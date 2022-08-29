#include "../../../include/vpc/view/T100VPCSetupDialog.h"

//(*InternalHeaders(T100VPCSetupDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "T100VPCSetup.h"


//(*IdInit(T100VPCSetupDialog)
const long T100VPCSetupDialog::ID_STATICBOX1 = wxNewId();
const long T100VPCSetupDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCSetupDialog::ID_COMBOBOX1 = wxNewId();
const long T100VPCSetupDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCSetupDialog::ID_COMBOBOX2 = wxNewId();
const long T100VPCSetupDialog::ID_PANEL1 = wxNewId();
const long T100VPCSetupDialog::ID_STATICBOX2 = wxNewId();
const long T100VPCSetupDialog::ID_STATICTEXT3 = wxNewId();
const long T100VPCSetupDialog::ID_STATICTEXT4 = wxNewId();
const long T100VPCSetupDialog::ID_STATICTEXT5 = wxNewId();
const long T100VPCSetupDialog::ID_COMBOBOX3 = wxNewId();
const long T100VPCSetupDialog::ID_COMBOBOX4 = wxNewId();
const long T100VPCSetupDialog::ID_COMBOBOX5 = wxNewId();
const long T100VPCSetupDialog::ID_PANEL2 = wxNewId();
const long T100VPCSetupDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCSetupDialog,wxDialog)
	//(*EventTable(T100VPCSetupDialog)
	//*)
END_EVENT_TABLE()

T100VPCSetupDialog::T100VPCSetupDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);

	create();

	SetSize(size);
}

void T100VPCSetupDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCSetupDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Memory:"), wxPoint(0,0), wxSize(400,104), 0, _T("ID_STATICBOX1"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8,24), wxSize(384,72), 0, _T("ID_PANEL1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Rom size:"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	RomSizeComboBox = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxPoint(80,8), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Ram size:"), wxPoint(8,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	RamSizeComboBox = new wxComboBox(Panel1, ID_COMBOBOX2, wxEmptyString, wxPoint(80,40), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("File:"), wxPoint(0,112), wxSize(400,144), 0, _T("ID_STATICBOX2"));
	Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(8,136), wxSize(384,112), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Rom file:"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Font file:"), wxPoint(8,40), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("VDisk file:"), wxPoint(8,72), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	RomFileComboBox = new wxComboBox(Panel2, ID_COMBOBOX3, wxEmptyString, wxPoint(80,8), wxSize(296,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	FontFileComboBox = new wxComboBox(Panel2, ID_COMBOBOX4, wxEmptyString, wxPoint(80,40), wxSize(296,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	VDiskFileComboBox = new wxComboBox(Panel2, ID_COMBOBOX5, wxEmptyString, wxPoint(80,72), wxSize(296,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	OKButton = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(160,384), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

	Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDialog::OnRomSizeComboBoxSelected);
	Connect(ID_COMBOBOX1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDialog::OnRomSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX2,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDialog::OnRamSizeComboBoxSelected);
	Connect(ID_COMBOBOX2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDialog::OnRamSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX3,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDialog::OnRomFileComboBoxSelected);
	Connect(ID_COMBOBOX3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDialog::OnRomFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX4,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDialog::OnFontFileComboBoxSelected);
	Connect(ID_COMBOBOX4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDialog::OnFontFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX5,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCSetupDialog::OnVDiskFileComboBoxSelected);
	Connect(ID_COMBOBOX5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCSetupDialog::OnVDiskFileComboBoxTextUpdated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCSetupDialog::OnOKButtonClick);
	//*)
}

T100VPCSetupDialog::~T100VPCSetupDialog()
{
    destroy();

	//(*Destroy(T100VPCSetupDialog)
	//*)
}

T100VOID T100VPCSetupDialog::create()
{
    RomSizeComboBox->SetValue(T100VPCSetup::getRomSize());
    RomSizeComboBox->Append(T100VPCSetup::getRomSize());

    RamSizeComboBox->SetValue(T100VPCSetup::getRamSize());
    RamSizeComboBox->Append(T100VPCSetup::getRamSize());

    RomFileComboBox->SetValue(T100VPCSetup::getRomFile());
    RomFileComboBox->Append(T100VPCSetup::getRomFile());

    FontFileComboBox->SetValue(T100VPCSetup::getFontFile());
    FontFileComboBox->Append(T100VPCSetup::getFontFile());

    VDiskFileComboBox->SetValue(T100VPCSetup::getVDiskFile());
    VDiskFileComboBox->Append(T100VPCSetup::getVDiskFile());
}

T100VOID T100VPCSetupDialog::destroy()
{

}

void T100VPCSetupDialog::OnRomSizeComboBoxSelected(wxCommandEvent& event)
{
    T100VPCSetup::setRomSize(RomSizeComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnRomSizeComboBoxTextUpdated(wxCommandEvent& event)
{
    T100VPCSetup::setRomSize(RomSizeComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnRamSizeComboBoxSelected(wxCommandEvent& event)
{
    T100VPCSetup::setRamSize(RamSizeComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnRamSizeComboBoxTextUpdated(wxCommandEvent& event)
{
    T100VPCSetup::setRamSize(RamSizeComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnRomFileComboBoxSelected(wxCommandEvent& event)
{
    T100VPCSetup::setRomFile(RomFileComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnRomFileComboBoxTextUpdated(wxCommandEvent& event)
{
    T100VPCSetup::setRomFile(RomFileComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnFontFileComboBoxSelected(wxCommandEvent& event)
{
    T100VPCSetup::setFontFile(FontFileComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnFontFileComboBoxTextUpdated(wxCommandEvent& event)
{
    T100VPCSetup::setFontFile(FontFileComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnVDiskFileComboBoxSelected(wxCommandEvent& event)
{
    T100VPCSetup::setVDiskFile(VDiskFileComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnVDiskFileComboBoxTextUpdated(wxCommandEvent& event)
{
    T100VPCSetup::setVDiskFile(VDiskFileComboBox->GetValue().ToStdString());
}

void T100VPCSetupDialog::OnOKButtonClick(wxCommandEvent& event)
{
    Close();
}
