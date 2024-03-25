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
