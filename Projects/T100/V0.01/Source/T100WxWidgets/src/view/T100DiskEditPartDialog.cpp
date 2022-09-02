#include "T100DiskEditPartDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

const long T100DiskEditPartDialog::ID_STATICTEXT1 = wxNewId();
const long T100DiskEditPartDialog::ID_TEXTCTRL_NAME = wxNewId();
const long T100DiskEditPartDialog::ID_STATICTEXT2 = wxNewId();
const long T100DiskEditPartDialog::ID_COMBOBOX_LOCATION = wxNewId();
const long T100DiskEditPartDialog::ID_STATICTEXT3 = wxNewId();
const long T100DiskEditPartDialog::ID_COMBOBOX_LENGTH = wxNewId();
const long T100DiskEditPartDialog::ID_CHECKBOX_BOOT = wxNewId();
const long T100DiskEditPartDialog::ID_STATICTEXT4 = wxNewId();
const long T100DiskEditPartDialog::ID_COMBOBOX_TYPE = wxNewId();

BEGIN_EVENT_TABLE(T100DiskEditPartDialog,wxDialog)

END_EVENT_TABLE()

T100DiskEditPartDialog::T100DiskEditPartDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
    create();
}

T100DiskEditPartDialog::~T100DiskEditPartDialog()
{
    //dtor
    destroy();
}

void T100DiskEditPartDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("编辑分区："));
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

	Connect(ID_TEXTCTRL_NAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnNameTextCtrlText);
	Connect(ID_TEXTCTRL_NAME,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskEditPartDialog::OnNameTextCtrlTextEnter);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnLocationComboBoxSelected);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnLocationComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskEditPartDialog::OnLocationComboBoxTextEnter);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnLengthComboBoxSelected);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnLengthComboBoxTextUpdated);
	Connect(ID_COMBOBOX_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskEditPartDialog::OnLengthComboBoxTextEnter);
	Connect(ID_CHECKBOX_BOOT,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnBootCheckBoxClick);
	Connect(ID_COMBOBOX_TYPE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnTypeComboBoxSelected);
	Connect(ID_COMBOBOX_TYPE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100DiskEditPartDialog::OnTypeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_TYPE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100DiskEditPartDialog::OnTypeComboBoxTextEnter);

    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);

}

T100VOID T100DiskEditPartDialog::create()
{
    TypeComboBox->Append(_("default"));
}

T100VOID T100DiskEditPartDialog::destroy()
{

}

void T100DiskEditPartDialog::OnNameTextCtrlText(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnNameTextCtrlTextEnter(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnLocationComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnLocationComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnLocationComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnLengthComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnLengthComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnLengthComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnBootCheckBoxClick(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnTypeComboBoxSelected(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnTypeComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100DiskEditPartDialog::OnTypeComboBoxTextEnter(wxCommandEvent& event)
{
}
