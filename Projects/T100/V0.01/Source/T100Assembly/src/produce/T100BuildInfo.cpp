#include "T100BuildInfo.h"

#include "T100Sentence.h"


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
            return m_code->getOffset();
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
    T100BOOL            result          = T100TRUE;

    m_type = sent->type;

    switch(m_type){
    case T100SENTENCE_CODE:
        {
            m_type  = T100SEGMENT_CODE;

            m_code  = T100NEW T100SegmentCode();

        }
        break;
    case T100SENTENCE_DATA:
        {
            m_type  = T100SEGMENT_DATA;

            m_data  = T100NEW T100SegmentData();

        }
        break;
    case T100SENTENCE_PROCEDURE:
        {
            m_type  = T100SEGMENT_PROCEDURE;

            m_code  = T100NEW T100SegmentCode();

        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100BuildInfo::closeSegment()
{
    T100BOOL            result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
        {



        }
        break;
    case T100SEGMENT_DATA:
        {

        }
        break;
    case T100SEGMENT_PROCEDURE:
        {
            T100WORD_BITS       order;

            order.BYTE0.BYTE    = T100ORDER_RETURN;

            m_code->setValue(order.WORD);
            m_code->next();

        }
        break;
    default:
        result = T100FALSE;
    }


    return result;
}

T100BOOL T100BuildInfo::setVariable(T100String name, T100WORD offset)
{
    T100BOOL            result          = T100TRUE;

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

T100BOOL T100BuildInfo::getVariable(T100String name, T100WORD& offset)
{
    T100BOOL            result          = T100TRUE;

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
    T100BOOL            result          = T100TRUE;

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

T100BOOL T100BuildInfo::setLabel(T100String name, T100WORD offset)
{
    T100BOOL            result          = T100TRUE;

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

T100BOOL T100BuildInfo::getLabel(T100String name, T100WORD& offset)
{
    T100BOOL            result          = T100TRUE;

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
    T100BOOL            result          = T100TRUE;

    switch(m_type){
    case T100SEGMENT_CODE:
    case T100SEGMENT_PROCEDURE:
        {
            result = m_code->addLabelCall(call);
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

T100BOOL T100BuildInfo::setProcedure(T100String name, T100WORD offset)
{
    T100BOOL            result          = T100TRUE;

    if(T100SEGMENT_PROCEDURE == m_type){
        result = m_code->setProcedure(name, offset);
    }

    return result;
}

T100BOOL T100BuildInfo::getProcedure(T100String name, T100WORD& offset)
{
    T100BOOL            result          = T100TRUE;

    if(T100SEGMENT_PROCEDURE == m_type){
        result = m_code->getProcedure(name, offset);
    }

    return result;
}

T100BOOL T100BuildInfo::addProcedureCall(T100PROCEDURE_CALL* call)
{
    T100BOOL            result          = T100TRUE;

    if(T100SEGMENT_PROCEDURE == m_type){
        result = m_code->addProcedureCall(call);
    }

    return result;
}

