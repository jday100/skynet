#include "../../../include/view/dialog/T100VPCHostLoadDemoDialog.h"

//(*InternalHeaders(T100VPCHostLoadDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCHostLoadDemoDialog)
const long T100VPCHostLoadDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCHostLoadDemoDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100VPCHostLoadDemoDialog::ID_BUTTON_BROWSE = wxNewId();
const long T100VPCHostLoadDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCHostLoadDemoDialog::ID_COMBOBOX_LOCATION = wxNewId();
const long T100VPCHostLoadDemoDialog::ID_CHECKBOX_RUN = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHostLoadDemoDialog,wxDialog)
	//(*EventTable(T100VPCHostLoadDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCHostLoadDemoDialog::T100VPCHostLoadDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHostLoadDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHostLoadDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("加载："));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("文件："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxFile = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	BoxSizer2->Add(ComboBoxFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonBrowse = new wxButton(this, ID_BUTTON_BROWSE, _("浏览…"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	BoxSizer2->Add(ButtonBrowse, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("定位："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxLocation = new wxComboBox(this, ID_COMBOBOX_LOCATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LOCATION"));
	BoxSizer3->Add(ComboBoxLocation, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	CheckBoxRun = new wxCheckBox(this, ID_CHECKBOX_RUN, _("立即运行"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_RUN"));
	CheckBoxRun->SetValue(false);
	BoxSizer4->Add(CheckBoxRun, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnComboBoxFileSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnComboBoxFileTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnComboBoxFileTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnButtonBrowseClick);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnComboBoxLocationSelected);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnComboBoxLocationTextUpdated);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnComboBoxLocationTextEnter);
	Connect(ID_CHECKBOX_RUN,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&T100VPCHostLoadDemoDialog::OnCheckBoxRunClick);
	//*)
}

T100VPCHostLoadDemoDialog::~T100VPCHostLoadDemoDialog()
{
	//(*Destroy(T100VPCHostLoadDemoDialog)
	//*)
}


void T100VPCHostLoadDemoDialog::OnComboBoxFileSelected(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnComboBoxFileTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnComboBoxFileTextEnter(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnButtonBrowseClick(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnComboBoxLocationSelected(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnComboBoxLocationTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnComboBoxLocationTextEnter(wxCommandEvent& event)
{
}

void T100VPCHostLoadDemoDialog::OnCheckBoxRunClick(wxCommandEvent& event)
{
}
