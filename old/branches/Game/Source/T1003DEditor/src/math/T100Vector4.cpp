#include "T100Vector4.h"

T100Vector4::T100Vector4() :
    X(0.0f),
    Y(0.0f),
    Z(0.0f),
    W(0.0f)
{
    //ctor
}

T100Vector4::T100Vector4(T100FLOAT x, T100FLOAT y, T100FLOAT z, T100FLOAT w)
{
    X          = x;
    Y          = y;
    Z          = z;
    W          = w;
}

T100Vector4::~T100Vector4()
{
    //dtor
}

T100Vector4 T100Vector4::operator+(T100Vector4& value)
{
    T100Vector4     result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;
    result.Z    = this->Z + value.Z;
    result.W    = this->W + value.W;

    return result;
}

T100Vector4 T100Vector4::operator*(T100Vector4& value)
{
    T100Vector4     result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;
    result.Z    = this->Z * value.Z;
    result.W    = this->W * value.W;

    return result;
}
