#include "T100ElementCircleSource.h"

T100ElementCircleSource::T100ElementCircleSource()
    :T100DiagramTransducerSource()
{
    //ctor
}

T100ElementCircleSource::~T100ElementCircleSource()
{
    //dtor
}

T100BOOL T100ElementCircleSource::serialize()
{
    return T100FALSE;
}

T100BOOL T100ElementCircleSource::deserialize()
{
    return T100FALSE;
}
