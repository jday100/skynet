#include "T100RenderBase.h"

T100RenderBase::T100RenderBase()
{
    //ctor
}

T100RenderBase::~T100RenderBase()
{
    //dtor
}

T100VOID T100RenderBase::SetOrigin(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_origin.m_x    = x;
    m_origin.m_y    = y;
    m_origin.m_z    = z;

    m_view_origin_x = x;
    m_view_origin_y = y;
}
