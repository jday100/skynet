#include "T100DiagramTransducerSource.h"

T100DiagramTransducerSource::T100DiagramTransducerSource()
{
    //ctor
}

T100DiagramTransducerSource::~T100DiagramTransducerSource()
{
    //dtor
}

T100VOID T100DiagramTransducerSource::setTarget(T100DiagramTransducerTarget* target)
{
    m_target    = target;
}

T100BOOL T100DiagramTransducerSource::serialize()
{
    return T100FALSE;
}

T100BOOL T100DiagramTransducerSource::deserialize()
{
    return T100FALSE;
}
