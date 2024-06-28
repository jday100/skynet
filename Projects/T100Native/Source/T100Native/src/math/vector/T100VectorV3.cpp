#include "T100VectorV3.h"

T100VectorV3::T100VectorV3()
{
    //ctor
}

T100VectorV3::~T100VectorV3()
{
    //dtor
}

T100BOOL T100VectorV3::operator==(const T100VectorV3& vec)
{

}

T100BOOL T100VectorV3::operator!=(const T100VectorV3& vec)
{

}

T100VectorV3& T100VectorV3::operator=(const T100VectorV3& vec)
{
    this->m_x   = vec.m_x;
    this->m_y   = vec.m_y;
    this->m_z   = vec.m_z;
    return *this;
}

T100VectorV3& operator+(const T100VectorV3& vec, const T100FLOAT& value)
{

}
