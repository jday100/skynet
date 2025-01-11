#include "T1003DEditorEntityPanel.h"

#include "T1003DEditorView.h"
#include "T1003DEditorPropertiesPanel.h"

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
    wxBoxSizer*     note_sizer      = T100NEW wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer*     list_sizer      = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_notebook  = T100NEW wxNotebook(this, wxID_ANY);

    wxPanel*        page        = T100NEW wxPanel(m_notebook);
    wxListCtrl*     listCtrl    = T100NEW wxListCtrl(page, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON);

    list_sizer->Add(listCtrl, 1, wxALL|wxEXPAND, 5);
    page->SetSizer(list_sizer);
    list_sizer->Fit(page);
    list_sizer->SetSizeHints(page);

    m_notebook->AddPage(page, wxT("Entity"));

    note_sizer->Add(m_notebook, 1, wxALL|wxEXPAND, 5);
    SetSizer(note_sizer);

    note_sizer->Fit(this);
    note_sizer->SetSizeHints(this);

    //test
    listCtrl->SetColumnWidth(150, 150);
    listCtrl->InsertItem(0, wxT("dot"));
    listCtrl->InsertItem(0, wxT("line"));
    listCtrl->InsertItem(0, wxT("triangle"));

    listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, (wxObjectEventFunction)&T1003DEditorEntityPanel::OnSelected, T100NULL, this);
}

T100VOID T1003DEditorEntityPanel::destroy()
{

}

T100VOID T1003DEditorEntityPanel::setView(T1003DEditorView* view)
{
    m_view  = view;
}

void T1003DEditorEntityPanel::OnSelected(wxListEvent& event)
{
    m_view->getPropertiesPanel()->update(1);
}
