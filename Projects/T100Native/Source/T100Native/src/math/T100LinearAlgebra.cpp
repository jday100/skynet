#include "T100LinearAlgebra.h"

#include "T100Matrix3.h"
#include "T100Matrix4.h"
#include "T100VectorV3.h"
#include "T100VectorH4.h"

T100LinearAlgebra::T100LinearAlgebra()
{
    //ctor
}

T100LinearAlgebra::~T100LinearAlgebra()
{
    //dtor
}

T100VectorV3& operator*(const T100VectorV3& vec, const T100Matrix3& matrix)
{

}

T100VectorV4& operator*(const T100VectorV4& vec, const T100Matrix4& matrix)
{

}

T100VectorH4& operator*(const T100VectorH4& vec, const T100Matrix4& matrix)
{
    T100VectorH4        result;

    result.m_x  = vec.m_x * matrix.DATA.DATA4[0][0] + vec.m_x * matrix.DATA.DATA4[1][0] + vec.m_x * matrix.DATA.DATA4[2][0] + vec.m_x * matrix.DATA.DATA4[3][0];
    result.m_y  = vec.m_y * matrix.DATA.DATA4[0][1] + vec.m_y * matrix.DATA.DATA4[1][1] + vec.m_y * matrix.DATA.DATA4[2][1] + vec.m_y * matrix.DATA.DATA4[3][1];
    result.m_z  = vec.m_z * matrix.DATA.DATA4[0][2] + vec.m_z * matrix.DATA.DATA4[1][2] + vec.m_z * matrix.DATA.DATA4[2][2] + vec.m_z * matrix.DATA.DATA4[3][2];
    result.m_w  = vec.m_w * matrix.DATA.DATA4[0][3] + vec.m_w * matrix.DATA.DATA4[1][3] + vec.m_w * matrix.DATA.DATA4[2][3] + vec.m_w * matrix.DATA.DATA4[3][3];

    return result;
}
