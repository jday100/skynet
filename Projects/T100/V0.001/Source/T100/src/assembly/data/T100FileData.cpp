#include "T100FileData.h"

#include "T100SegmentCode.h"
#include "T100SegmentData.h"

#include "T100SentenceCode.h"
#include "T100SentenceData.h"
#include "T100SentenceProcedure.h"


T100FileData::T100FileData(T100Code* code)
    :m_parent(code)
{
    //ctor
}

T100FileData::~T100FileData()
{
    //dtor
}

T100BOOL T100FileData::addSegment()
{
    switch(m_type)
    {
    //
    case T100SEGMENT_PROCEDURE:
        {
            T100WORD_BITS   order;

            order.BYTE0.BYTE  = T100ORDER_RETURN;
            m_code->setValue(order.WORD);
            m_code->next();

            m_codes.push_back(m_code);
            m_code = T100NULL;
        }
        break;
    case T100SEGMENT_CODE:
        {
            m_codes.push_back(m_code);

            if(m_code->isDefault){
                m_code_id = m_codes.size() - 1;

                T100Code::m_code = m_code;
            }else if(m_master && T100Code::m_code_default_flag == T100FALSE && m_code->isVirtual == T100FALSE){
                T100Code::m_code = m_code;
                T100Code::m_code_default_flag = T100TRUE;
            }

            m_code = T100NULL;
            break;
        }
    case T100SEGMENT_DATA:
        {
            m_datas.push_back(m_data);

            if(m_data->isDefault){
                m_data_id = m_datas.size() - 1;

                T100Code::m_data = m_data;
            }else if(m_master && T100Code::m_data_default_flag == T100FALSE && m_data->isVirtual == T100FALSE){
                T100Code::m_data = m_data;
                T100Code::m_data_default_flag = T100TRUE;
            }

            m_data = T100NULL;
            break;
        }
    case T100SEGMENT_SHARE_DATA:
        {
            m_share_datas.push_back(m_data);
            m_data = T100NULL;
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100FileData::createSegment(T100Sentence* sent)
{
    T100BOOL    result      = T100FALSE;

    switch(sent->type)
    {
    case T100SENTENCE_CODE:
        {
            m_type = T100SEGMENT_CODE;
            T100SentenceCode* code;

            code    = (T100SentenceCode*)sent;
            m_code  = T100NEW T100SegmentCode();

            m_code->isDefault   = code->isDefault;
            m_code->isVirtual   = code->isVirtual;
            m_code->isShare     = code->isShare;
            m_code->m_location  = code->location;
            m_code->m_length    = code->length;

            T100BOOL value  = m_code->isShare;

            if(m_code->isDefault){
                T100Code::m_code = m_code;
                T100Code::m_code_default_flag = T100TRUE;
            }

            if(m_code->isVirtual == T100FALSE){
                m_code_virtual = T100FALSE;
            }

            result = T100TRUE;
            break;
        }
    case T100SENTENCE_DATA:
        {
            m_type = T100SEGMENT_DATA;
            T100SentenceData* data;

            data    = (T100SentenceData*)sent;
            m_data  = T100NEW T100SegmentData();

            m_data->setName(data->name);
            m_data->isDefault   = data->isDefault;
            m_data->isVirtual   = data->isVirtual;
            m_data->isShare     = data->isShare;
            m_data->m_location  = data->location;
            m_data->m_length    = data->length;

            T100BOOL value  = m_data->isShare;

            if(m_data->isDefault){
                T100Code::m_data = m_data;
                T100Code::m_data_default_flag = T100TRUE;
            }

            if(m_data->isVirtual == T100FALSE){
                m_data_virtual = T100FALSE;
            }

            if(m_data->isShare){
                m_type  = T100SEGMENT_SHARE_DATA;
            }

            result = T100TRUE;
            break;
        }
    case T100SENTENCE_PROCEDURE:
        {
            m_type = T100SEGMENT_PROCEDURE;
            T100SentenceProcedure* proc;

            proc    = (T100SentenceProcedure*)sent;
            m_code  = T100NEW T100SegmentCode();

            m_code->isDefault   = T100FALSE;
            m_code->isVirtual   = T100FALSE;
            m_code->m_location  = 0;
            m_code->m_length    = 0;

            if(m_code->isDefault){
                T100Code::m_code = m_code;
                T100Code::m_code_default_flag = T100TRUE;
            }

            if(m_code->isVirtual == T100FALSE){
                m_code_virtual = T100FALSE;
            }

            m_code->setProcedure(proc->name, m_code->getOffset());

            /*
            T100PROCEDURE_DEFINE*   pd = new T100PROCEDURE_DEFINE;

            pd->name        = proc->name;
            pd->offset      = m_code->getOffset();

            T100Code::setProcedureDefine(proc->name, pd);
            */

            T100PROCEDURE_DEFINE* pd = T100Code::getProcedureDefine(proc->name);

            if(!pd){
                return T100FALSE;
            }

            pd->offset  = m_code->getOffset();

            result = T100TRUE;
            break;
        }
    };

    return result;
}

T100BOOL T100FileData::setValue(T100WORD value)
{
    switch(m_type)
    {
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            return m_code->setValue(value);
        }
    case T100SEGMENT_DATA:
        {
            break;
        }
    };

    return T100FALSE;
}

T100VOID T100FileData::next()
{
    switch(m_type)
    {
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            m_code->next();
            break;
        }
    case T100SEGMENT_DATA:
        {
            break;
        }
    }
}

T100WORD T100FileData::getOffset()
{
    T100WORD    result      = 0;

    switch(m_type)
    {
    //test
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            result = m_code->getOffset();
            break;
        }
    case T100SEGMENT_DATA:
        {
            result = m_data->getOffset();
            break;
        }
    case T100SEGMENT_SHARE_DATA:
        {
            result = m_data->getOffset();
        }
        break;
    };

    return result;
}

