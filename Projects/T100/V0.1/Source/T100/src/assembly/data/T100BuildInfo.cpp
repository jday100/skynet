#include "T100BuildInfo.h"

#include "T100BitTypes.h"
#include "T100Sentence.h"
#include "T100ProduceInfo.h"
#include "T100SentenceCode.h"
#include "T100SentenceData.h"
#include "T100SentenceProcedure.h"

namespace T100Assembly{

T100BuildInfo::T100BuildInfo()
{
    //ctor
}

T100BuildInfo::~T100BuildInfo()
{
    //dtor
}

T100BOOL T100BuildInfo::setValue(T100WORD value)
{
    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            return m_code->setValue(value);
        }
        break;
    }
    return T100FALSE;
}

T100WORD T100BuildInfo::getOffset()
{
    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            return  m_code->getOffset();
        }
        break;
    case T100SEGMENT_DATA:
        {
            return m_data->getOffset();
        }
        break;
    }
    return T100FALSE;
}

T100VOID T100BuildInfo::next()
{
    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            m_code->next();
        }
        break;
    case T100SEGMENT_DATA:
        {
            m_data->next();
        }
        break;
    }
    return;
}

T100BOOL T100BuildInfo::openSegment(T100Sentence* sent)
{
    T100BOOL        result          = T100TRUE;

    m_type = sent->type;

    switch(m_type){
    case T100SENTENCE_CODE:
        {
            m_type  = T100SEGMENT_CODE;
            result  = createCode(sent);
        }
        break;
    case T100SENTENCE_DATA:
        {
            m_type  = T100SEGMENT_DATA;
            result  = createData(sent);
        }
        break;
    case T100SENTENCE_PROCEDURE:
        {
            m_type  = T100SEGMENT_PROCEDURE;
            result  = createProcedure(sent);
        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::closeSegment()
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
        {
            if(T100ProduceInfo::m_code_default){
                if(m_code->isDefault){
                    result = T100ProduceInfo::setDefaultCode(m_code);
                }
            }else{
                if(m_code_master && m_code->isMaster){
                    result = T100ProduceInfo::setDefaultCode(m_code);
                    if(result){
                        m_code_master = T100FALSE;
                    }
                }
            }

            m_code_segments.push_back(m_code);
            m_code = T100NULL;
        }
        break;
    case T100SEGMENT_DATA:
        {
            if(T100ProduceInfo::m_data_default){
                if(m_data->isDefault){
                    result = T100ProduceInfo::setDefaultData(m_data);
                }
            }else{
                if(m_data_master && m_data->isMaster){
                    result = T100ProduceInfo::setDefaultData(m_data);
                    if(result){
                        m_data_master = T100FALSE;
                    }
                }
            }

            m_data_segments.push_back(m_data);
            m_data = T100NULL;
        }
        break;
    case T100SEGMENT_PROCEDURE:
        {
            T100WORD_BITS       order;

            order.BYTE0.BYTE    = T100Component::T100ORDER_RETURN;

            m_code->setValue(order.WORD);
            m_code->next();

            m_code_segments.push_back(m_code);
            m_code = T100NULL;
        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::setVariable(T100STRING name, T100WORD offset)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
        {

        }
        break;
    //case T100SEGMENT_SHARE_DATA:
    case T100SEGMENT_DATA:
        {
            m_data->setVariable(name, offset);
        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::getVariable(T100STRING name, T100WORD& offset)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
        {

        }
        break;
    //case T100SEGMENT_SHARE_DATA:
    case T100SEGMENT_DATA:
        {
            m_data->getVariable(name, offset);
        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::addVariableCall(T100VARIABLE_CALL* call)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
    case T100SEGMENT_PROCEDURE:
        {
            result = m_code->addVariableCall(call);
        }
        break;
    case T100SEGMENT_DATA:
        {

        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::setLabel(T100STRING name, T100WORD offset)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
    case T100SEGMENT_PROCEDURE:
        {
            result = m_code->setLabel(name, offset);
        }
        break;
    case T100SEGMENT_DATA:
        {

        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::getLabel(T100STRING name, T100WORD& offset)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
    case T100SEGMENT_PROCEDURE:
        {
            result = m_code->getLabel(name, offset);
        }
        break;
    case T100SEGMENT_DATA:
        {

        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::addLabelCall(T100LABEL_CALL* call)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
    case T100SEGMENT_PROCEDURE:
        {
            result = m_code->addLabelCall(call);
        }
        break;
    case T100SEGMENT_DATA:
        {
            result = m_data->addLabelCall(call);
        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100BuildInfo::setProcedure(T100STRING name, T100WORD offset)
{
    T100BOOL        result          = T100TRUE;

    if(T100SEGMENT_PROCEDURE == m_type){
        result = m_code->setProcedure(name, offset);
    }
    return result;
}

T100BOOL T100BuildInfo::getProcedure(T100STRING name, T100WORD& offset)
{
    T100BOOL        result          = T100TRUE;

    if(T100SEGMENT_PROCEDURE == m_type){
        result = m_code->getProcedure(name, offset);
    }
    return result;
}

T100BOOL T100BuildInfo::addProcedureCall(T100PROCEDURE_CALL* call)
{
    T100BOOL        result          = T100TRUE;

    result = m_code->addProcedureCall(call);

    return result;
}

T100SEGMENT_CODE_VECTOR& T100BuildInfo::getCodeSegments()
{
    return m_code_segments;
}

T100SEGMENT_DATA_VECTOR& T100BuildInfo::getDataSegments()
{
    return m_data_segments;
}

T100SegmentData* T100BuildInfo::getData()
{
    return m_data;
}

T100BOOL T100BuildInfo::createCode(T100Sentence* sent)
{
    T100SentenceCode*       code            = T100NULL;

    code = static_cast<T100SentenceCode*>(sent);
    if(!code){
        return T100FALSE;
    }

    m_code = T100NEW T100SegmentCode();

    m_code->setName(code->name);

    m_code->isMaster    = m_code_master;

    m_code->isDefault   = code->isDefault;
    m_code->isVirtual   = code->isVirtual;
    m_code->isShare     = code->isShare;
    m_code->m_location  = code->location;
    m_code->m_length    = code->length;

    return T100TRUE;
}

T100BOOL T100BuildInfo::createData(T100Sentence* sent)
{
    T100SentenceData*       data            = T100NULL;

    data = static_cast<T100SentenceData*>(sent);
    if(!data){
        return T100FALSE;
    }

    m_data = T100NEW T100SegmentData();

    m_data->setName(data->name);

    m_data->isMaster    = m_data_master;

    m_data->isDefault   = data->isDefault;
    m_data->isVirtual   = data->isVirtual;
    m_data->isShare     = data->isShare;
    m_data->m_location  = data->location;
    m_data->m_length    = data->length;

    return T100TRUE;
}

T100BOOL T100BuildInfo::createProcedure(T100Sentence* sent)
{
    T100SentenceProcedure*      procedure           = T100NULL;

    procedure = static_cast<T100SentenceProcedure*>(sent);
    if(!procedure){
        return T100FALSE;
    }

    m_code = T100NEW T100SegmentCode();

    m_code->setName(procedure->name);

    m_code->setProcedure(procedure->name, m_code->getOffset());

    return T100TRUE;
}

}
