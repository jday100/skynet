#include "T100DiagramTransducer.h"

T100DiagramTransducer::T100DiagramTransducer() :
    T100TransducerBase()
{
    //ctor
}

T100DiagramTransducer::~T100DiagramTransducer()
{
    //dtor
}

T100BOOL T100DiagramTransducer::Serialize(T100DiagramTransducerSource& source, T100DiagramTransducerTarget& target)
{
    return T100TransducerBase::Serialize(source, target);
}

T100BOOL T100DiagramTransducer::Deserialize(T100DiagramTransducerSource& source, T100DiagramTransducerTarget& target)
{
    return T100TransducerBase::Deserialize(source, target);
}
