#include "T100CodeNew.h"


#include <assert.h>
#include "T100FileData.h"
#include "T100Sentence.h"
#include "T100SegmentCode.h"
#include "T100SegmentData.h"


T100VARIABLE_HASH       T100Code::m_variables;
T100LABEL_HASH          T100Code::m_labels;
T100PROCEDURE_HASH      T100Code::m_procedures;


T100SegmentCode*        T100Code::m_code = T100NULL;
T100SegmentData*        T100Code::m_data = T100NULL;
T100BOOL                T100Code::m_code_default = T100FALSE;
T100BOOL                T100Code::m_data_default = T100FALSE;
T100BOOL                T100Code::m_code_default_flag = T100FALSE;
T100BOOL                T100Code::m_data_default_flag = T100FALSE;



T100Code::T100Code()
{
    //ctor
}

T100Code::~T100Code()
{
    //dtor
    clear();
}

T100VARIABLE_DEFINE* T100Code::getVariableDefine(T100String name)
{
    T100VARIABLE_DEFINE*    result = T100NULL;
    T100VARIABLE_HASH::iterator it;

    it = m_variables.find(name);

    if(it == m_variables.end()){

    }else{
        result = it->second;
    }

    return result;
}

T100BOOL T100Code::setVariableDefine(T100String name, T100VARIABLE_DEFINE* vd)
{
    m_variables[name] = vd;

    return T100TRUE;
}

T100LABEL_DEFINE* T100Code::getLabelDefine(T100String name)
{

    T100LABEL_DEFINE*   result = T100NULL;
    T100LABEL_HASH::iterator it;

    it = m_labels.find(name);

    if(it == m_labels.end()){

    }else{
        result = it->second;
    }

    return result;
}

T100BOOL T100Code::setLabelDefine(T100String name, T100LABEL_DEFINE* ld)
{
    m_labels[name] = ld;

    return T100TRUE;
}

T100PROCEDURE_DEFINE* T100Code::getProcedureDefine(T100String name)
{
    T100PROCEDURE_DEFINE* result = T100NULL;
    T100PROCEDURE_HASH::iterator it;

    it = m_procedures.find(name);

    if(it == m_procedures.end()){

    }else{
        result = it->second;
    }

    return result;
}

T100BOOL T100Code::setProcedureDefine(T100String name, T100PROCEDURE_DEFINE* pd)
{
    m_procedures[name] = pd;

    return T100TRUE;
}

T100BOOL T100Code::istiny()
{
    return m_istiny;
}

T100BOOL T100Code::build(T100FileToken* file)
{
    T100BOOL result;

    m_file = T100NEW T100FileData(this);
    m_file->file        = file->file;
    m_file->m_master    = file->master;

    for(auto item : file->segments){
        if(item){
            result = build(item);

            if(result && file->master){
                item->master = T100TRUE;
                result = setDefaultSegment(item);
            }

            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    m_files.push_back(m_file);
    m_file = T100NULL;

    return result;
}

T100BOOL T100Code::build(T100SegmentToken* segment)
{
    T100BOOL result;

    for(auto item : segment->sentences){
        if(item){
            result = build(item);

            if(result){

            }else{
                break;
            }
        }else{

        }
    }

    return result;
}

T100BOOL T100Code::build(T100SentenceToken* token)
{
    T100BOOL result;

    if(token->data){
        result = token->data->run(m_file);
    }

    if(result){

    }else{

    }

    return result;
}

T100BOOL T100Code::setDefaultSegment(T100SegmentToken* token)
{
    switch(token->type)
    {
    case T100SEGMENT_CODE:
        {
            if(m_code_default){

            }else{
                if(!m_code_default_flag){
                    m_code = m_file->getCode();

                    assert(m_code != T100NULL);

                    //test
                    m_code->getMem();
                    m_code_default_flag = T100TRUE;
                }
            }
        }
        break;
    case T100SEGMENT_DATA:
        {
            if(m_data_default){

            }else{
                if(!m_data_default_flag && m_file->getData()){
                    m_data = m_file->getData();

                    //test
                    m_data->getMem();
                    m_data_default_flag = T100TRUE;
                }
            }
        }
        break;
    };

    return T100TRUE;
}

T100BOOL T100Code::clear()
{
    T100BOOL    result      = T100TRUE;

    m_code              = T100NULL;
    m_data              = T100NULL;

    m_code_default      = T100FALSE;
    m_data_default      = T100FALSE;
    m_code_default_flag = T100FALSE;
    m_data_default_flag = T100FALSE;

    for(auto item : m_variables){
        T100DELETE(item.second);
    }

    m_variables.clear();

    for(auto item : m_labels){
        T100DELETE(item.second);
    }

    m_labels.clear();

    for(auto item : m_procedures){
        T100DELETE(item.second);
    }

    m_procedures.clear();

    return result;
}
