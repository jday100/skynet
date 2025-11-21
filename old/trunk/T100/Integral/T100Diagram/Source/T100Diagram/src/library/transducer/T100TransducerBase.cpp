#include "T100TransducerBase.h"

T100TransducerBase::T100TransducerBase()
{
    //ctor
}

T100TransducerBase::~T100TransducerBase()
{
    //dtor
}

T100BOOL T100TransducerBase::Serialize(T100TransducerSource& source, T100TransducerTarget& target)
{
    source.SetTarget(&target);
    return source.Serialize();
}

T100BOOL T100TransducerBase::Deserialize(T100TransducerSource& source, T100TransducerTarget& target)
{
    source.SetTarget(&target);
    return source.Deserialize();
}
