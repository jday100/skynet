#include "T100Matrix4.h"

#include <string.h>

T100Matrix4::T100Matrix4()
{
    //ctor
    TurnOn();
}

T100Matrix4::~T100Matrix4()
{
    //dtor
    TurnOff();
}

T100VOID T100Matrix4::TurnOn()
{
    memset(&DATA, 0, sizeof(T100MATRIX4));
}

T100VOID T100Matrix4::TurnOff()
{

}

T100Matrix4 operator*(const T100Matrix4& mat1, const T100Matrix4& mat2)
{
    T100Matrix4         result;

    result.DATA.DATA4[0][0] = mat1.DATA.DATA4[0][0] * mat2.DATA.DATA4[0][0]
                            + mat1.DATA.DATA4[0][1] * mat2.DATA.DATA4[1][0]
                            + mat1.DATA.DATA4[0][2] * mat2.DATA.DATA4[2][0]
                            + mat1.DATA.DATA4[0][3] * mat2.DATA.DATA4[3][0];

    result.DATA.DATA4[0][1] = mat1.DATA.DATA4[0][0] * mat2.DATA.DATA4[0][1]
                            + mat1.DATA.DATA4[0][1] * mat2.DATA.DATA4[1][1]
                            + mat1.DATA.DATA4[0][2] * mat2.DATA.DATA4[2][1]
                            + mat1.DATA.DATA4[0][3] * mat2.DATA.DATA4[3][1];

    result.DATA.DATA4[0][2] = mat1.DATA.DATA4[0][0] * mat2.DATA.DATA4[0][2]
                            + mat1.DATA.DATA4[0][1] * mat2.DATA.DATA4[1][2]
                            + mat1.DATA.DATA4[0][2] * mat2.DATA.DATA4[2][2]
                            + mat1.DATA.DATA4[0][3] * mat2.DATA.DATA4[3][2];

    result.DATA.DATA4[0][3] = mat1.DATA.DATA4[0][0] * mat2.DATA.DATA4[0][3]
                            + mat1.DATA.DATA4[0][1] * mat2.DATA.DATA4[1][3]
                            + mat1.DATA.DATA4[0][2] * mat2.DATA.DATA4[2][3]
                            + mat1.DATA.DATA4[0][3] * mat2.DATA.DATA4[3][3];

    result.DATA.DATA4[1][0] = mat1.DATA.DATA4[1][0] * mat2.DATA.DATA4[0][0]
                            + mat1.DATA.DATA4[1][1] * mat2.DATA.DATA4[1][0]
                            + mat1.DATA.DATA4[1][2] * mat2.DATA.DATA4[2][0]
                            + mat1.DATA.DATA4[1][3] * mat2.DATA.DATA4[3][0];

    result.DATA.DATA4[1][1] = mat1.DATA.DATA4[1][0] * mat2.DATA.DATA4[0][1]
                            + mat1.DATA.DATA4[1][1] * mat2.DATA.DATA4[1][1]
                            + mat1.DATA.DATA4[1][2] * mat2.DATA.DATA4[2][1]
                            + mat1.DATA.DATA4[1][3] * mat2.DATA.DATA4[3][1];

    result.DATA.DATA4[1][2] = mat1.DATA.DATA4[1][0] * mat2.DATA.DATA4[0][2]
                            + mat1.DATA.DATA4[1][1] * mat2.DATA.DATA4[1][2]
                            + mat1.DATA.DATA4[1][2] * mat2.DATA.DATA4[2][2]
                            + mat1.DATA.DATA4[1][3] * mat2.DATA.DATA4[3][2];

    result.DATA.DATA4[1][3] = mat1.DATA.DATA4[1][0] * mat2.DATA.DATA4[0][3]
                            + mat1.DATA.DATA4[1][1] * mat2.DATA.DATA4[1][3]
                            + mat1.DATA.DATA4[1][2] * mat2.DATA.DATA4[2][3]
                            + mat1.DATA.DATA4[1][3] * mat2.DATA.DATA4[3][3];

    result.DATA.DATA4[2][0] = mat1.DATA.DATA4[2][0] * mat2.DATA.DATA4[0][0]
                            + mat1.DATA.DATA4[2][1] * mat2.DATA.DATA4[1][0]
                            + mat1.DATA.DATA4[2][2] * mat2.DATA.DATA4[2][0]
                            + mat1.DATA.DATA4[2][3] * mat2.DATA.DATA4[3][0];

    result.DATA.DATA4[2][1] = mat1.DATA.DATA4[2][0] * mat2.DATA.DATA4[0][1]
                            + mat1.DATA.DATA4[2][1] * mat2.DATA.DATA4[1][1]
                            + mat1.DATA.DATA4[2][2] * mat2.DATA.DATA4[2][1]
                            + mat1.DATA.DATA4[2][3] * mat2.DATA.DATA4[3][1];

    result.DATA.DATA4[2][2] = mat1.DATA.DATA4[2][0] * mat2.DATA.DATA4[0][2]
                            + mat1.DATA.DATA4[2][1] * mat2.DATA.DATA4[1][2]
                            + mat1.DATA.DATA4[2][2] * mat2.DATA.DATA4[2][2]
                            + mat1.DATA.DATA4[2][3] * mat2.DATA.DATA4[3][2];

    result.DATA.DATA4[2][3] = mat1.DATA.DATA4[2][0] * mat2.DATA.DATA4[0][3]
                            + mat1.DATA.DATA4[2][1] * mat2.DATA.DATA4[1][3]
                            + mat1.DATA.DATA4[2][2] * mat2.DATA.DATA4[2][3]
                            + mat1.DATA.DATA4[2][3] * mat2.DATA.DATA4[3][3];

    result.DATA.DATA4[3][0] = mat1.DATA.DATA4[3][0] * mat2.DATA.DATA4[0][0]
                            + mat1.DATA.DATA4[3][1] * mat2.DATA.DATA4[1][0]
                            + mat1.DATA.DATA4[3][2] * mat2.DATA.DATA4[2][0]
                            + mat1.DATA.DATA4[3][3] * mat2.DATA.DATA4[3][0];

    result.DATA.DATA4[3][1] = mat1.DATA.DATA4[3][0] * mat2.DATA.DATA4[0][1]
                            + mat1.DATA.DATA4[3][1] * mat2.DATA.DATA4[1][1]
                            + mat1.DATA.DATA4[3][2] * mat2.DATA.DATA4[2][1]
                            + mat1.DATA.DATA4[3][3] * mat2.DATA.DATA4[3][1];

    result.DATA.DATA4[3][2] = mat1.DATA.DATA4[3][0] * mat2.DATA.DATA4[0][2]
                            + mat1.DATA.DATA4[3][1] * mat2.DATA.DATA4[1][2]
                            + mat1.DATA.DATA4[3][2] * mat2.DATA.DATA4[2][2]
                            + mat1.DATA.DATA4[3][3] * mat2.DATA.DATA4[3][2];

    result.DATA.DATA4[3][3] = mat1.DATA.DATA4[3][0] * mat2.DATA.DATA4[0][3]
                            + mat1.DATA.DATA4[3][1] * mat2.DATA.DATA4[1][3]
                            + mat1.DATA.DATA4[3][2] * mat2.DATA.DATA4[2][3]
                            + mat1.DATA.DATA4[3][3] * mat2.DATA.DATA4[3][3];

    return result;
}
