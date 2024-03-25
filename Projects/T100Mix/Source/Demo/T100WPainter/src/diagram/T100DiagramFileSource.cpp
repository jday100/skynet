#include "T100DiagramFileSource.h"

#include "T100DiagramTransducerTarget.h"

T100DiagramFileSource::T100DiagramFileSource()
    :T100DiagramTransducerSource()
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
    T100BOOL            result;

    return result;
}

T100BOOL T100DiagramFileSource::deserialize()
{
    T100BOOL            result;

    result  = m_target->getWord(m_sign);

    result  = m_target->getWord(m_type);

    result  = m_target->getWord(m_version);

    return result;
}
