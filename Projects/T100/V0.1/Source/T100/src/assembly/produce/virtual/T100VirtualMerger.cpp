#include "T100VirtualMerger.h"

#include <assert.h>
#include "T100PartDrawer.h"
#include "T100LabelDrawer.h"
#include "T100VariableDrawer.h"
#include "T100ProcedureDrawer.h"

namespace T100Assembly{

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
    T100BOOL        result          = T100TRUE;

    m_info = &target;

    m_info->m_code = source.m_code;
    m_info->m_data = source.m_data;

    m_info->m_codes.push_back(source.m_code);

    if(T100FALSE == source.m_data_default){
        m_info->m_data = T100NEW T100SegmentData();
    }else{
        m_info->m_datas.push_back(source.m_data);
    }

    assert(source.m_code != T100NULL);
    assert(m_info->m_code != T100NULL);
    assert(m_info->m_data != T100NULL);

    T100PART_INFO_VECTOR&       parts       = source.getPartDrawer().getPartInfos();

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
    T100BOOL        result          = T100FALSE;

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
    T100BOOL        result          = T100TRUE;

    for(T100SegmentCode* item : codes){
        if(!item){
            return T100FALSE;
        }

        if(item->isShare){
            result = mergeCode(item, m_info->m_share_code, m_info->m_share_codes, m_share_codes);
            if(!result){
                return T100FALSE;
            }
        }else{
            result = mergeCode(item, m_info->m_code, m_info->m_codes, m_codes);
            if(!result){
                return T100FALSE;
            }
        }
    }

    return result;
}

