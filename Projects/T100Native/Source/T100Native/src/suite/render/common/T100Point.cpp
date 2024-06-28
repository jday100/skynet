#include "T100Point.h"

T100Point::T100Point()
{
    //ctor
}

T100Point::~T100Point()
{
    //dtor
}

T100VOID T100Point::SetValue(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_x     = x;
    m_y     = y;
    m_z     = z;
}

T100Point& T100Point::operator=(const T100VectorV3& vec)
{
    this->m_x   = vec.m_x;
    this->m_y   = vec.m_y;
    this->m_z   = vec.m_z;
    return *this;
}

T100Point operator*(const T100Matrix4& matrix, const T100Point& dot)
{
    T100Point       result;

    result.m_x  = matrix.DATA.DATA4[0][0] * dot.m_x + matrix.DATA.DATA4[1][0] * dot.m_y + matrix.DATA.DATA4[2][0] * dot.m_z + matrix.DATA.DATA4[3][0];
    result.m_y  = matrix.DATA.DATA4[0][1] * dot.m_x + matrix.DATA.DATA4[1][1] * dot.m_y + matrix.DATA.DATA4[2][1] * dot.m_z + matrix.DATA.DATA4[3][1];
    result.m_z  = matrix.DATA.DATA4[0][2] * dot.m_x + matrix.DATA.DATA4[1][2] * dot.m_y + matrix.DATA.DATA4[2][2] * dot.m_z + matrix.DATA.DATA4[3][2];

    return result;
}
