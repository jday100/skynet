#include "T100DiagramTransducer.h"

T100DiagramTransducer::T100DiagramTransducer()
    :T100Transducer()
{
    //ctor
}

T100DiagramTransducer::~T100DiagramTransducer()
{
    //dtor
}

T100BOOL T100DiagramTransducer::serialize(T100TransducerSource& source, T100TransducerTarget& target)
{
    return T100FALSE;
}

T100BOOL T100DiagramTransducer::deserialize(T100TransducerSource& source, T100TransducerTarget& target)
{
    return T100FALSE;
}
