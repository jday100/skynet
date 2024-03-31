#include "T100BivectorTools.h"

#include <math.h>

T100BivectorTools::T100BivectorTools()
{
    //ctor
}

T100BivectorTools::~T100BivectorTools()
{
    //dtor
}

T100FLOAT T100BivectorTools::distance(T100Bivector a, T100Bivector b)
{
    T100FLOAT           dx;
    T100FLOAT           dy;
    T100FLOAT           value;
    T100FLOAT           result;

    dx      = b.X - a.X;
    dy      = b.Y - a.Y;
    value   = dx * dx + dy * dy;
    result  = std::sqrt(value);

    return result;
}
