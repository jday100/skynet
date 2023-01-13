#include "T100ElementText.h"

#include "T100Planimetry.h"
#include "T100ElementCommon.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"

namespace T100Painter{

T100ElementText::T100ElementText()
{
    //ctor
    create();
}

T100ElementText::~T100ElementText()
{
    //dtor
    destroy();
}

T100VOID T100ElementText::create()
{
    m_name  = L"Text";
    m_label = L"Text";
    m_panel = L"Other";
    m_key   = L"elements.text";
    m_type  = T100ELEMENT_TEXT;

    m_width     = 100;
    m_height    = 50;
}

T100VOID T100ElementText::destroy()
{

}

T100VOID T100ElementText::Clear()
{
    m_starting_x    = 0;
    m_starting_y    = 0;

    m_ending_x      = 0;
    m_ending_y      = 0;
}

T100BOOL T100ElementText::draw(wxDC& dc)
{
    T100INT     w, h;

    Resize(dc);

    dc.DrawRectangle(m_origin_x, m_origin_y, m_width, m_height);

    wxString name = m_name.to_wstring();

    dc.DrawText(name, m_name_x, m_name_y);

    T100PainterCallback::getView()->getPaintCtrl()->GetVirtualSize(&w, &h);

    if(m_tail_x > w || m_tail_y > h){
        T100PainterCallback::getView()->getPaintCtrl()->Resize(m_tail_x, m_tail_y);
    }
}

T100ElementText* T100ElementText::Clone()
{
    T100ElementText*        result          = T100NULL;

    result = T100NEW T100ElementText();

    if(result){
        *result = *this;
    }

    return result;
}

T100BOOL T100ElementText::Hit(T100INT x, T100INT y)
{
    return T100Math::T100Planimetry::Hit(m_origin_x, m_origin_y, m_tail_x, m_tail_y, x, y);
}

T100BOOL T100ElementText::PaintMove(T100INT x, T100INT y)
{
    return T100TRUE;
}

T100BOOL T100ElementText::SelectedMove(T100INT x, T100INT y)
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

T100BOOL T100ElementText::Update(wxPropertyGrid* panel)
{
    panel->Clear();

    if(!m_inited){
        m_pg_name = T100NEW wxLongStringProperty(wxT("Text"), wxPG_LABEL);
        //m_inited = T100TRUE;
    }

    panel->Append(m_pg_name);

    return T100TRUE;
}

T100BOOL T100ElementText::Update(wxPropertyGridEvent& event)
{
    m_name = event.GetPropertyValue().GetString().ToStdWstring();
    return T100TRUE;
}

T100VOID T100ElementText::Resize(wxDC& dc)
{
    wxCoord     x, y;

    dc.GetTextExtent(m_name.to_wstring(), &x, &y);

    m_width     = x > m_width ? x : m_width;
    m_height    = y > m_height ? y : m_height;

    m_name_x    = (m_width - x) / 2 + m_origin_x;
    m_name_y    = (m_height - y) / 2 + m_origin_y;

    m_tail_x    = m_origin_x + m_width;
    m_tail_y    = m_origin_y + m_height;
}

T100BOOL T100ElementText::SetPaintStarting(T100INT x, T100INT y)
{
    m_starting_x    = x;
    m_starting_y    = y;

    Position();
    return T100TRUE;
}

}
