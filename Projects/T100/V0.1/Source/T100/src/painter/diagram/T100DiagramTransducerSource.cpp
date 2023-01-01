#include "T100DiagramTransducerSource.h"

#include "T100DiagramTransducerTarget.h"

namespace T100Painter{

T100DiagramTransducerSource::T100DiagramTransducerSource()
    :T100Library::T100TransducerSource()
{
    //ctor
}

T100DiagramTransducerSource::~T100DiagramTransducerSource()
{
    //dtor
}

T100VOID T100DiagramTransducerSource::setTarget(T100Library::T100TransducerTarget* target)
{
    T100DiagramTransducerTarget*        result          = T100NULL;

    result      = static_cast<T100DiagramTransducerTarget*>(target);

    m_target    = result;
}

}
