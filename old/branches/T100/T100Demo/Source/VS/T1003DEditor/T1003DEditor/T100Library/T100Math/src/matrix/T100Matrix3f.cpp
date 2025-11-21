#include "matrix/T100Matrix3f.h"

T100Matrix3f::T100Matrix3f() :
    _11(0.0f), _12(0.0f), _13(0.0f),
    _21(0.0f), _22(0.0f), _23(0.0f),
    _31(0.0f), _32(0.0f), _33(0.0f)
{
    //ctor
}

T100Matrix3f::T100Matrix3f(T100FLOAT __11, T100FLOAT __12, T100FLOAT __13,
                           T100FLOAT __21, T100FLOAT __22, T100FLOAT __23,
                           T100FLOAT __31, T100FLOAT __32, T100FLOAT __33)
{
    //ctor
    _11    = __11;
    _12    = __12;
    _13    = __13;

    _21    = __21;
    _22    = __22;
    _23    = __23;

    _31    = __31;
    _32    = __32;
    _33    = __33;
}

T100Matrix3f::~T100Matrix3f()
{
    //dtor
}

T100Matrix3f T100Matrix3f::operator+(T100Matrix3f& value)
{
    T100Matrix3f    result;

    for(T100UINT i = 0; i < 9; i++){
        result.FLOAT9[i]   = this->FLOAT9[i] + value.FLOAT9[i];
    }

    return result;
}

T100Matrix3f T100Matrix3f::operator-(T100Matrix3f& value)
{
    T100Matrix3f    result;

    for(T100UINT i = 0; i < 9; i++){
        result.FLOAT9[i]   = this->FLOAT9[i] - value.FLOAT9[i];
    }

    return result;
}

T100Matrix3f T100Matrix3f::operator*(T100Matrix3f& value)
{
    T100Matrix3f    result;

    for(T100UINT i = 0; i < 3; i++){
        for(T100UINT j = 0; j < 3; j++){
            T100FLOAT   total   = 0;
            for(T100UINT k = 0; k <3; k++){
                total += this->FLOAT3X3[j][k] * value.FLOAT3X3[k][i];
            }
            result.FLOAT3X3[j][i] = total;
        }
    }

    return result;
}

T100Matrix3f T100Matrix3f::operator/(T100Matrix3f& value)
{
    T100Matrix3f    result;

    for(T100UINT i = 0; i < 3; i++){
        for(T100UINT j = 0; j < 3; j++){
            T100FLOAT   total   = 0;
            for(T100UINT k = 0; k <3; k++){
                total += this->FLOAT3X3[j][k] / value.FLOAT3X3[k][i];
            }
            result.FLOAT3X3[j][i] = total;
        }
    }

    return result;
}
