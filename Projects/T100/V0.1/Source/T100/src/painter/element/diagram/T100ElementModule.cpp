#include "T100ElementModule.h"

#include "T100Planimetry.h"
#include "T100ElementCommon.h"

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
    dc.DrawRectangle(m_starting_x, m_starting_y, m_ending_x - m_starting_x, m_ending_y - m_starting_y);

    wxString name = m_name.to_wstring();

    dc.DrawText(name, m_starting_x, m_starting_y);
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
    return T100Math::T100Planimetry::Hit(m_starting_x, m_starting_y, m_ending_x, m_ending_y, x, y);
}

T100BOOL T100ElementModule::MouseLeftDown(T100INT x, T100INT y)
{
    m_starting_x    = x;
    m_starting_y    = y;

    m_ending_x      = m_starting_x + 50;
    m_ending_y      = m_starting_y + 100;

    return T100TRUE;
}

T100BOOL T100ElementModule::MouseLeftUp(T100INT x, T100INT y)
{
    return T100TRUE;
}

T100BOOL T100ElementModule::MouseMove(T100INT x, T100INT y)
{
    return T100TRUE;
}

T100BOOL T100ElementModule::Update(wxPropertyGrid* panel)
{
    panel->Clear();

    panel->Append(T100NEW wxStringProperty(wxT("Name"), wxT("Name"), m_name.to_wstring()));

    panel->Append(T100NEW wxIntProperty(wxT("X"), wxPG_LABEL, m_starting_x));
    panel->Append(T100NEW wxIntProperty(wxT("Y"), wxPG_LABEL, m_starting_y));

    return T100TRUE;
}

T100BOOL T100ElementModule::Update(wxPropertyGridEvent& event)
{
    T100INT     i;


    i = event.GetColumn();

    i = event.GetId();

    i = event.GetInt();

    i = event.GetSelection();


    switch(event.GetSelection()){
    case 0:
        {
            m_name = event.GetPropertyValue().GetString().ToStdWstring();
        }
        break;
    case 1:
        {
            m_name = event.GetPropertyValue().GetString().ToStdWstring();
        }
        break;
    }
}

}
