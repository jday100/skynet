#include "T100Point.h"

T100Point::T100Point()
    :T100VectorV3()
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
