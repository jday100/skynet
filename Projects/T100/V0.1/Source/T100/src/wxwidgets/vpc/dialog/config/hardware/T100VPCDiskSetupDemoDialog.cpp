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
const long T100VPCDiskSetupDemoDialog::ID_BUTTON1 = wxNewId();
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
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("文件："));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("名称："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	FileNameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL_FILE_NAME, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_NAME"));
	StaticBoxSizer1->Add(FileNameTextCtrl, 1, wxALL|wxALIGN_LEFT, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _(" 路径："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	FilePathComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_PATH, wxEmptyString, wxDefaultPosition, wxSize(300,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_PATH"));
	BoxSizer2->Add(FilePathComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer1->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
	FileLengthComboBox = new wxComboBox(this, ID_COMBOBOX_FILE_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_LENGTH"));
	StaticBoxSizer1->Add(FileLengthComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL_FILE_NAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFileNameTextCtrlText);
	Connect(ID_TEXTCTRL_FILE_NAME,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFileNameTextCtrlTextEnter);
	Connect(ID_COMBOBOX_FILE_PATH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFilePathComboBoxSelected);
	Connect(ID_COMBOBOX_FILE_PATH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFilePathComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE_PATH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFilePathComboBoxTextEnter);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnButton1Click);
	Connect(ID_COMBOBOX_FILE_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFileLengthComboBoxSelected);
	Connect(ID_COMBOBOX_FILE_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFileLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDiskSetupDemoDialog::OnFileLengthComboBoxTextEnter);
	//*)
}

T100VPCDiskSetupDemoDialog::~T100VPCDiskSetupDemoDialog()
{
	//(*Destroy(T100VPCDiskSetupDemoDialog)
	//*)
}


void T100VPCDiskSetupDemoDialog::OnFileNameTextCtrlText(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFileNameTextCtrlTextEnter(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFilePathComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFilePathComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFilePathComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFileLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFileLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnFileLengthComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDiskSetupDemoDialog::OnButton1Click(wxCommandEvent& event)
{
}
