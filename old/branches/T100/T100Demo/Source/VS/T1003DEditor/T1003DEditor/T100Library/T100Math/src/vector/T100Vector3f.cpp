#include "vector/T100Vector3f.h"

#include <math.h>

T100Vector3f::T100Vector3f() :
    X(0.0f), Y(0.0f), Z(0.0f)
{
    //ctor
}

T100Vector3f::T100Vector3f(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    //ctor
    X   = x;
    Y   = y;
    Z   = z;
}

T100Vector3f::~T100Vector3f()
{
    //dtor
}

T100Vector3f T100Vector3f::operator+(T100Vector3f& value)
{
    T100Vector3f    result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;
    result.Z    = this->Z + value.Z;

    return result;

}

T100Vector3f T100Vector3f::operator-(T100Vector3f& value)
{
    T100Vector3f    result;

    result.X    = this->X - value.X;
    result.Y    = this->Y - value.Y;
    result.Z    = this->Z - value.Z;

    return result;
}

T100Vector3f T100Vector3f::operator*(T100Vector3f& value)
{
    T100Vector3f    result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;
    result.Z    = this->Z * value.Z;

    return result;
}

T100Vector3f T100Vector3f::operator/(T100Vector3f& value)
{
    T100Vector3f    result;

    result.X    = this->X / value.X;
    result.Y    = this->Y / value.Y;
    result.Z    = this->Z / value.Z;

    return result;
}

T100Vector3f T100Vector3f::operator*(T100FLOAT value)
{
    T100Vector3f    result;

    result.X    = this->X * value;
    result.Y    = this->Y * value;
    result.Z    = this->Z * value;

    return result;
}

T100Vector3f T100Vector3f::operator/(T100FLOAT value)
{
    T100Vector3f    result;

    result.X    = this->X / value;
    result.Y    = this->Y / value;
    result.Z    = this->Z / value;

    return result;
}

T100FLOAT T100Vector3f::Norm()
{
    T100FLOAT   total;

    total   = X * X + Y * Y + Z * Z;

    return sqrtf(total);
}
