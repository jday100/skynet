#include "T100TransducerBase.h"

namespace T100Library{

T100TransducerBase::T100TransducerBase()
{
    //ctor
}

T100TransducerBase::~T100TransducerBase()
{
    //dtor
}

T100BOOL T100TransducerBase::serialize(T100TransducerSource& source, T100TransducerTarget& target)
{
    source.setTarget(&target);
    return source.serialize();
}

T100BOOL T100TransducerBase::deserialize(T100TransducerSource& source, T100TransducerTarget& target)
{
    source.setTarget(&target);
    return source.deserialize();
}

}
