#include "base/T100Point.h"

namespace T100LIBRARY{

T100Point::T100Point() :
    T100Class()
{
    //ctor
}

T100Point::T100Point(T100INT x, T100INT y) :
    T100Class(),
    X(x),
    Y(y)
{
    //ctor
}

T100Point::~T100Point()
{
    //dtor
}

}
