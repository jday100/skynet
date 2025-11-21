#include "T1003DEditorConfigDialog.h"

#include <wx/listctrl.h>

#include "T1003DEditorConfigPanel.h"

const long T1003DEditorConfigDialog::ID_LISTBOOK = wxNewId();

BEGIN_EVENT_TABLE(T1003DEditorConfigDialog,wxDialog)

END_EVENT_TABLE()

T1003DEditorConfigDialog::T1003DEditorConfigDialog(wxWindow *parent,
             wxWindowID id,
             const wxString& title,
             const wxPoint& pos,
             const wxSize& size,
             long style,
             const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    init();
}

T1003DEditorConfigDialog::~T1003DEditorConfigDialog()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorConfigDialog::init()
{
	m_sizer     = new wxBoxSizer(wxHORIZONTAL);
	m_listbook  = new wxListbook(this, ID_LISTBOOK, wxDefaultPosition, wxDefaultSize, 0, _T("ID_LISTBOOK"));

	m_sizer->Add(m_listbook, 1, wxALL|wxEXPAND, 5);
	SetSizer(m_sizer);
	Layout();
    SetSize(1280, 700);
    Center();

    m_listbook->GetListView()->SetColumnWidth(0, 200);


    T1003DEditorConfigPanel*        configPanel         = T100NEW T1003DEditorConfigPanel(m_listbook);

    m_listbook->AddPage(configPanel, _("Config"), false);
}

T100VOID T1003DEditorConfigDialog::uninit()
{

}
