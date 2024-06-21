#include "T100VectorV4.h"

T100VectorV4::T100VectorV4()
{
    //ctor
}

T100VectorV4::~T100VectorV4()
{
    //dtor
}

T100BOOL T100VectorV4::operator==(const T100VectorV4& vec)
{
    return (this->m_x == vec.m_x && this->m_y == vec.m_y && this->m_z == vec.m_z && this->m_w == vec.m_w);
}

T100BOOL T100VectorV4::operator!=(const T100VectorV4& vec)
{
    return !(*this == vec);
}

T100VectorV4& T100VectorV4::operator=(const T100VectorV4& vec)
{
    this->m_x   = vec.m_x;
    this->m_y   = vec.m_y;
    this->m_z   = vec.m_z;
    this->m_w   = vec.m_w;
    return *this;
}

T100VectorV4& T100VectorV4::operator+(const T100VectorV4& vec)
{
    T100VectorV4        result;

    result.m_x  = this->m_x + vec.m_x;
    result.m_y  = this->m_y + vec.m_y;
    result.m_z  = this->m_z + vec.m_z;
    result.m_w  = this->m_w + vec.m_w;

    return result;
}

T100VectorV4& T100VectorV4::operator-(const T100VectorV4& vec)
{
    T100VectorV4        result;

    result.m_x  = this->m_x - vec.m_x;
    result.m_y  = this->m_y - vec.m_y;
    result.m_z  = this->m_z - vec.m_z;
    result.m_w  = this->m_w - vec.m_w;

    return result;
}

T100VectorV4& T100VectorV4::operator*(const T100VectorV4& vec)
{
    T100VectorV4        result;

    result.m_x  = this->m_x - vec.m_x;
    result.m_y  = this->m_y - vec.m_y;
    result.m_z  = this->m_z - vec.m_z;
    result.m_w  = this->m_w - vec.m_w;

    return result;
}

T100VectorV4& T100VectorV4::operator/(const T100VectorV4& vec)
{
    T100VectorV4        result;

    result.m_x  = this->m_x - vec.m_x;
    result.m_y  = this->m_y - vec.m_y;
    result.m_z  = this->m_z - vec.m_z;
    result.m_w  = this->m_w - vec.m_w;

    return result;
}