T100BOOL T100VirtualMerger::merge(T100SEGMENT_DATA_VECTOR& datas)
{
    T100BOOL        result          = T100TRUE;

    for(T100SegmentData* item : datas){
        if(!item){
            return T100FALSE;
        }

        if(item->isShare){
            result = mergeData(item, m_info->m_share_data, m_info->m_share_datas, m_share_datas);
            if(!result){
                return T100FALSE;
            }
        }else{
            result = mergeData(item, m_info->m_data, m_info->m_datas, m_datas);
            if(!result){
                return T100FALSE;
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
        size = source->m_length >= (source->getMem().size() - 1) ? source->m_length : (source->getMem().size() - 1);
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

        ld->OFFSET = offset;
    }

    for(auto it : source->m_procedure_hash){
        T100WORD        offset;

        offset = length + it.second;

        target->setProcedure(it.first, offset);

        T100PROCEDURE_DEFINE* pd = T100ProduceInfo::getProcedureDrawer().getProcedureDefine(it.first);
        if(!pd){
            return T100FALSE;
        }

        pd->OFFSET = offset;
    }

    for(auto item : source->m_variable_call){
        item->OFFSET = length + item->OFFSET;
        target->m_variable_call.push_back(item);
    }

    for(auto item : source->m_label_call){
        item->OFFSET = length + item->OFFSET;
        target->m_label_call.push_back(item);
    }

    for(auto item : source->m_procedure_call){
        item->OFFSET = length + item->OFFSET;
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
        T100WORD        offset;

        T100LABEL_DEFINE* ld = T100ProduceInfo::getLabelDrawer().getLabelDefine(item->NAME);
        if(!ld){
            return T100FALSE;
        }

        offset = ld->OFFSET;
        target->getMem()[offset] = ld->OFFSET;
    }

    for(auto it : source->m_variable_hash){
        T100WORD        offset;

        offset = length + it.second;

        target->setVariable(it.first, offset);

        T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(it.first);
        if(!vd){
            return T100FALSE;
        }

        vd->OFFSET = offset;
    }

    return T100TRUE;
}

T100Segment* T100VirtualMerger::findCode(T100SEGMENT_KEY* key)
{
    T100Segment*        result          = T100NULL;
    T100SEGMENT_HASH::iterator      it;

    it = m_codes.find(*key);

    if(m_codes.end() == it){
        return result;
    }
    return it->second;
}

T100Segment* T100VirtualMerger::findData(T100SEGMENT_KEY* key)
{
    T100Segment*        result          = T100NULL;
    T100SEGMENT_HASH::iterator      it;

    it = m_datas.find(*key);

    if(m_datas.end() == it){
        return result;
    }
    return it->second;
}

T100Segment* T100VirtualMerger::findShareCode(T100SEGMENT_KEY* key)
{
    T100Segment*        result          = T100NULL;
    T100SEGMENT_HASH::iterator      it;

    it = m_share_codes.find(*key);

    if(m_share_codes.end() == it){
        return result;
    }
    return it->second;
}

T100Segment* T100VirtualMerger::findShareData(T100SEGMENT_KEY* key)
{
    T100Segment*        result          = T100NULL;
    T100SEGMENT_HASH::iterator      it;

    it = m_share_datas.find(*key);

    if(m_share_datas.end() == it){
        return result;
    }
    return it->second;
}

T100Segment* T100VirtualMerger::find(T100SEGMENT_KEY* key, T100SEGMENT_HASH& segs)
{
    T100Segment*        result          = T100NULL;
    T100SEGMENT_HASH::iterator      it;

    it = segs.find(*key);

    if(segs.end() == it){
        return result;
    }
    return it->second;
}

T100BOOL T100VirtualMerger::mergeCode(T100SegmentCode* source, T100SegmentCode*& target, T100SEGMENT_CODE_VECTOR& codes_vector, T100SEGMENT_HASH& codes_hash)
{
    T100BOOL        result          = T100FALSE;

    if(!source){
        return T100FALSE;
    }

    if(source == target){
        return T100TRUE;
    }

    if(source->getName().empty()){
        if(!target){
            target = source;
            codes_vector.push_back(source);
            return T100TRUE;
        }
        if(decide(target, source)){
            result = mergeCode(target, source);
            if(!result){
                return T100FALSE;
            }
        }else{
            codes_vector.push_back(source);
        }
    }else{
        T100SEGMENT_KEY* key = T100NEW T100SEGMENT_KEY();

        key->NAME       = source->getName();
        key->LOCATION   = source->getLocation();

        T100Segment* seg = find(key, codes_hash);

        if(seg){
            if(decide((T100SegmentCode*)seg, source)){
                result = mergeCode((T100SegmentCode*)seg, source);
                if(!result){
                    return T100FALSE;
                }
            }else{
                codes_hash[*key] = source;
                codes_vector.push_back(source);
            }
        }
    }
    return result;
}

T100BOOL T100VirtualMerger::mergeData(T100SegmentData* source, T100SegmentData*& target, T100SEGMENT_DATA_VECTOR& datas_vector, T100SEGMENT_HASH& datas_hash)
{
    T100BOOL        result          = T100FALSE;

    if(!source){
        return T100FALSE;
    }

    if(source == target){
        return T100TRUE;
    }

    if(source->getName().empty()){
        if(!target){
            target = source;
            datas_vector.push_back(source);
            return T100TRUE;
        }
        if(decide(target, source)){
            result = mergeData(target, source);
            if(!result){
                return T100FALSE;
            }
        }else{
            datas_vector.push_back(source);
        }
    }else{
        T100SEGMENT_KEY* key = T100NEW T100SEGMENT_KEY();

        key->NAME       = source->getName();
        key->LOCATION   = source->getLocation();

        T100Segment* seg = find(key, datas_hash);

        if(seg){
            if(decide((T100SegmentData*)seg, source)){
                result = mergeData((T100SegmentData*)seg, source);
                if(!result){
                    return T100FALSE;
                }
            }else{
                datas_hash[*key] = source;
                datas_vector.push_back(source);
            }
        }else{
            datas_hash[*key] = source;
            datas_vector.push_back(source);
        }
    }

    return result;
}

}
