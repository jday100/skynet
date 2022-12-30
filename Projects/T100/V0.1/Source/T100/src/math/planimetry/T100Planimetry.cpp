#include "T100Planimetry.h"

#include <math.h>

namespace T100Math{

T100Planimetry::T100Planimetry()
{
    //ctor
}

T100Planimetry::~T100Planimetry()
{
    //dtor
}

T100FLOAT T100Planimetry::Dist(T100FLOAT sx, T100FLOAT sy, T100FLOAT tx, T100FLOAT ty)
{
    T100FLOAT       x;
    T100FLOAT       y;
    T100FLOAT       value;
    T100FLOAT       result;

    x       = sx - tx;
    y       = sy - ty;
    value   = x * x + y * y;
    result  = std::sqrt(value);

    return result;
}

}
