#include "matrix/T100Matrix4f.h"

T100Matrix4f::T100Matrix4f() :
    _11(0.0f), _12(0.0f), _13(0.0f), _14(0.0f),
    _21(0.0f), _22(0.0f), _23(0.0f), _24(0.0f),
    _31(0.0f), _32(0.0f), _33(0.0f), _34(0.0f),
    _41(0.0f), _42(0.0f), _43(0.0f), _44(0.0f)
{
    //ctor
}

T100Matrix4f::T100Matrix4f(T100FLOAT __11, T100FLOAT __12, T100FLOAT __13, T100FLOAT __14,
                           T100FLOAT __21, T100FLOAT __22, T100FLOAT __23, T100FLOAT __24,
                           T100FLOAT __31, T100FLOAT __32, T100FLOAT __33, T100FLOAT __34,
                           T100FLOAT __41, T100FLOAT __42, T100FLOAT __43, T100FLOAT __44)
{
    //ctor
    _11    = __11;
    _12    = __12;
    _13    = __13;
    _14    = __14;

    _21    = __21;
    _22    = __22;
    _23    = __23;
    _24    = __24;

    _31    = __31;
    _32    = __32;
    _33    = __33;
    _34    = __34;

    _41    = __41;
    _42    = __42;
    _43    = __43;
    _44    = __44;
}

T100Matrix4f::~T100Matrix4f()
{
    //dtor
}

T100Matrix4f T100Matrix4f::operator+(T100Matrix4f& value)
{
    T100Matrix4f    result;

    for(T100UINT i = 0; i < 16; i++){
        result.FLOAT16[i]   = this->FLOAT16[i] + value.FLOAT16[i];
    }

    return result;
}

T100Matrix4f T100Matrix4f::operator-(T100Matrix4f& value)
{
    T100Matrix4f    result;

    for(T100UINT i = 0; i < 16; i++){
        result.FLOAT16[i]   = this->FLOAT16[i] - value.FLOAT16[i];
    }

    return result;
}

T100Matrix4f T100Matrix4f::operator*(T100Matrix4f& value)
{
    T100Matrix4f    result;

    for(T100UINT i = 0; i < 4; i++){
        for(T100UINT j = 0; j < 4; j++){
            T100FLOAT   total   = 0;
            for(T100UINT k = 0; k <4; k++){
                total += this->FLOAT4X4[j][k] * value.FLOAT4X4[k][i];
            }
            result.FLOAT4X4[j][i] = total;
        }
    }

    return result;
}

T100Matrix4f T100Matrix4f::operator/(T100Matrix4f& value)
{
    T100Matrix4f    result;

    for(T100UINT i = 0; i < 4; i++){
        for(T100UINT j = 0; j < 4; j++){
            T100FLOAT   total   = 0;
            for(T100UINT k = 0; k <4; k++){
                total += this->FLOAT4X4[j][k] / value.FLOAT4X4[k][i];
            }
            result.FLOAT4X4[j][i] = total;
        }
    }

    return result;
}
