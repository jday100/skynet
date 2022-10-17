#include "T100VirtualMerger.h"

#include <assert.h>
#include "T100PartDrawer.h"
#include "T100LabelDrawer.h"
#include "T100VariableDrawer.h"
#include "T100ProcedureDrawer.h"


T100VirtualMerger::T100VirtualMerger()
{
    //ctor
}

T100VirtualMerger::~T100VirtualMerger()
{
    //dtor
}

T100BOOL T100VirtualMerger::run(T100ProduceInfo& source, T100VirtualInfo& target)
{
    T100BOOL        result      = T100TRUE;

    m_info = &target;

    m_info->m_code = source.m_code;
    m_info->m_data = source.m_data;

    if(T100FALSE == source.m_data_default){
        m_info->m_data = T100NEW T100SegmentData();
    }

    assert(source.m_code != T100NULL);
    assert(m_info->m_code != T100NULL);
    assert(m_info->m_data != T100NULL);

    T100PART_INFO_VECTOR&       parts   = source.getPartDrawer().getPartInfos();

    for(T100PartInfo* item : parts){
        if(item){
            result = merge(item);
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VirtualMerger::merge(T100PartInfo* source)
{
    T100BOOL        result      = T100FALSE;

    if(!source){
        return T100FALSE;
    }

    result = merge(source->getBuildInfo().getCodeSegments());
    if(!result){
        return T100FALSE;
    }

    result = merge(source->getBuildInfo().getDataSegments());

    return result;
}

T100BOOL T100VirtualMerger::merge(T100SEGMENT_CODE_VECTOR& codes)
{
    T100BOOL            result          = T100TRUE;

    for(T100SegmentCode* item : codes){
        if(!item){
            return T100FALSE;
        }

        T100SEGMENT_KEY* key = T100NEW T100SEGMENT_KEY();

        key->name       = item->getName();
        key->location   = item->getLocation();

        if(key->name.empty()){
            if(decide(m_info->m_code, item)){
                result = mergeCode(m_info->m_code, item);
                if(!result){
                    return T100FALSE;
                }
            }else{
                m_info->m_codes.push_back(item);
            }
        }else{
            T100Segment* seg = findCode(key);

            if(seg){
                if(decide((T100SegmentCode*)seg, item)){
                    result = mergeCode((T100SegmentCode*)seg, item);
                    if(!result){
                        return T100FALSE;
                    }
                }else{
                    m_codes[*key] = item;
                    m_info->m_codes.push_back(item);
                }
            }else{
                m_codes[*key] = item;
                m_info->m_codes.push_back(item);
            }
        }
    }

    return result;
}

T100BOOL T100VirtualMerger::merge(T100SEGMENT_DATA_VECTOR& datas)
{
    T100BOOL            result          = T100TRUE;

    for(T100SegmentData* item : datas){
        if(!item){
            return T100FALSE;
        }

        T100SEGMENT_KEY* key = T100NEW T100SEGMENT_KEY();

        key->name       = item->getName();
        key->location   = item->getLocation();

        if(key->name.empty()){
            if(decide(m_info->m_data, item)){
                result = mergeData(m_info->m_data, item);
                if(!result){
                    return T100FALSE;
                }
            }else{
                m_info->m_datas.push_back(item);
            }
        }else{
            T100Segment* seg = findData(key);

            if(seg){
                if(decide((T100SegmentData*)seg, item)){
                    result = mergeData((T100SegmentData*)seg, item);
                    if(!result){
                        return T100FALSE;
                    }
                }else{
                    m_datas[*key] = item;
                    m_info->m_datas.push_back(item);
                }
            }else{
                m_datas[*key] = item;
                m_info->m_datas.push_back(item);
            }
        }
    }

    return result;
}

T100BOOL T100VirtualMerger::decide(T100SegmentCode* target, T100SegmentCode* source)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100VirtualMerger::decide(T100SegmentData* target, T100SegmentData* source)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100VirtualMerger::mergeCode(T100SegmentCode* target, T100SegmentCode* source)
{
    assert(target != T100NULL);
    assert(source != T100NULL);

    if(source->isVirtual){
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
        target->m_variable_call.push_back(item);
    }

    for(auto item : source->m_label_call){
        item->offset = length + item->offset;
        target->m_label_call.push_back(item);
    }

    for(auto item : source->m_procedure_call){
        item->offset = length + item->offset;
        target->m_procedure_call.push_back(item);
    }

    return T100TRUE;
}

T100BOOL T100VirtualMerger::mergeData(T100SegmentData* target, T100SegmentData* source)
{
    assert(target != T100NULL);
    assert(source != T100NULL);

    if(source->isVirtual){
        return T100TRUE;
    }

    if(source->m_location != 0){
        return T100FALSE;
    }

    T100WORD        length;
    T100WORD        size;

    length = target->getMem().size();

    if(source->m_length == 0){
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());
    }else{
        size = source->m_length >= source->getMem().size() ? source->m_length : source->getMem().size();
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());

        target->getMem().resize(length + size);
    }

    for(auto item : source->m_label_call){
        T100WORD    offset;

        T100LABEL_DEFINE *ld = T100ProduceInfo::getLabelDrawer().getLabelDefine(item->name);
        if(!ld){
            return T100FALSE;
        }

        offset = ld->offset;
        target->getMem()[offset] = ld->offset;
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

    return T100TRUE;
}

T100Segment* T100VirtualMerger::findCode(T100SEGMENT_KEY* key)
{
    T100Segment*    result      = T100NULL;
    T100SEGMENT_HASH::iterator it;

    it = m_codes.find(*key);

    if(m_codes.end() == it){
        return result;
    }

    return it->second;
}

T100Segment* T100VirtualMerger::findData(T100SEGMENT_KEY* key)
{
    T100Segment*    result      = T100NULL;
    T100SEGMENT_HASH::iterator it;

    it = m_datas.find(*key);

    if(m_datas.end() == it){
        return result;
    }

    return it->second;
}

T100Segment* T100VirtualMerger::findShareCode(T100SEGMENT_KEY* key)
{
    T100Segment*    result      = T100NULL;
    T100SEGMENT_HASH::iterator it;

    it = m_share_codes.find(*key);

    if(m_share_codes.end() == it){
        return result;
    }

    return it->second;
}

T100Segment* T100VirtualMerger::findShareData(T100SEGMENT_KEY* key)
{
    T100Segment*    result      = T100NULL;
    T100SEGMENT_HASH::iterator it;

    it = m_share_datas.find(*key);

    if(m_share_datas.end() == it){
        return result;
    }

    return it->second;
}
