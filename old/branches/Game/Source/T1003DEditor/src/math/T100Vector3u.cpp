#include "T100Vector3u.h"

T100Vector3u::T100Vector3u() :
    X(0),
    Y(0),
    Z(0)
{
    //ctor
}

T100Vector3u::T100Vector3u(T100UINT x, T100UINT y, T100UINT z)
{
    X   = x;
    Y   = y;
    Z   = z;
}

T100Vector3u::~T100Vector3u()
{
    //dtor
}
