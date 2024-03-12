#include "T100ElementCircle.h"

#include "T100Planimetry.h"
#include "T100ElementCommon.h"

#include "T100TestTools.h"


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
    m_panel = L"Graphic";
    m_key   = L"elements.circle";
    m_type  = T100ELEMENT_GRAPHICS_CIRCLE;
}

T100VOID T100ElementCircle::destroy()
{

}

T100VOID T100ElementCircle::Clear()
{
    m_origin_x  = 0;
    m_origin_y  = 0;
    m_radius    = 0;
}

T100BOOL T100ElementCircle::draw(wxDC& dc)
{
    dc.DrawCircle(m_origin_x, m_origin_y, m_radius);
    return T100TRUE;
}

T100ElementCircle* T100ElementCircle::Clone()
{
    T100ElementCircle*      result          = T100NULL;

    result = T100NEW T100ElementCircle();

    if(result){
        result->m_origin_x  = m_origin_x;
        result->m_origin_y  = m_origin_y;
        result->m_radius    = m_radius;
    }

    return result;
}

T100BOOL T100ElementCircle::Hit(T100INT x, T100INT y)
{
    T100FLOAT   result;

    result = T100Math::T100Planimetry::Dist(m_origin_x, m_origin_y, x, y);

    if(result <= m_radius){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ElementCircle::Edit()
{

}

T100BOOL T100ElementCircle::PaintMove(T100INT x, T100INT y)
{
    m_target_x  = x;
    m_target_y  = y;

    m_radius    = T100Math::T100Planimetry::Dist(m_origin_x, m_origin_y, m_target_x, m_target_y);

    return T100TRUE;
}

T100BOOL T100ElementCircle::SelectedMove(T100INT x, T100INT y)
{
    T100INT     dx, dy;

    dx  = x - m_starting_x;
    dy  = y - m_starting_y;

    m_origin_x  += dx;
    m_origin_y  += dy;

    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

T100BOOL T100ElementCircle::Update(wxPropertyGrid* panel)
{
    panel->Clear();

    panel->Append(T100NEW wxIntProperty(wxT("X"), wxPG_LABEL, m_origin_x));
    panel->Append(T100NEW wxIntProperty(wxT("Y"), wxPG_LABEL, m_origin_y));

    panel->Append(T100NEW wxFloatProperty(wxT("Radius"), wxPG_LABEL, m_radius));

    return T100TRUE;
}

T100BOOL T100ElementCircle::SetPaintStarting(T100INT x, T100INT y)
{
    m_origin_x      = x;
    m_origin_y      = y;

    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

}
