#include "T100ElementTransducer.h"

T100ElementTransducer::T100ElementTransducer() :
    T100TransducerBase()
{
    //ctor
}

T100ElementTransducer::~T100ElementTransducer()
{
    //dtor
}

T100BOOL T100ElementTransducer::Serialize(T100ElementTransducerSource& source, T100ElementTransducerTarget& target)
{
    return T100TransducerBase::Serialize(source, target);
}

T100BOOL T100ElementTransducer::Deserialize(T100ElementTransducerSource& source, T100ElementTransducerTarget& target)
{
    return T100TransducerBase::Deserialize(source, target);
}
