#include "T1003DEditorPropertiesPanel.h"

#include <wx/propgrid/advprops.h>

BEGIN_EVENT_TABLE(T1003DEditorPropertiesPanel, wxPropertyGrid)

END_EVENT_TABLE()

T1003DEditorPropertiesPanel::T1003DEditorPropertiesPanel(wxWindow *parent, wxWindowID id,
                    const wxPoint& pos,
                    const wxSize& size,
                    long style,
                    const wxString& name)
    :wxPropertyGrid(parent, id, pos, size, style, name)
{
    //ctor
}

T1003DEditorPropertiesPanel::~T1003DEditorPropertiesPanel()
{
    //dtor
}

T100VOID T1003DEditorPropertiesPanel::update(T100UINT id)
{
    Clear();

    wxStringProperty* name = T100NEW wxStringProperty(wxT("name"));

    this->Append(name);

    load_dot();
}

T100VOID T1003DEditorPropertiesPanel::load_dot()
{
    Clear();

    wxIntProperty*      row         = T100NEW wxIntProperty(wxT("Row"), wxT("row"), 1);
    wxIntProperty*      column      = T100NEW wxIntProperty(wxT("Column"), wxT("column"), 1);

    wxColourProperty*   colour      = T100NEW wxColourProperty(wxT("Colour"), wxT("colour"));
    wxFileProperty*     file        = T100NEW wxFileProperty(wxT("File"), wxT("file"));

    this->Append(row);
    this->Append(column);
    this->Append(colour);
    this->Append(file);
}

T100VOID T1003DEditorPropertiesPanel::load_line()
{
    Clear();
}

T100VOID T1003DEditorPropertiesPanel::load_triangle()
{
    Clear();
}
