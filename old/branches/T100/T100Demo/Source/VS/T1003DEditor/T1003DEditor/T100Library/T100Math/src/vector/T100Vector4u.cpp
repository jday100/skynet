#include "vector/T100Vector4u.h"

T100Vector4u::T100Vector4u() :
    RED(0), GREEN(0), BLUE(0), ALPHA(0)
{
    //ctor
}

T100Vector4u::T100Vector4u(T100UINT8 red, T100UINT8 green, T100UINT8 blue, T100UINT8 alpha)
{
    //ctor
    RED     = red;
    GREEN   = green;
    BLUE    = blue;
    ALPHA   = alpha;
}

T100Vector4u::~T100Vector4u()
{
    //dtor
}

T100Vector4u T100Vector4u::operator+(T100Vector4u& value)
{
    T100Vector4u    result;

    result.RED      = this->RED     + value.RED;
    result.GREEN    = this->GREEN   + value.GREEN;
    result.BLUE     = this->BLUE    + value.BLUE;
    result.ALPHA    = this->ALPHA   + value.ALPHA;

    return result;

}

T100Vector4u T100Vector4u::operator-(T100Vector4u& value)
{
    T100Vector4u    result;

    result.RED      = this->RED     - value.RED;
    result.GREEN    = this->GREEN   - value.GREEN;
    result.BLUE     = this->BLUE    - value.BLUE;
    result.ALPHA    = this->ALPHA   - value.ALPHA;

    return result;
}

T100Vector4u T100Vector4u::operator*(T100Vector4u& value)
{
    T100Vector4u    result;

    result.RED      = this->RED     * value.RED;
    result.GREEN    = this->GREEN   * value.GREEN;
    result.BLUE     = this->BLUE    * value.BLUE;
    result.ALPHA    = this->ALPHA   * value.ALPHA;

    return result;
}

T100Vector4u T100Vector4u::operator/(T100Vector4u& value)
{
    T100Vector4u    result;

    result.RED      = this->RED     / value.RED;
    result.GREEN    = this->GREEN   / value.GREEN;
    result.BLUE     = this->BLUE    / value.BLUE;
    result.ALPHA    = this->ALPHA   / value.ALPHA;

    return result;
}
