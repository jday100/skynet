#include "../../include/view/T100DiskBrowseCreateFolderDemoDialog.h"

//(*InternalHeaders(T100DiskBrowseCreateFolderDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskBrowseCreateFolderDemoDialog)
const long T100DiskBrowseCreateFolderDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskBrowseCreateFolderDemoDialog::ID_TEXTCTRL_FOLDER = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiskBrowseCreateFolderDemoDialog,wxDialog)
	//(*EventTable(T100DiskBrowseCreateFolderDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskBrowseCreateFolderDemoDialog::T100DiskBrowseCreateFolderDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskBrowseCreateFolderDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskBrowseCreateFolderDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("新建目录："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("目录名："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FolderTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL_FOLDER, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_FOLDER"));
	StaticBoxSizer1->Add(FolderTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100DiskBrowseCreateFolderDemoDialog::~T100DiskBrowseCreateFolderDemoDialog()
{
	//(*Destroy(T100DiskBrowseCreateFolderDemoDialog)
	//*)
}

