#include "T100RealMerger.h"
#include <assert.h>
#include "T100AssemblyCommon.h"
#include "T100ProduceInfo.h"
#include "T100PartDrawer.h"
#include "T100VariableDrawer.h"
#include "T100LabelDrawer.h"
#include "T100ProcedureDrawer.h"


T100RealMerger::T100RealMerger()
{
    //ctor
}

T100RealMerger::~T100RealMerger()
{
    //dtor
}

T100BOOL T100RealMerger::run(T100ProduceInfo& source, T100RealInfo& target)
{
    T100BOOL            result          = T100TRUE;

    T100PART_INFO_VECTOR&       parts   = source.getPartDrawer().getPartInfos();

    //
    result = merge_code(T100ProduceInfo::m_code, &target.getCode());
    if(!result){
        return T100FALSE;
    }

    result = merge_data(T100ProduceInfo::m_data, &target.getData());
    if(!result){
        return T100FALSE;
    }

    for(T100PartInfo* item : parts){
        if(item){
            result = merge(item, target);
            if(!result){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    result = relocate(target);

    return result;
}

T100BOOL T100RealMerger::merge(T100PartInfo* part, T100RealInfo& info)
{
    T100BOOL    result      = T100FALSE;

    for(T100SegmentCode* item : part->getBuildInfo().getCodeSegments()){
        if(!item){
            return T100FALSE;
        }

        if(item == T100ProduceInfo::m_code){
            continue;
        }

        if(decide_code(item, &info.getCode())){
            result = merge_code(item, &info.getCode());
            if(!result){
                return T100FALSE;
            }
        }
    }

    for(T100SegmentData* item : part->getBuildInfo().getDataSegments()){
        if(!item){
            return T100FALSE;
        }

        if(item == T100ProduceInfo::m_data){
            continue;
        }

        if(decide_data(item, &info.getData())){
            result = merge_data(item, &info.getData());
            if(!result){
                return T100FALSE;
            }
        }
    }

    return T100TRUE;
}

T100BOOL T100RealMerger::decide_code(T100SegmentCode* source, T100SegmentCode* target)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->isShare)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100RealMerger::decide_data(T100SegmentData* source, T100SegmentData* target)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->isShare)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100RealMerger::merge_code(T100SegmentCode* source, T100SegmentCode* target)
{
    assert(target != T100NULL);
    assert(source != T100NULL);

    if(source->isVirtual){
        return T100TRUE;
    }

    if(source->isShare){
        return T100TRUE;
    }

    if(source->m_location != 0){
        return T100FALSE;
    }

    T100WORD        length;
    T100WORD        size;

    length = target->getMem().size();

    if(source->m_length == 0){
        source->getMem().resize(source->getMem().size() - 1);
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());
    }else{
        size = source->m_length >= (source->getMem().size()-1) ? source->m_length : (source->getMem().size()-1);
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());

        target->getMem().resize(length + size);
    }

    /*
    for(auto it : source->m_variable_call){
        T100WORD        offset;

        offset = length + it.second;

        target->setVariable(it.first, offset);

        T100VARIABLE_DEFINE *vd = T100Code::getVariableDefine(it.first);
        if(!vd){
            return T100FALSE;
        }

        vd->offset = offset;
    }
    */

    for(auto it : source->m_label_hash){
        T100WORD        offset;

        offset = length + it.second;

        target->setLabel(it.first, offset);

        T100LABEL_DEFINE* ld = T100ProduceInfo::getLabelDrawer().getLabelDefine(it.first);
        if(!ld){
            return T100FALSE;
        }

        ld->offset = offset;
    }

    for(auto it : source->m_procedure_hash){
        T100WORD    offset;

        offset = length + it.second;

        target->setProcedure(it.first, offset);

        T100PROCEDURE_DEFINE* pd = T100ProduceInfo::getProcedureDrawer().getProcedureDefine(it.first);
        if(!pd){
            return T100FALSE;
        }

        pd->offset = offset;
    }

    for(auto item : source->m_variable_call){
        item->offset = length + item->offset;
        //
        T100WORD test;

        test = item->offset;

        target->m_variable_call.push_back(item);
    }

    for(auto item : source->m_label_call){
        item->offset = length + item->offset;
        target->m_label_call.push_back(item);

        T100STDSTRING   msg;

        msg = "LABEL: " + item->name.to_std_string();

        //T100Log::info(msg);
    }

    for(auto item : source->m_procedure_call){
        item->offset = length + item->offset;
        target->m_procedure_call.push_back(item);
    }

    return T100TRUE;
}

T100BOOL T100RealMerger::merge_data(T100SegmentData* source, T100SegmentData* target)
{
    assert(target != T100NULL);
    assert(source != T100NULL);

    if(source->isVirtual){
        return T100TRUE;
    }

    if(source->isShare){
        return T100TRUE;
    }

    if(source->m_location != 0){
        return T100FALSE;
    }

    T100WORD        length;
    T100WORD        size;

    length = target->getMem().size();

    if(source->getLength() == 0){
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());
    }else{
        size = source->getLength() >= source->getMem().size() ? source->getLength() : source->getMem().size();
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());

        target->getMem().resize(length + size);
    }

    for(auto it : source->m_variable_hash){
        T100WORD        offset;

        offset = length + it.second;

        target->setVariable(it.first, offset);

        T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(it.first);
        if(!vd){
            return T100FALSE;
        }

        vd->offset = offset;
    }

    for(auto item : source->m_label_call){
        item->offset = length + item->offset;
        target->m_label_call.push_back(item);

        T100STDSTRING   msg;

        msg = "LABEL: " + item->name.to_std_string();

        //T100Log::info(msg);
    }

    return T100TRUE;
}

T100BOOL T100RealMerger::relocate(T100RealInfo& info)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100WORD            os;
    T100WORD            size;

    T100WORD            offset;
    T100WORD            temp;

    os      = 2;
    size    = info.getData().getMem().size();

    for(T100LABEL_CALL* item : info.getData().m_label_call){
        if(item){
            offset = item->offset;

            T100LABEL_DEFINE*   ld = T100ProduceInfo::getLabelDrawer().getLabelDefine(item->name);

            if(ld){
                if(ld->isvirtual || ld->isshare)continue;

                temp  = ld->offset;

                info.getData().getMem()[offset] = temp + os + size;
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    size    = info.getData().getMem().size();
    os      = size + 2;

    for(T100VARIABLE_CALL* item : info.getCode().m_variable_call){
        if(item){
            offset = item->offset;

            T100VARIABLE_DEFINE*    vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(item->name);

            if(vd){
                T100WORD    test;

                test = vd->offset;

                if(vd->isvirtual || vd->isshare){
                    info.getCode().getMem()[offset] = vd->offset;
                    continue;
                }else{
                    info.getCode().getMem()[offset] = vd->offset + 2;
                }
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    for(T100LABEL_CALL* item : info.getCode().m_label_call){
        if(item){
            offset = item->offset;

            T100LABEL_DEFINE*   ld = T100ProduceInfo::getLabelDrawer().getLabelDefine(item->name);

            if(ld){
                if(ld->isvirtual || ld->isshare)continue;

                temp = ld->offset;

                info.getCode().getMem()[offset] = temp + os;
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    for(T100PROCEDURE_CALL* item : info.getCode().m_procedure_call){
        if(item){
            offset = item->offset;

            T100PROCEDURE_DEFINE*   pd = T100ProduceInfo::getProcedureDrawer().getProcedureDefine(item->name);

            if(pd){
                temp = pd->offset;

                info.getCode().getMem()[offset] = temp + os;
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}
