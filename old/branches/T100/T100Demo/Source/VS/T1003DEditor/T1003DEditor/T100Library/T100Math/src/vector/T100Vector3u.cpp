#include "vector/T100Vector3u.h"

T100Vector3u::T100Vector3u() :
    X(0), Y(0), Z(0)
{
    //ctor
}

T100Vector3u::T100Vector3u(T100UINT x, T100UINT y, T100UINT z)
{
    //ctor
    X   = x;
    Y   = y;
    Z   = z;
}

T100Vector3u::~T100Vector3u()
{
    //dtor
}

T100Vector3u T100Vector3u::operator+(T100Vector3u& value)
{
    T100Vector3u    result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;
    result.Z    = this->Z + value.Z;

    return result;

}

T100Vector3u T100Vector3u::operator-(T100Vector3u& value)
{
    T100Vector3u    result;

    result.X    = this->X - value.X;
    result.Y    = this->Y - value.Y;
    result.Z    = this->Z - value.Z;

    return result;
}

T100Vector3u T100Vector3u::operator*(T100Vector3u& value)
{
    T100Vector3u    result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;
    result.Z    = this->Z * value.Z;

    return result;
}

T100Vector3u T100Vector3u::operator/(T100Vector3u& value)
{
    T100Vector3u    result;

    result.X    = this->X / value.X;
    result.Y    = this->Y / value.Y;
    result.Z    = this->Z / value.Z;

    return result;
}
