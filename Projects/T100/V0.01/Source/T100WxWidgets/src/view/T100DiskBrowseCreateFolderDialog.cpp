#include "T100DiskBrowseCreateFolderDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

const long T100DiskBrowseCreateFolderDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskBrowseCreateFolderDialog::ID_TEXTCTRL_FOLDER = wxNewId();

BEGIN_EVENT_TABLE(T100DiskBrowseCreateFolderDialog,wxDialog)

END_EVENT_TABLE()

T100DiskBrowseCreateFolderDialog::T100DiskBrowseCreateFolderDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100DiskBrowseCreateFolderDialog::~T100DiskBrowseCreateFolderDialog()
{
    //dtor
}

void T100DiskBrowseCreateFolderDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

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

    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);

}
