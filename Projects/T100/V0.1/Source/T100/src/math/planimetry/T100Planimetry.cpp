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

T100BOOL T100Planimetry::Hit(T100FLOAT sx, T100FLOAT sy, T100FLOAT ex, T100FLOAT ey, T100FLOAT x, T100FLOAT y)
{
    T100FLOAT   x1, y1;
    T100FLOAT   x2, y2;

    if(sx <= ex){
        x1  = sx;
        x2  = ex;
    }else{
        x1  = ex;
        x2  = sx;
    }

    if(sy <= ey){
        y1  = sy;
        y2  = ey;
    }else{
        y1  = ey;
        y2  = sy;
    }

    if(x >= x1 && x <= x2 && y >= y1 && y <= y2){
        return T100TRUE;
    }
    return T100FALSE;
}

}
