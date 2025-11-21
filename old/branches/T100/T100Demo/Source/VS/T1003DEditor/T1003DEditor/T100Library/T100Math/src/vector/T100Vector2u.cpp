#include "vector/T100Vector2u.h"

T100Vector2u::T100Vector2u() :
    X(0), Y(0)
{
    //ctor
}

T100Vector2u::T100Vector2u(T100UINT x, T100UINT y)
{
    //ctor
    X   = x;
    Y   = y;
}

T100Vector2u::~T100Vector2u()
{
    //dtor
}

T100Vector2u T100Vector2u::operator+(T100Vector2u& value)
{
    T100Vector2u    result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;

    return result;

}

T100Vector2u T100Vector2u::operator-(T100Vector2u& value)
{
    T100Vector2u    result;

    result.X    = this->X - value.X;
    result.Y    = this->Y - value.Y;

    return result;
}

T100Vector2u T100Vector2u::operator*(T100Vector2u& value)
{
    T100Vector2u    result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;

    return result;
}

T100Vector2u T100Vector2u::operator/(T100Vector2u& value)
{
    T100Vector2u    result;

    result.X    = this->X / value.X;
    result.Y    = this->Y / value.Y;

    return result;
}
