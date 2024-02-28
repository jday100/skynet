#include "T100CreateDialog.h"

//(*InternalHeaders(T100CreateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "wx/filedlg.h"
#include "T100CapacityTools.h"
#include "T100CreateProgressDialog.h"

//(*IdInit(T100CreateDialog)
const long T100CreateDialog::ID_STATICTEXT1 = wxNewId();
const long T100CreateDialog::ID_COMBOBOX_FILE_LENGTH = wxNewId();
const long T100CreateDialog::ID_STATICTEXT2 = wxNewId();
const long T100CreateDialog::ID_TEXTCTRL_FILE_NAME = wxNewId();
const long T100CreateDialog::ID_BUTTON_BROWSE = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON_FILE_TYPE_VHD = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON_FILE_TYPE_VHDX = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON_FILE_STORAGE_FIXED = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON_FILE_STORAGE_DYNAMIC = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100CreateDialog,wxDialog)
	//(*EventTable(T100CreateDialog)
	//*)
END_EVENT_TABLE()

T100CreateDialog::T100CreateDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(T100CreateDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("VHD"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Length:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxFileLength = new wxComboBox(this, ID_COMBOBOX_FILE_LENGTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE_LENGTH"));
	BoxSizer4->Add(ComboBoxFileLength, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("File:"), wxDefaultPosition, wxSize(50,-1), 0, _T("ID_STATICTEXT2"));
	BoxSizer5->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlFileName = new wxTextCtrl(this, ID_TEXTCTRL_FILE_NAME, wxEmptyString, wxDefaultPosition, wxSize(300,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_NAME"));
	BoxSizer5->Add(TextCtrlFileName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonFileBrowse = new wxButton(this, ID_BUTTON_BROWSE, _("Browse..."), wxDefaultPosition, wxSize(80,25), 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	BoxSizer5->Add(ButtonFileBrowse, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Type:"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	RadioButtonFileTypeVHD = new wxRadioButton(this, ID_RADIOBUTTON_FILE_TYPE_VHD, _("VHD"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON_FILE_TYPE_VHD"));
	BoxSizer2->Add(RadioButtonFileTypeVHD, 0, wxALIGN_LEFT, 0);
	RadioButtonFileTypeVHDX = new wxRadioButton(this, ID_RADIOBUTTON_FILE_TYPE_VHDX, _("VHDX"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON_FILE_TYPE_VHDX"));
	BoxSizer2->Add(RadioButtonFileTypeVHDX, 0, wxALIGN_LEFT, 0);
	StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Storage:"));
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	RadioButtonFileStorageFixed = new wxRadioButton(this, ID_RADIOBUTTON_FILE_STORAGE_FIXED, _("Fixed"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON_FILE_STORAGE_FIXED"));
	BoxSizer3->Add(RadioButtonFileStorageFixed, 1, wxALL|wxALIGN_LEFT, 5);
	RadioButtonFileStorageDynamic = new wxRadioButton(this, ID_RADIOBUTTON_FILE_STORAGE_DYNAMIC, _("Dynamic"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON_FILE_STORAGE_DYNAMIC"));
	BoxSizer3->Add(RadioButtonFileStorageDynamic, 1, wxALL|wxALIGN_LEFT, 5);
	StaticBoxSizer3->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(StaticBoxSizer1);
	StaticBoxSizer1->Fit(this);
	StaticBoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_COMBOBOX_FILE_LENGTH,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100CreateDialog::OnComboBoxFileLengthSelected);
	Connect(ID_COMBOBOX_FILE_LENGTH,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100CreateDialog::OnComboBoxFileLengthTextUpdated);
	Connect(ID_COMBOBOX_FILE_LENGTH,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100CreateDialog::OnComboBoxFileLengthTextEnter);
	Connect(ID_TEXTCTRL_FILE_NAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100CreateDialog::OnTextCtrlFileNameText);
	Connect(ID_TEXTCTRL_FILE_NAME,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100CreateDialog::OnTextCtrlFileNameTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100CreateDialog::OnButtonFileBrowseClick);
	Connect(ID_RADIOBUTTON_FILE_TYPE_VHD,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100CreateDialog::OnRadioButtonFileTypeVHDSelect);
	Connect(ID_RADIOBUTTON_FILE_TYPE_VHDX,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100CreateDialog::OnRadioButtonFileTypeVHDXSelect);
	Connect(ID_RADIOBUTTON_FILE_STORAGE_FIXED,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100CreateDialog::OnRadioButtonFileStorageFixedSelect);
	Connect(ID_RADIOBUTTON_FILE_STORAGE_DYNAMIC,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100CreateDialog::OnRadioButtonFileStorageDynamicSelect);
	//*)


	BoxSizer1->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCLOSE),
                   wxSizerFlags().Right().Border());

    Connect(wxID_APPLY,     wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100CreateDialog::OnButtonApplyClick);

    create();
}

T100CreateDialog::~T100CreateDialog()
{
	//(*Destroy(T100CreateDialog)
	//*)

	destroy();
}

T100VOID T100CreateDialog::create()
{
    wxArrayString       options;


    options.push_back(wxT("4M"));
    options.push_back(wxT("512M"));
    options.push_back(wxT("1G"));
    options.push_back(wxT("4G"));
    options.push_back(wxT("20G"));
    options.push_back(wxT("50G"));

    ComboBoxFileLength->Append(options);

    m_type      = T100VDISK_TYPE_VHD;
    m_storage   = T100VDISK_STORAGE_TYPE_FIXED;

}

T100VOID T100CreateDialog::destroy()
{

}

void T100CreateDialog::OnButtonApplyClick(wxCommandEvent& event)
{
    T100CreateProgressDialog    dialog(this);

    dialog.m_filename   = m_filename;
    dialog.m_length     = m_length;
    dialog.m_type       = m_type;
    dialog.m_storage    = m_storage;

    long    id;

    id  = dialog.ShowModal();

    if(wxID_CANCEL == id){

    }else if(wxID_OK == id){


    }
}


void T100CreateDialog::OnButtonFileBrowseClick(wxCommandEvent& event)
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return;

    TextCtrlFileName->SetValue(dialog.GetPath());
}

void T100CreateDialog::OnRadioButtonFileTypeVHDSelect(wxCommandEvent& event)
{
    m_type      = T100VDISK_TYPE_VHD;
}

void T100CreateDialog::OnRadioButtonFileTypeVHDXSelect(wxCommandEvent& event)
{
    m_type      = T100VDISK_TYPE_VHDX;
}

void T100CreateDialog::OnRadioButtonFileStorageFixedSelect(wxCommandEvent& event)
{
    m_storage   = T100VDISK_STORAGE_TYPE_FIXED;
}

void T100CreateDialog::OnRadioButtonFileStorageDynamicSelect(wxCommandEvent& event)
{
    m_storage   = T100VDISK_STORAGE_TYPE_DYNAMIC;
}

void T100CreateDialog::OnComboBoxFileLengthSelected(wxCommandEvent& event)
{
}

void T100CreateDialog::OnComboBoxFileLengthTextUpdated(wxCommandEvent& event)
{
    m_length    = T100CapacityTools::parse(ComboBoxFileLength->GetValue().ToStdString());
}

void T100CreateDialog::OnComboBoxFileLengthTextEnter(wxCommandEvent& event)
{
}

void T100CreateDialog::OnTextCtrlFileNameText(wxCommandEvent& event)
{
    m_filename  = TextCtrlFileName->GetValue().ToStdString();
}

void T100CreateDialog::OnTextCtrlFileNameTextEnter(wxCommandEvent& event)
{
}
