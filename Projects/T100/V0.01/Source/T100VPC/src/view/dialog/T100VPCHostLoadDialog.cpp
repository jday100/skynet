#include "T100VPCHostLoadDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/filedlg.h>


const long T100VPCHostLoadDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCHostLoadDialog::ID_COMBOBOX_FILE = wxNewId();
const long T100VPCHostLoadDialog::ID_BUTTON_BROWSE = wxNewId();
const long T100VPCHostLoadDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCHostLoadDialog::ID_COMBOBOX_LOCATION = wxNewId();
const long T100VPCHostLoadDialog::ID_CHECKBOX_RUN = wxNewId();

BEGIN_EVENT_TABLE(T100VPCHostLoadDialog,wxDialog)

END_EVENT_TABLE()

T100VPCHostLoadDialog::T100VPCHostLoadDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCHostLoadDialog::~T100VPCHostLoadDialog()
{
    //dtor
}

void T100VPCHostLoadDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

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
	ComboBoxFile = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxDefaultPosition, wxSize(400, -1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
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

	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnComboBoxFileSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnComboBoxFileTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnComboBoxFileTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnButtonBrowseClick);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnComboBoxLocationSelected);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnComboBoxLocationTextUpdated);
	Connect(ID_COMBOBOX_LOCATION,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnComboBoxLocationTextEnter);
	Connect(ID_CHECKBOX_RUN,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&T100VPCHostLoadDialog::OnCheckBoxRunClick);

	BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);
}

void T100VPCHostLoadDialog::OnComboBoxFileSelected(wxCommandEvent& event)
{
}

void T100VPCHostLoadDialog::OnComboBoxFileTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostLoadDialog::OnComboBoxFileTextEnter(wxCommandEvent& event)
{
}

void T100VPCHostLoadDialog::OnButtonBrowseClick(wxCommandEvent& event)
{
    wxFileDialog        dialog(this, _("Select a binary file"), "", "", "Executable files (*.bin)|*.bin", wxFD_FILE_MUST_EXIST);

    if(dialog.ShowModal() == wxID_OK){
        ComboBoxFile->SetValue(dialog.GetPath());
    }
}

void T100VPCHostLoadDialog::OnComboBoxLocationSelected(wxCommandEvent& event)
{
}

void T100VPCHostLoadDialog::OnComboBoxLocationTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostLoadDialog::OnComboBoxLocationTextEnter(wxCommandEvent& event)
{
}

void T100VPCHostLoadDialog::OnCheckBoxRunClick(wxCommandEvent& event)
{
}