T100BOOL T100FileData::setVariable(T100String name, T100WORD offset)
{

    switch(m_type){
    case T100SEGMENT_CODE:
        {
            m_code->setVariable(name, offset);
        }
        break;
    case T100SEGMENT_SHARE_DATA:
    case T100SEGMENT_DATA:
        {
            m_data->setVariable(name, offset);
        }
        break;
    };

    return T100FALSE;
}

T100BOOL T100FileData::getVariable(T100String name, T100WORD& offset)
{
    T100BOOL    result      = T100FALSE;

    switch(m_type){
    case T100SEGMENT_CODE:
        {
            result = m_code->getVariable(name, offset);
        }
        break;
    case T100SEGMENT_SHARE_DATA:
    case T100SEGMENT_DATA:
        {
            result = m_data->getVariable(name, offset);
        }
        break;
    };

    return result;
}

T100BOOL T100FileData::addVariableCall(T100VARIABLE_CALL* c)
{
    T100BOOL    result      = T100FALSE;

    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            result = m_code->addVariableCall(c);
        }
        break;
    case T100SEGMENT_DATA:
        {
            //
        }
        break;
    };

    return T100FALSE;
}

T100BOOL T100FileData::setLabel(T100String name, T100WORD offset)
{
    T100BOOL    result      = T100FALSE;

    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            result = m_code->setLabel(name, offset);
        }
        break;
    case T100SEGMENT_DATA:
        {
            //
        }
        break;
    };

    return result;
}

T100BOOL T100FileData::getLabel(T100String name, T100WORD& offset)
{
    T100BOOL    result      = T100FALSE;

    if(m_type == T100SEGMENT_CODE){
        result = m_code->getLabel(name, offset);
    }

    return result;
}

T100BOOL T100FileData::addLabelCall(T100LABEL_CALL* c)
{
    T100BOOL    result      = T100FALSE;

    if(T100SEGMENT_CODE == m_type){
        T100Log::info("CODE add label call " + c->name.to_std_string());
        result = m_code->addLabelCall(c);
    }else if(T100SEGMENT_DATA == m_type){
        T100Log::info("DATA add label call " + c->name.to_std_string());
        result = m_data->addLabelCall(c);
    }else if(T100SEGMENT_SHARE_DATA == m_type){
        T100Log::info("SHARE DATA add label call " + c->name.to_std_string());
        result = m_data->addLabelCall(c);
    }else if(T100SEGMENT_PROCEDURE == m_type){
        result = m_code->addLabelCall(c);
    }

    return result;
}

T100BOOL T100FileData::setProcedure(T100String name, T100WORD offset)
{
    T100BOOL    result      = T100FALSE;

    if(m_type == T100SEGMENT_PROCEDURE){
        result = m_code->setProcedure(name, offset);
    }
    return result;
}

T100BOOL T100FileData::getProcedure(T100String name, T100WORD& offset)
{
    T100BOOL    result      = T100FALSE;

    if(m_type == T100SENTENCE_PROCEDURE){
        result = m_code->getProcedure(name, offset);
    }
    return result;
}

T100BOOL T100FileData::addProcedureCall(T100PROCEDURE_CALL* c)
{
    T100BOOL    result      = T100FALSE;

    result = m_code->addProcedureCall(c);

    return result;
}

T100SegmentCode* T100FileData::getCode()
{
    return m_code;
}

T100SegmentData* T100FileData::getData()
{
    return m_data;
}

T100BOOL T100FileData::setTiny(T100BOOL istiny)
{
    m_istiny            = istiny;
    m_parent->m_istiny  = istiny;

    m_segment_type      = T100TYPE_TINY;
    m_parent->m_type    = T100TYPE_TINY;

    return T100TRUE;
}

T100BOOL T100FileData::setMode(T100MODE mode)
{
    m_mode = mode;
    m_parent->m_mode = mode;

    return T100TRUE;
}

T100BOOL T100FileData::setType(T100TYPE type)
{
    m_segment_type = type;
    m_parent->m_type = type;

    return T100TRUE;
}

