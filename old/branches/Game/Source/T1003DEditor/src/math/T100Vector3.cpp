#include "T100Vector3.h"

T100Vector3::T100Vector3() :
    X(0.0f),
    Y(0.0f),
    Z(0.0f)
{
    //ctor
}

T100Vector3::T100Vector3(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    X   = x;
    Y   = y;
    Z   = z;
}

T100Vector3::~T100Vector3()
{
    //dtor
}

T100Vector3 T100Vector3::operator+(T100Vector3& value)
{
    T100Vector3     result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;
    result.Z    = this->Z + value.Z;

    return result;
}

T100Vector3 T100Vector3::operator*(T100Vector3& value)
{
    T100Vector3     result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;
    result.Z    = this->Z * value.Z;

    return result;
}
