#include "T100ElementCircle.h"

#include "T100Planimetry.h"


namespace T100Painter{

T100ElementCircle::T100ElementCircle()
    :T100ElementBase()
{
    //ctor
    create();
}

T100ElementCircle::~T100ElementCircle()
{
    //dtor
    destroy();
}

T100VOID T100ElementCircle::create()
{
    m_name  = L"Circle";
    m_label = L"Circle";
    m_key   = L"elements.circle";
}

T100VOID T100ElementCircle::destroy()
{

}

T100BOOL T100ElementCircle::draw(wxDC& dc)
{
    dc.DrawCircle(m_origin_x, m_origin_y, m_radius);
}

T100ElementCircle* T100ElementCircle::Clone()
{
    T100ElementCircle*      result          = T100NULL;

    result = T100NEW T100ElementCircle();

    if(result){
        *result = *this;
    }

    return result;
}

T100BOOL T100ElementCircle::MouseLeftDown(T100INT x, T100INT y)
{
    m_origin_x  = x;
    m_origin_y  = y;

    return T100TRUE;
}

T100BOOL T100ElementCircle::MouseLeftUp(T100INT x, T100INT y)
{
    m_target_x  = x;
    m_target_y  = y;

    m_radius    = T100Math::T100Planimetry::Dist(m_origin_x, m_origin_y, m_target_x, m_target_y);

    return T100TRUE;
}

T100BOOL T100ElementCircle::MouseMoving()
{

}

}
