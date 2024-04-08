#include "T100ElementBaseSource.h"

#include "T100DiagramTransducerTarget.h"

T100ElementBaseSource::T100ElementBaseSource()
    :T100DiagramTransducerSource()
{
    //ctor
}

T100ElementBaseSource::~T100ElementBaseSource()
{
    //dtor
}

T100VOID T100ElementBaseSource::setElement(T100ElementBase* element)
{
    m_element   = element;
}

T100ElementBase* T100ElementBaseSource::getElement()
{
    return m_element;
}

T100WORD T100ElementBaseSource::getType()
{
    return m_type;
}

T100BOOL T100ElementBaseSource::serialize()
{
    T100BOOL            result      = T100FALSE;

    result  = m_target->setWORD(m_element->getType());

    return result;
}

T100BOOL T100ElementBaseSource::deserialize()
{
    T100BOOL            result      = T100FALSE;

    result  = m_target->getWORD(m_type);

    return result;
}
