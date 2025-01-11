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
    create();
}

T1003DEditorEntityPanel::~T1003DEditorEntityPanel()
{
    //dtor
    destroy();
}

T100VOID T1003DEditorEntityPanel::create()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_notebook  = T100NEW wxNotebook(this, wxID_ANY);

    wxPanel*        page        = T100NEW wxPanel(m_notebook);
    wxListCtrl*     listCtrl    = T100NEW wxListCtrl(page);

    m_notebook->AddPage(page, wxT("Entity"));

    sizer->Add(m_notebook, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(sizer);

    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T1003DEditorEntityPanel::destroy()
{

}
