#include "T100DiagramFileSource.h"

#include "T100DiagramTransducerTarget.h"

T100DiagramFileSource::T100DiagramFileSource(T100DiagramInfo* diagram)
    :T100DiagramTransducerSource(), m_diagram(diagram)
{
    //ctor
}

T100DiagramFileSource::~T100DiagramFileSource()
{
    //dtor
}

T100WORD T100DiagramFileSource::getSign()
{
    return m_sign;
}

T100WORD T100DiagramFileSource::getType()
{
    return m_type;
}

T100WORD T100DiagramFileSource::getVersion()
{
    return m_version;
}

T100BOOL T100DiagramFileSource::serialize()
{
    T100BOOL                result;
    T100DIAGRAM_HEAD*       head            = T100NULL;

    head    = m_diagram->getHead();
    if(head){
        result  = m_target->setWORD(head->COMMON.SIGN);
        if(!result)return T100FALSE;

        result  = m_target->setWORD(head->TYPE);
        if(!result)return T100FALSE;

        result  = m_target->setWORD(head->VERSION);
    }

    return result;
}

T100BOOL T100DiagramFileSource::deserialize()
{
    T100BOOL            result;

    result  = m_target->getWORD(m_sign);

    result  = m_target->getWORD(m_type);

    result  = m_target->getWORD(m_version);

    return result;
}
