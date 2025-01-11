#include "T1003DEditorPropertiesPanel.h"

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

    wxStringProperty* name = T100NEW wxStringProperty();

    this->Append(name);
}
