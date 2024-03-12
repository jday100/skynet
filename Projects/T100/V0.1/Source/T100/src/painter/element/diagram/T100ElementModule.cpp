#include "T100ElementModule.h"

#include "T100Planimetry.h"
#include "T100ElementCommon.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"

namespace T100Painter{

T100ElementModule::T100ElementModule()
{
    //ctor
    create();
}

T100ElementModule::~T100ElementModule()
{
    //dtor
    destroy();
}

T100VOID T100ElementModule::create()
{
    m_name  = L"Module";
    m_label = L"Module";
    m_panel = L"Diagram";
    m_key   = L"elements.module";
    m_type  = T100ELEMENT_DIAGRAM_MODULE;

    m_width     = 50;
    m_height    = 100;
}

T100VOID T100ElementModule::destroy()
{

}

T100VOID T100ElementModule::Clear()
{
    m_starting_x    = 0;
    m_starting_y    = 0;

    m_ending_x      = 0;
    m_ending_y      = 0;
}

T100BOOL T100ElementModule::draw(wxDC& dc)
{
    T100INT     w, h;

    Resize(dc);

    dc.DrawRectangle(m_origin_x, m_origin_y, m_width, m_height);

    wxString name = m_name.to_wstring();

    dc.DrawText(name, m_name_x, m_name_y);

    T100PainterCallback::getView()->getPaintCtrl()->GetVirtualSize(&w, &h);

    if(m_tail_x > w || m_tail_y > h){
        //T100PainterCallback::getView()->getPaintCtrl()->Resize(m_tail_x, m_tail_y);
    }

    return T100TRUE;
}

T100ElementModule* T100ElementModule::Clone()
{
    T100ElementModule*      result          = T100NULL;

    result = T100NEW T100ElementModule();

    if(result){
        *result = *this;
    }

    return result;
}

T100BOOL T100ElementModule::Hit(T100INT x, T100INT y)
{
    return T100Math::T100Planimetry::Hit(m_origin_x, m_origin_y, m_tail_x, m_tail_y, x, y);
}

T100BOOL T100ElementModule::Edit()
{

}

T100BOOL T100ElementModule::PaintMove(T100INT x, T100INT y)
{
    return T100TRUE;
}

T100BOOL T100ElementModule::SelectedMove(T100INT x, T100INT y)
{
    T100INT     dx, dy;

    dx  = x - m_starting_x;
    dy  = y - m_starting_y;

    m_origin_x  += dx;
    m_origin_y  += dy;

    m_tail_x    = m_origin_x + m_width;
    m_tail_y    = m_origin_y + m_height;

    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

T100BOOL T100ElementModule::Update(wxPropertyGrid* panel)
{
    T100WORD        index       = 1;

    panel->Clear();

    if(!m_inited){
        m_pg_name   = T100NEW wxStringProperty(wxT("Name"), wxPG_LABEL, m_name.to_wstring());
        m_properties[L"Name"] = index++;

        m_pg_x      = T100NEW wxIntProperty(wxT("X"), wxPG_LABEL, m_origin_x);
        m_properties[L"X"] = index++;

        m_pg_y      = T100NEW wxIntProperty(wxT("Y"), wxPG_LABEL, m_origin_y);
        m_properties[L"Y"] = index++;

        //m_inited = T100TRUE;
    }

    panel->Append(m_pg_name);
    panel->Append(m_pg_x);
    panel->Append(m_pg_y);

    return T100TRUE;
}

T100BOOL T100ElementModule::Update(wxPropertyGridEvent& event)
{
    T100WORD        index           = 0;

    index   = m_properties[event.GetPropertyName().ToStdWstring()];

    switch(index){
    case 1:
        {
            m_name  = m_pg_name->GetValueAsString().ToStdWstring();
        }
        break;
    case 2:
        {
            m_origin_x  = m_pg_x->GetValue().GetInteger();
        }
        break;
    case 3:
        {
            m_origin_y  = m_pg_y->GetValue().GetInteger();
        }
        break;
    default:
        return T100FALSE;
    }
    return T100TRUE;
}

T100VOID T100ElementModule::Resize(wxDC& dc)
{
    wxCoord     x, y;

    dc.GetMultiLineTextExtent(m_name.to_wstring(), &x, &y);

    m_width     = x > m_width ? x : m_width;
    m_height    = y > m_height ? y : m_height;

    m_name_x    = (m_width - x) / 2 + m_origin_x;
    m_name_y    = (m_height - y) / 2 + m_origin_y;

    m_tail_x    = m_origin_x + m_width;
    m_tail_y    = m_origin_y + m_height;
}

T100BOOL T100ElementModule::SetPaintStarting(T100INT x, T100INT y)
{
    m_starting_x    = x;
    m_starting_y    = y;

    Position();
    return T100TRUE;
}

}
