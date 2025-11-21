#include "T100VectorTools.h"

#include <math.h>

T100VectorTools::T100VectorTools()
{
    //ctor
}

T100VectorTools::~T100VectorTools()
{
    //dtor
}

T100Vector3 operator*(T100Vector3& para1, T100Matrix3& para2)
{
    T100Vector3     result;

    for(T100UINT i = 0; i < 3; i++){
        T100FLOAT       total = 0;
        for(T100UINT j = 0; j < 3; j++){
            total += para1.FLOAT3[j] * para2.FLOAT3X3[j][i];
        }
        result.FLOAT3[i] = total;
    }

    return result;
}

T100Vector4 operator*(T100Vector4& para1, T100Matrix4& para2)
{
    T100Vector4     result;

    for(T100UINT i = 0; i < 4; i++){
        T100FLOAT       total = 0;
        for(T100UINT j = 0; j < 4; j++){
            total += para1.FLOAT4[j] * para2.FLOAT4X4[i][j];
        }
        result.FLOAT4[i] = total;
    }

    return result;
}

T100VOID T100VectorTools::Translation(T100Vector3 source, T100Vector3 para, T100Vector3& target)
{
    target  = source + para;
}

T100VOID T100VectorTools::Rotation(T100Vector3 source, T100Vector3 para, T100Vector3& target)
{
    //target  = source * ToMatrix3(para);
}

T100VOID T100VectorTools::Scaling(T100Vector3 source, T100Vector3 para, T100Vector3& target)
{

}

T100Matrix3 T100VectorTools::ToMatrix3(T100Vector3& value)
{
    T100Matrix3     result;

    return result;
}

T100Vector3 T100VectorTools::ToVector3(T100Matrix3& value)
{
    T100Vector3     result;

    return result;
}

T100VOID T100VectorTools::RotationX(T100Vector3 source, T100FLOAT value, T100Vector3& target)
{
    T100Matrix3     matrix;

    target = source * matrix;
}

T100VOID T100VectorTools::RotationZ(T100Vector3 source, T100FLOAT value, T100Vector3& target)
{
    T100Vector4     para;
    T100Vector4     result;
    T100Matrix4     matrix;

    ToRotationZMatrix4(value, matrix);
    ToVector4One(source, para);

    result  = para * matrix;

    ToVector3(result, target);
}

T100VOID T100VectorTools::ToRotationXMatrix4(T100FLOAT angle, T100Matrix4& result)
{
    T100FLOAT       fSinValue;
    T100FLOAT       fCosValue;
    //ScalarSinAndCos(angle, fSinValue, fCosValue);
    fSinValue   = sin(angle);
    fCosValue   = cos(angle);

    /*
    result.Data.FLOAT4X4[0][0]  = 1.0f;
    result.Data.FLOAT4X4[0][1]  = 0.0f;
    result.Data.FLOAT4X4[0][2]  = 0.0f;
    result.Data.FLOAT4X4[0][3]  = 0.0f;

    result.Data.FLOAT4X4[1][0]  = 0.0f;
    result.Data.FLOAT4X4[1][1]  = fCosValue;
    result.Data.FLOAT4X4[1][2]  = fSinValue;
    result.Data.FLOAT4X4[1][3]  = 0.0f;

    result.Data.FLOAT4X4[2][0]  = 0.0f;
    result.Data.FLOAT4X4[2][1]  = -fSinValue;
    result.Data.FLOAT4X4[2][2]  = fCosValue;
    result.Data.FLOAT4X4[2][3]  = 0.0f;

    result.Data.FLOAT4X4[3][0]  = 0.0f;
    result.Data.FLOAT4X4[3][1]  = 0.0f;
    result.Data.FLOAT4X4[3][2]  = 0.0f;
    result.Data.FLOAT4X4[3][3]  = 1.0f;
    */

    result.FLOAT4X4[0][0]  = fCosValue;
    result.FLOAT4X4[0][1]  = fSinValue;
    result.FLOAT4X4[0][2]  = 0.0f;
    result.FLOAT4X4[0][3]  = 0.0f;

    result.FLOAT4X4[1][0]  = -fSinValue;
    result.FLOAT4X4[1][1]  = fCosValue;
    result.FLOAT4X4[1][2]  = 0.0f;
    result.FLOAT4X4[1][3]  = 0.0f;

    result.FLOAT4X4[2][0]  = 0.0f;
    result.FLOAT4X4[2][1]  = 0.0f;
    result.FLOAT4X4[2][2]  = 1.0f;
    result.FLOAT4X4[2][3]  = 0.0f;

    result.FLOAT4X4[3][0]  = 0.0f;
    result.FLOAT4X4[3][1]  = 0.0f;
    result.FLOAT4X4[3][2]  = 0.0f;
    result.FLOAT4X4[3][3]  = 1.0f;
}

