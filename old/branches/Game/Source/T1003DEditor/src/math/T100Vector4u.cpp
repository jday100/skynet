#include "T100Vector4u.h"

T100Vector4u::T100Vector4u() :
    X(0),
    Y(0),
    Z(0),
    W(0)
{
    //ctor
}

T100Vector4u::T100Vector4u(T100UINT r, T100UINT g, T100UINT b, T100UINT a)
{
    RED         = r;
    GREEN       = g;
    BLUE        = b;
    ALPHA       = a;
}

T100Vector4u::~T100Vector4u()
{
    //dtor
}
