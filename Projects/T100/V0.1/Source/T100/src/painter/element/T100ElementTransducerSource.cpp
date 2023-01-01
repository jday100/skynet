#include "T100ElementTransducerSource.h"

#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementTransducerSource::T100ElementTransducerSource()
    :T100DiagramTransducerSource()
{
    //ctor
}

T100ElementTransducerSource::~T100ElementTransducerSource()
{
    //dtor
}

T100VOID T100ElementTransducerSource::setTarget(T100Library::T100TransducerTarget* target)
{
    T100ElementTransducerTarget*        result          = T100NULL;

    result      = static_cast<T100ElementTransducerTarget*>(target);

    m_target    = result;
}

}