T100VOID T100VectorTools::ToRotationYMatrix4(T100FLOAT angle, T100Matrix4& result)
{
    T100FLOAT       fSinValue;
    T100FLOAT       fCosValue;
    //ScalarSinAndCos(angle, fSinValue, fCosValue);
    fSinValue   = sin(angle);
    fCosValue   = cos(angle);

    /*
    result.Data.FLOAT4X4[0][0]  = 1.0f;
    result.Data.FLOAT4X4[0][1]  = 0.0f;
    result.Data.FLOAT4X4[0][2]  = 0.0f;
    result.Data.FLOAT4X4[0][3]  = 0.0f;

    result.Data.FLOAT4X4[1][0]  = 0.0f;
    result.Data.FLOAT4X4[1][1]  = fCosValue;
    result.Data.FLOAT4X4[1][2]  = fSinValue;
    result.Data.FLOAT4X4[1][3]  = 0.0f;

    result.Data.FLOAT4X4[2][0]  = 0.0f;
    result.Data.FLOAT4X4[2][1]  = -fSinValue;
    result.Data.FLOAT4X4[2][2]  = fCosValue;
    result.Data.FLOAT4X4[2][3]  = 0.0f;

    result.Data.FLOAT4X4[3][0]  = 0.0f;
    result.Data.FLOAT4X4[3][1]  = 0.0f;
    result.Data.FLOAT4X4[3][2]  = 0.0f;
    result.Data.FLOAT4X4[3][3]  = 1.0f;
    */

    result.FLOAT4X4[0][0]  = fCosValue;
    result.FLOAT4X4[0][1]  = fSinValue;
    result.FLOAT4X4[0][2]  = 0.0f;
    result.FLOAT4X4[0][3]  = 0.0f;

    result.FLOAT4X4[1][0]  = -fSinValue;
    result.FLOAT4X4[1][1]  = fCosValue;
    result.FLOAT4X4[1][2]  = 0.0f;
    result.FLOAT4X4[1][3]  = 0.0f;

    result.FLOAT4X4[2][0]  = 0.0f;
    result.FLOAT4X4[2][1]  = 0.0f;
    result.FLOAT4X4[2][2]  = 1.0f;
    result.FLOAT4X4[2][3]  = 0.0f;

    result.FLOAT4X4[3][0]  = 0.0f;
    result.FLOAT4X4[3][1]  = 0.0f;
    result.FLOAT4X4[3][2]  = 0.0f;
    result.FLOAT4X4[3][3]  = 1.0f;
}

T100VOID T100VectorTools::ToRotationZMatrix4(T100FLOAT angle, T100Matrix4& result)
{
    T100FLOAT       fSinValue;
    T100FLOAT       fCosValue;
    //ScalarSinAndCos(angle, fSinValue, fCosValue);
    fSinValue   = sin(angle);
    fCosValue   = cos(angle);

    /*
    result.Data.FLOAT4X4[0][0]  = 1.0f;
    result.Data.FLOAT4X4[0][1]  = 0.0f;
    result.Data.FLOAT4X4[0][2]  = 0.0f;
    result.Data.FLOAT4X4[0][3]  = 0.0f;

    result.Data.FLOAT4X4[1][0]  = 0.0f;
    result.Data.FLOAT4X4[1][1]  = fCosValue;
    result.Data.FLOAT4X4[1][2]  = fSinValue;
    result.Data.FLOAT4X4[1][3]  = 0.0f;

    result.Data.FLOAT4X4[2][0]  = 0.0f;
    result.Data.FLOAT4X4[2][1]  = -fSinValue;
    result.Data.FLOAT4X4[2][2]  = fCosValue;
    result.Data.FLOAT4X4[2][3]  = 0.0f;

    result.Data.FLOAT4X4[3][0]  = 0.0f;
    result.Data.FLOAT4X4[3][1]  = 0.0f;
    result.Data.FLOAT4X4[3][2]  = 0.0f;
    result.Data.FLOAT4X4[3][3]  = 1.0f;
    */

    result.FLOAT4X4[0][0]  = fCosValue;
    result.FLOAT4X4[0][1]  = fSinValue;
    result.FLOAT4X4[0][2]  = 0.0f;
    result.FLOAT4X4[0][3]  = 0.0f;

    result.FLOAT4X4[1][0]  = -fSinValue;
    result.FLOAT4X4[1][1]  = fCosValue;
    result.FLOAT4X4[1][2]  = 0.0f;
    result.FLOAT4X4[1][3]  = 0.0f;

    result.FLOAT4X4[2][0]  = 0.0f;
    result.FLOAT4X4[2][1]  = 0.0f;
    result.FLOAT4X4[2][2]  = 1.0f;
    result.FLOAT4X4[2][3]  = 0.0f;

    result.FLOAT4X4[3][0]  = 0.0f;
    result.FLOAT4X4[3][1]  = 0.0f;
    result.FLOAT4X4[3][2]  = 0.0f;
    result.FLOAT4X4[3][3]  = 1.0f;
}

T100VOID T100VectorTools::ToVector3(T100Vector4 source, T100Vector3& target)
{
    target.X   = source.X;
    target.Y   = source.Y;
    target.Z   = source.Z;
}

T100VOID T100VectorTools::ToVector4One(T100Vector3 source, T100Vector4& target)
{
    target.X   = source.X;
    target.Y   = source.Y;
    target.Z   = source.Z;
    target.W   = 1;
}

T100VOID T100VectorTools::ToVector4Zero(T100Vector3 source, T100Vector4& target)
{
    target.X   = source.X;
    target.Y   = source.Y;
    target.Z   = source.Z;
    target.W   = 0;
}

T100VOID T100VectorTools::ScalarSinAndCos(T100FLOAT angle, T100FLOAT& fsin, T100FLOAT& fcos)
{
    T100FLOAT quotient = T100_1DIV2XPI * angle;
    if (angle >= 0.0f)
    {
        quotient = static_cast<T100FLOAT>(static_cast<T100INT>(quotient + 0.5f));
    }
    else
    {
        quotient = static_cast<T100FLOAT>(static_cast<T100INT>(quotient - 0.5f));
    }
    T100FLOAT y = angle - T100_2XPI * quotient;

    T100FLOAT sign;
    if (y > T100_PIDIV2)
    {
        y = T100_PI - y;
        sign = -1.0f;
    }
    else if (y < -T100_PIDIV2)
    {
        y = -T100_PI - y;
        sign = -1.0f;
    }
    else
    {
        sign = +1.0f;
    }

    T100FLOAT y2 = y * y;
    fsin = (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;

    T100FLOAT p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
    fcos = sign * p;
}
