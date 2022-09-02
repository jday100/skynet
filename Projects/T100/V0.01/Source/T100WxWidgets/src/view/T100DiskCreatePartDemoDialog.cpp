#include "../../include/view/T100DiskCreatePartDemoDialog.h"

//(*InternalHeaders(T100DiskCreatePartDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100DiskCreatePartDemoDialog)
const long T100DiskCreatePartDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_TEXTCTRL_NAME = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_COMBOBOX_LOCATION = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_STATICTEXT3 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_COMBOBOX_LENGTH = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_CHECKBOX_BOOT = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_STATICTEXT4 = wxNewId();
const long T100DiskCreatePartDemoDialog::ID_COMBOBOX_TYPE = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiskCreatePartDemoDialog,wxDialog)
	//(*EventTable(T100DiskCreatePartDemoDialog)
	//*)
END_EVENT_TABLE()

T100DiskCreatePartDemoDialog::T100DiskCreatePartDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DiskCreatePartDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DiskCreatePartDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("新建分区："));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("名称："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL_NAME, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_NAME"));
	FlexGridSizer1->Add(NameTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("起始："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LocationComboBox = new wxComboBox(this, ID_COMBOBOX_LOCATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LOCATION"));
	FlexGridSizer1->Add(LocationComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("大小："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LengthComboBox = new wxComboBox(this, ID_COMBOBOX_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_LENGTH"));
	FlexGridSizer1->Add(LengthComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BootCheckBox = new wxCheckBox(this, ID_CHECKBOX_BOOT, _("启动"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_BOOT"));
	BootCheckBox->SetValue(false);
	StaticBoxSizer1->Add(BootCheckBox, 0, wxALL|wxALIGN_LEFT, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("类型："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer2->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TypeComboBox = new wxComboBox(this, ID_COMBOBOX_TYPE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_TYPE"));
	BoxSizer2->Add(TypeComboBox, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL_NAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnNameTextCtrlText);
	Connect(ID_TEXTCTRL_NAME,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnNameTextCtrlTextEnter);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnLocationComboBoxSelected);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnLocationComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnLocationComboBoxTextEnter);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnLengthComboBoxSelected);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnLengthComboBoxTextEnter);
	Connect(ID_CHECKBOX_BOOT,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnBootCheckBoxClick);
	Connect(ID_COMBOBOX_TYPE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnTypeComboBoxSelected);
	Connect(ID_COMBOBOX_TYPE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnTypeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_TYPE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskCreatePartDemoDialog::OnTypeComboBoxTextEnter);
	//*)
}

T100DiskCreatePartDemoDialog::~T100DiskCreatePartDemoDialog()
{
	//(*Destroy(T100DiskCreatePartDemoDialog)
	//*)
}


void T100DiskCreatePartDemoDialog::OnNameTextCtrlText(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnNameTextCtrlTextEnter(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnLocationComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnLocationComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnLocationComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnLengthComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnBootCheckBoxClick(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnTypeComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnTypeComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskCreatePartDemoDialog::OnTypeComboBoxTextEnter(wxCommandEvent& event)
{
}
