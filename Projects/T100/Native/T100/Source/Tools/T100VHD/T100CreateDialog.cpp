#include "T100CreateDialog.h"

//(*InternalHeaders(T100CreateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VDisk.h"

//(*IdInit(T100CreateDialog)
const long T100CreateDialog::ID_STATICTEXT1 = wxNewId();
const long T100CreateDialog::ID_COMBOBOX1 = wxNewId();
const long T100CreateDialog::ID_STATICTEXT2 = wxNewId();
const long T100CreateDialog::ID_TEXTCTRL1 = wxNewId();
const long T100CreateDialog::ID_BUTTON1 = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON1 = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON2 = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON3 = wxNewId();
const long T100CreateDialog::ID_RADIOBUTTON4 = wxNewId();
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
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxStaticBoxSizer* StaticBoxSizer7;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("File:"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	BoxSizer2->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("VHD"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	BoxSizer3->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("VHDX"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	BoxSizer3->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	RadioButton3 = new wxRadioButton(this, ID_RADIOBUTTON3, _("固定大小"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
	BoxSizer4->Add(RadioButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton4 = new wxRadioButton(this, ID_RADIOBUTTON4, _("动态扩展"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
	BoxSizer4->Add(RadioButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer1->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer1->Add(StaticBoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer1->Add(StaticBoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)


	BoxSizer1->Add(CreateStdDialogButtonSizer(wxAPPLY | wxCLOSE),
                   wxSizerFlags().Right().Border());

    Connect(wxID_APPLY,     wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100CreateDialog::OnButtonApplyClick);
}

T100CreateDialog::~T100CreateDialog()
{
	//(*Destroy(T100CreateDialog)
	//*)
}

void T100CreateDialog::OnButtonApplyClick(wxCommandEvent& event)
{
    T100STRING                  name;
    T100INT64                   length;
    T100VDISK_TYPE              vdisk;
    T100VDISK_STORAGE_TYPE      type;

    name    = "temp.vhd";
    length  = 1024 * 1024 * 1024;
    vdisk   = T100VDISK_TYPE_VHD;
    type    = T100VDISK_STORAGE_TYPE_FIXED;

    T100VDisk           disk(name, length);

    disk.create(vdisk, type);
}

