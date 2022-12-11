#include "T100VPCDiskSetupDialog.h"

#include <wx/intl.h>
#include <wx/string.h>


namespace T100VPC{
const long T100VPCDiskSetupDialog::ID_STATICTEXT_FILE_NAME = wxNewId();
const long T100VPCDiskSetupDialog::ID_TEXTCTRL_FILE_NAME = wxNewId();
const long T100VPCDiskSetupDialog::ID_STATICTEXT_FILE_PATH = wxNewId();
const long T100VPCDiskSetupDialog::ID_COMBOBOX_FILE_PATH = wxNewId();
const long T100VPCDiskSetupDialog::ID_STATICTEXT_FILE_LENGTH = wxNewId();
const long T100VPCDiskSetupDialog::ID_COMBOBOX_FILE_LENGTH = wxNewId();


BEGIN_EVENT_TABLE(T100VPCDiskSetupDialog, wxDialog)

END_EVENT_TABLE()

T100VPCDiskSetupDialog::T100VPCDiskSetupDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	//ctor
    BuildContent(parent,id,pos,size);
}

T100VPCDiskSetupDialog::~T100VPCDiskSetupDialog()
{
    //dtor
}

void T100VPCDiskSetupDialog::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{

	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("文件："));
	FileNameStaticText = new wxStaticText(this, ID_STATICTEXT_FILE_NAME, _("名称："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILE_NAME"));
	StaticBoxSizer1->Add(FileNameStaticText, 0, wxALL|wxALIGN_LEFT, 5);
	FileNameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL_FILE_NAME, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_NAME"));
	StaticBoxSizer1->Add(FileNameTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FilePathStaticText = new wxStaticText(this, ID_STATICTEXT_FILE_PATH, _(" 路径："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILE_PATH"));
	StaticBoxSizer1->Add(FilePathStaticText, 0, wxALL|wxALIGN_LEFT, 5);
	FilePathComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_PATH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_PATH"));
	StaticBoxSizer1->Add(FilePathComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FileLengthStaticText = new wxStaticText(this, ID_STATICTEXT_FILE_LENGTH, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILE_LENGTH"));
	StaticBoxSizer1->Add(FileLengthStaticText, 0, wxALL|wxALIGN_LEFT, 5);
	FileLengthComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_LENGTH"));
	StaticBoxSizer1->Add(FileLengthComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

}

}
