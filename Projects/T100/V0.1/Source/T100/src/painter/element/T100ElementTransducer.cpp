#include "T100ElementTransducer.h"

namespace T100Painter{

T100ElementTransducer::T100ElementTransducer()
    :T100Library::T100TransducerBase()
{
    //ctor
}

T100ElementTransducer::~T100ElementTransducer()
{
    //dtor
}

T100BOOL T100ElementTransducer::serialize(T100ElementTransducerSource& source, T100ElementTransducerTarget& target)
{
    return T100Library::T100TransducerBase::serialize(source, target);
}

T100BOOL T100ElementTransducer::deserialize(T100ElementTransducerSource& source, T100ElementTransducerTarget& target)
{
    return T100Library::T100TransducerBase::deserialize(source, target);
}

}

