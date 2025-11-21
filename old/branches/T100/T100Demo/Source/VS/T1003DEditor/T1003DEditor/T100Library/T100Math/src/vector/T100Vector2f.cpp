#include "vector/T100Vector2f.h"

T100Vector2f::T100Vector2f() :
    X(0.0f), Y(0.0f)
{
    //ctor
}

T100Vector2f::T100Vector2f(T100FLOAT x, T100FLOAT y)
{
    //ctor
    X   = x;
    Y   = y;
}

T100Vector2f::~T100Vector2f()
{
    //dtor
}

T100Vector2f T100Vector2f::operator+(T100Vector2f& value)
{
    T100Vector2f    result;

    result.X    = this->X + value.X;
    result.Y    = this->Y + value.Y;

    return result;

}

T100Vector2f T100Vector2f::operator-(T100Vector2f& value)
{
    T100Vector2f    result;

    result.X    = this->X - value.X;
    result.Y    = this->Y - value.Y;

    return result;
}

T100Vector2f T100Vector2f::operator*(T100Vector2f& value)
{
    T100Vector2f    result;

    result.X    = this->X * value.X;
    result.Y    = this->Y * value.Y;

    return result;
}

T100Vector2f T100Vector2f::operator/(T100Vector2f& value)
{
    T100Vector2f    result;

    result.X    = this->X / value.X;
    result.Y    = this->Y / value.Y;

    return result;
}
