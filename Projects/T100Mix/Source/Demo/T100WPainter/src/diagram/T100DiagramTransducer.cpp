#include "T100DiagramTransducer.h"

T100DiagramTransducer::T100DiagramTransducer()
{
    //ctor
}

T100DiagramTransducer::~T100DiagramTransducer()
{
    //dtor
}

T100BOOL T100DiagramTransducer::serialize(T100DiagramTransducerSource& source, T100DiagramTransducerTarget& target)
{
    source.setTarget(&target);
    return source.serialize();
}

T100BOOL T100DiagramTransducer::deserialize(T100DiagramTransducerSource& source, T100DiagramTransducerTarget& target)
{
    source.setTarget(&target);
    return source.deserialize();
}
