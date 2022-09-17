#include "../../include/view/T100DiskBrowsePartDemoDialog.h"

//(*InternalHeaders(T100DiskBrowsePartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskBrowsePartDemoDialog)
const long T100DiskBrowsePartDemoDialog::ID_GENERICDIRCTRL1 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_GENERICDIRCTRL2 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_MENUITEM2 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_MENUITEM3 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_MENUITEM1 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_MENUITEM5 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_MENUITEM6 = wxNewId();
const long T100DiskBrowsePartDemoDialog::ID_MENUITEM4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiskBrowsePartDemoDialog,wxDialog)
	//(*EventTable(T100DiskBrowsePartDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskBrowsePartDemoDialog::T100DiskBrowsePartDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskBrowsePartDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskBrowsePartDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(800,600));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	GenericDirCtrl1 = new wxGenericDirCtrl(this, ID_GENERICDIRCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString, 0, _T("ID_GENERICDIRCTRL1"));
	BoxSizer3->Add(GenericDirCtrl1, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	GenericDirCtrl2 = new wxGenericDirCtrl(this, ID_GENERICDIRCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString, 0, _T("ID_GENERICDIRCTRL2"));
	BoxSizer4->Add(GenericDirCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenu();
	MenuItem2 = new wxMenuItem(MenuItem1, ID_MENUITEM2, _("Create"), wxEmptyString, wxITEM_NORMAL);
	MenuItem1->Append(MenuItem2);
	MenuItem3 = new wxMenuItem(MenuItem1, ID_MENUITEM3, _("Remove"), wxEmptyString, wxITEM_NORMAL);
	MenuItem1->Append(MenuItem3);
	Menu1.Append(ID_MENUITEM1, _("Folder"), MenuItem1, wxEmptyString);
	MenuItem4 = new wxMenu();
	MenuItem5 = new wxMenuItem(MenuItem4, ID_MENUITEM5, _("Copy"), wxEmptyString, wxITEM_NORMAL);
	MenuItem4->Append(MenuItem5);
	MenuItem6 = new wxMenuItem(MenuItem4, ID_MENUITEM6, _("Remove"), wxEmptyString, wxITEM_NORMAL);
	MenuItem4->Append(MenuItem6);
	Menu1.Append(ID_MENUITEM4, _("File"), MenuItem4, wxEmptyString);
	SetSizer(BoxSizer1);
	Layout();
	//*)
}

T100DiskBrowsePartDemoDialog::~T100DiskBrowsePartDemoDialog()
{
	//(*Destroy(T100DiskBrowsePartDemoDialog)
	//*)
}

