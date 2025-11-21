#include "vector/T100Vector4f.h"

T100Vector4f::T100Vector4f() :
    X(0.0f), Y(0.0f), Z(0.0f), W(0.0f)
{
    //ctor
}

T100Vector4f::T100Vector4f(T100FLOAT x, T100FLOAT y, T100FLOAT z, T100FLOAT w)
{
    //ctor
    X   = x;
    Y   = y;
    Z   = z;
    W   = w;
}

T100Vector4f::~T100Vector4f()
{
    //dtor
}

T100Vector4f T100Vector4f::operator+(T100Vector4f& value)
{
    T100Vector4f    result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;
    result.Z    = this->Z + value.Z;
    result.W    = this->W + value.W;

    return result;

}

T100Vector4f T100Vector4f::operator-(T100Vector4f& value)
{
    T100Vector4f    result;

    result.X    = this->X - value.X;
    result.Y    = this->Y - value.Y;
    result.Z    = this->Z - value.Z;
    result.W    = this->W - value.W;

    return result;
}

T100Vector4f T100Vector4f::operator*(T100Vector4f& value)
{
    T100Vector4f    result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;
    result.Z    = this->Z * value.Z;
    result.W    = this->W * value.W;

    return result;
}

T100Vector4f T100Vector4f::operator/(T100Vector4f& value)
{
    T100Vector4f    result;

    result.X    = this->X / value.X;
    result.Y    = this->Y / value.Y;
    result.Z    = this->Z / value.Z;
    result.W    = this->W / value.W;

    return result;
}
