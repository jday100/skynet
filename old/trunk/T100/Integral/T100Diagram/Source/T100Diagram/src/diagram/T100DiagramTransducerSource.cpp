#include "T100DiagramTransducerSource.h"

#include "T100DiagramTransducerTarget.h"

T100DiagramTransducerSource::T100DiagramTransducerSource() :
    T100TransducerSource()
{
    //ctor
}

T100DiagramTransducerSource::~T100DiagramTransducerSource()
{
    //dtor
}

T100VOID T100DiagramTransducerSource::SetTarget(T100TransducerTarget* target)
{
    T100DiagramTransducerTarget*        result          = T100NULL;

    result      = static_cast<T100DiagramTransducerTarget*>(target);

    m_target    = result;
}
