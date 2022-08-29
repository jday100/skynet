#include "T100ExecutableRealTinyMerger.h"

#include <assert.h>
#include "T100FileData.h"


T100ExecutableRealTinyMerger::T100ExecutableRealTinyMerger(T100Code* code)
{
    //ctor
}

T100ExecutableRealTinyMerger::~T100ExecutableRealTinyMerger()
{
    //dtor
}


T100FileData* T100ExecutableRealTinyMerger::run(T100CODEDATA_VECTOR& files)
{
    T100BOOL        result      = T100FALSE;
    T100FileData*   file        = T100NULL;

    file = T100NEW T100FileData(m_code);

    file->m_code    = T100Code::m_code;
    file->m_data    = T100Code::m_data;

    if(T100FALSE == T100Code::m_data_default_flag){
        file->m_data = T100NEW T100SegmentData();
    }

    assert(T100Code::m_code != T100NULL);
    assert(file->m_code != T100NULL);
    assert(file->m_data != T100NULL);

    for(auto item : files){
        if(!item){
            T100DELETE(file);
            T100AssemblyError::error(T100BUILD_MARGER_FAILURE);
            return T100NULL;
        }

        result = merge(file, item);

        if(!result){
            T100DELETE(file);
            T100AssemblyError::error(T100AssemblyHint::file_hint(item->file.to_std_string(), T100BUILD_MARGER_FAILURE));
            return T100NULL;
        }
    }

    assert(file->m_code != T100NULL);
    assert(file->m_data != T100NULL);

    T100Log::info(T100BUILD_MARGER_SUCCESS);

    return file;
}

T100BOOL T100ExecutableRealTinyMerger::decide(T100SegmentCode* target, T100SegmentCode* source)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->isShare)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100ExecutableRealTinyMerger::decide(T100SegmentData* target, T100SegmentData* source)
{
    if((!target) || (!source))return T100FALSE;

    if(target == source)return T100FALSE;

    if(source->isVirtual)return T100FALSE;

    if(source->isShare)return T100FALSE;

    if(source->m_location != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100ExecutableRealTinyMerger::merge(T100FileData* target, T100FileData* source)
{
    T100BOOL    result      = T100FALSE;

    for(auto item : source->m_codes){
        if(!item){
            return T100FALSE;
        }

        if(decide(target->getCode(), (T100SegmentCode*)item)){
            result = mergeCode(target->getCode(), (T100SegmentCode*)item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    for(auto item : source->m_datas){
        if(!item){
            return T100FALSE;
        }

        if(decide(target->getData(), (T100SegmentData*)item)){
            result = mergeData(target->getData(), (T100SegmentData*)item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    return T100TRUE;
}

T100BOOL T100ExecutableRealTinyMerger::mergeCode(T100SegmentCode* target, T100SegmentCode* source)
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

    for(auto it : source->m_variables){
        T100WORD        offset;

        offset = length + it.second;

        target->setVariable(it.first, offset);

        T100VARIABLE_DEFINE *vd = T100Code::getVariableDefine(it.first);
        if(!vd){
            return T100FALSE;
        }

        vd->offset = offset;
    }

    for(auto it : source->m_labels){
        T100WORD        offset;

        offset = length + it.second;

        target->setLabel(it.first, offset);

        T100LABEL_DEFINE* ld = T100Code::getLabelDefine(it.first);
        if(!ld){
            return T100FALSE;
        }

        ld->offset = offset;
    }

    for(auto it : source->m_procedures){
        T100WORD    offset;

        offset = length + it.second;

        target->setProcedure(it.first, offset);

        T100PROCEDURE_DEFINE* pd = T100Code::getProcedureDefine(it.first);
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

        T100STDSTRING   msg;

        msg = "LABEL: " + item->name.to_std_string();

        T100Log::info(msg);
    }

    for(auto item : source->m_procedure_call){
        item->offset = length + item->offset;
        target->m_procedure_call.push_back(item);
    }

    return T100TRUE;
}

T100BOOL T100ExecutableRealTinyMerger::mergeData(T100SegmentData* target, T100SegmentData* source)
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
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());
    }else{
        size = source->m_length >= source->getMem().size() ? source->m_length : source->getMem().size();
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());

        target->getMem().resize(length + size);
    }

    for(auto it : source->m_variables){
        T100WORD        offset;

        offset = length + it.second;

        target->setVariable(it.first, offset);

        T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(it.first);
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

        T100Log::info(msg);
    }

    return T100TRUE;
}
