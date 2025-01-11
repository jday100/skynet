#include "T1003DEditorEntityPanel.h"

BEGIN_EVENT_TABLE(T1003DEditorEntityPanel, wxPanel)

END_EVENT_TABLE()

T1003DEditorEntityPanel::T1003DEditorEntityPanel(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxString& name)
    :wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
}

T1003DEditorEntityPanel::~T1003DEditorEntityPanel()
{
    //dtor
}
