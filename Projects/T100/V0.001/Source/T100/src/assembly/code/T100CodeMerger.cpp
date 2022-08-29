#include "T100CodeMerger.h"

#include <assert.h>


T100CodeMerger::T100CodeMerger()
{
    //ctor
}

T100CodeMerger::~T100CodeMerger()
{
    //dtor
}

T100BOOL T100CodeMerger::mergeCode(T100SegmentCode* target, T100SegmentCode* source)
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
    }

    for(auto item : source->m_procedure_call){
        item->offset = length + item->offset;
        target->m_procedure_call.push_back(item);
    }

    return T100TRUE;
}

T100BOOL T100CodeMerger::mergeData(T100SegmentData* target, T100SegmentData* source)
{
    assert(target != T100NULL);
    assert(source != T100NULL);

    if(source->isVirtual){
        return T100TRUE;
    }

    /*
    if(source->m_location != 0){
        return T100FALSE;
    }
    */

    T100WORD        length;
    T100WORD        size;

    length = source->getMem().size();
    length = target->getMem().size();

    if(source->m_length == 0){
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());
    }else{
        size = source->m_length >= source->getMem().size() ? source->m_length : source->getMem().size();
        target->getMem().insert(target->getMem().end(), source->getMem().begin(), source->getMem().end());

        target->getMem().resize(length + size);
    }

    size = target->getMem().size();

    for(auto item : source->m_label_call){
        T100WORD    offset;

        T100LABEL_DEFINE *ld = T100Code::getLabelDefine(item->name);
        if(!ld){
            return T100FALSE;
        }

        offset = ld->offset;
        target->getMem()[offset] = ld->offset;
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

    return T100TRUE;
}
