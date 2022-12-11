#include "../../../../../../include/wxwidgets/vpc/dialog/config/hardware/T100VPCDiskSetupDemoDialog.h"

//(*InternalHeaders(T100VPCDiskSetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDiskSetupDemoDialog)
const long T100VPCDiskSetupDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCDiskSetupDemoDialog::ID_TEXTCTRL_FILE_NAME = wxNewId();
const long T100VPCDiskSetupDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCDiskSetupDemoDialog::ID_COMBOBOX_FILE_PATH = wxNewId();
const long T100VPCDiskSetupDemoDialog::ID_STATICTEXT3 = wxNewId();
const long T100VPCDiskSetupDemoDialog::ID_COMBOBOX_FILE_LENGTH = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCDiskSetupDemoDialog,wxDialog)
	//(*EventTable(T100VPCDiskSetupDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCDiskSetupDemoDialog::T100VPCDiskSetupDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDiskSetupDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDiskSetupDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("文件："));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("名称："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	FileNameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL_FILE_NAME, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_NAME"));
	StaticBoxSizer1->Add(FileNameTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _(" 路径："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	FilePathComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_PATH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_PATH"));
	StaticBoxSizer1->Add(FilePathComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer1->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
	FileLengthComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_LENGTH"));
	StaticBoxSizer1->Add(FileLengthComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCDiskSetupDemoDialog::~T100VPCDiskSetupDemoDialog()
{
	//(*Destroy(T100VPCDiskSetupDemoDialog)
	//*)
}

