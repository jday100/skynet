#include "T100DiagramTransducer.h"

namespace T100Painter{

T100DiagramTransducer::T100DiagramTransducer()
    :T100Library::T100TransducerBase()
{
    //ctor
}

T100DiagramTransducer::~T100DiagramTransducer()
{
    //dtor
}

T100BOOL T100DiagramTransducer::serialize(T100DiagramTransducerSource& source, T100DiagramTransducerTarget& target)
{
    return T100Library::T100TransducerBase::serialize(source, target);
}

T100BOOL T100DiagramTransducer::deserialize(T100DiagramTransducerSource& source, T100DiagramTransducerTarget& target)
{
    return T100Library::T100TransducerBase::deserialize(source, target);
}

}
