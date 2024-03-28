#include "T100ElementCircle.h"

T100ElementCircle::T100ElementCircle()
    :T100ElementBase()
{
    //ctor
}

T100ElementCircle::~T100ElementCircle()
{
    //dtor
}

T100BOOL T100ElementCircle::Draw(wxDC& dc)
{
    dc.DrawCircle(m_origin_x, m_origin_y, m_radius);
    return T100TRUE;
}
