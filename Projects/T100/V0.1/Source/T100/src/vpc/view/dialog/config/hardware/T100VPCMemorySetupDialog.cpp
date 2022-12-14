#include "T100VPCMemorySetupDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "T100MemoryInfo.h"

namespace T100VPC{

const long T100VPCMemorySetupDialog::ID_STATICTEXT_ROM_BASE = wxNewId();
const long T100VPCMemorySetupDialog::ID_STATICTEXT_ROM_SIZE = wxNewId();
const long T100VPCMemorySetupDialog::ID_STATICTEXT_RAM_BASE = wxNewId();
const long T100VPCMemorySetupDialog::ID_STATICTEXT_RAM_SIZE = wxNewId();
const long T100VPCMemorySetupDialog::ID_COMBOBOX_ROM_BASE = wxNewId();
const long T100VPCMemorySetupDialog::ID_COMBOBOX_ROM_SIZE = wxNewId();
const long T100VPCMemorySetupDialog::ID_COMBOBOX_RAM_BASE = wxNewId();
const long T100VPCMemorySetupDialog::ID_COMBOBOX_RAM_SIZE = wxNewId();

BEGIN_EVENT_TABLE(T100VPCMemorySetupDialog, wxDialog)

END_EVENT_TABLE()

T100VPCMemorySetupDialog::T100VPCMemorySetupDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCMemorySetupDialog::~T100VPCMemorySetupDialog()
{
    //dtor
}

void T100VPCMemorySetupDialog::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{

	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);

	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("ROM："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT_ROM_BASE, _("BASE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_ROM_BASE"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	RomBaseComboBox = new wxComboBox(this, ID_COMBOBOX_ROM_BASE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ROM_BASE"));
	StaticBoxSizer1->Add(RomBaseComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT_ROM_SIZE, _("SIZE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_ROM_SIZE"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	RomSizeComboBox = new wxComboBox(this, ID_COMBOBOX_ROM_SIZE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ROM_SIZE"));
	StaticBoxSizer1->Add(RomSizeComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);

	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("RAM："));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT_RAM_BASE, _("BASE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_RAM_BASE"));
	StaticBoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	RamBaseComboBox = new wxComboBox(this, ID_COMBOBOX_RAM_BASE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_RAM_BASE"));
	StaticBoxSizer2->Add(RamBaseComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT_RAM_SIZE, _("SIZE："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_RAM_SIZE"));
	StaticBoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	RamSizeComboBox = new wxComboBox(this, ID_COMBOBOX_RAM_SIZE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_RAM_SIZE"));
	StaticBoxSizer2->Add(RamSizeComboBox, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);

    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);

	Connect(ID_COMBOBOX_ROM_BASE,   wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRomBaseComboBoxSelected);
	Connect(ID_COMBOBOX_ROM_BASE,   wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRomBaseComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ROM_BASE,   wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRomBaseComboBoxTextEnter);
	Connect(ID_COMBOBOX_ROM_SIZE,   wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRomSizeComboBoxSelected);
	Connect(ID_COMBOBOX_ROM_SIZE,   wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRomSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ROM_SIZE,   wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRomSizeComboBoxTextEnter);
	Connect(ID_COMBOBOX_RAM_BASE,   wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRamBaseComboBoxSelected);
	Connect(ID_COMBOBOX_RAM_BASE,   wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRamBaseComboBoxTextUpdated);
	Connect(ID_COMBOBOX_RAM_BASE,   wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRamBaseComboBoxTextEnter);
    Connect(ID_COMBOBOX_RAM_SIZE,   wxEVT_COMMAND_COMBOBOX_SELECTED,    (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRamSizeComboBoxSelected);
	Connect(ID_COMBOBOX_RAM_SIZE,   wxEVT_COMMAND_TEXT_UPDATED,         (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRamSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_RAM_SIZE,   wxEVT_COMMAND_TEXT_ENTER,           (wxObjectEventFunction)&T100VPCMemorySetupDialog::OnRamSizeComboBoxTextEnter);
}

T100VOID T100VPCMemorySetupDialog::setInfo(T100MemoryInfo* info)
{
    m_info = info;

    load();
}

T100VOID T100VPCMemorySetupDialog::load()
{
    if(m_info){
        RomBaseComboBox->SetValue(std::to_string(m_info->m_rom_base));
        RomSizeComboBox->SetValue(std::to_string(m_info->m_rom_size));
        RamBaseComboBox->SetValue(std::to_string(m_info->m_ram_base));
        RamSizeComboBox->SetValue(std::to_string(m_info->m_ram_size));
    }
}

void T100VPCMemorySetupDialog::OnRomBaseComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RomBaseComboBox->GetValue().ToLongLong(&value)){
            m_info->m_rom_base = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRomBaseComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RomBaseComboBox->GetValue().ToLongLong(&value)){
            m_info->m_rom_base = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRomBaseComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RomBaseComboBox->GetValue().ToLongLong(&value)){
            m_info->m_rom_base = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRomSizeComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RomSizeComboBox->GetValue().ToLongLong(&value)){
            m_info->m_rom_size = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRomSizeComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RomSizeComboBox->GetValue().ToLongLong(&value)){
            m_info->m_rom_size = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRomSizeComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RomSizeComboBox->GetValue().ToLongLong(&value)){
            m_info->m_rom_size = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRamBaseComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RamBaseComboBox->GetValue().ToLongLong(&value)){
            m_info->m_ram_base = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRamBaseComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RamBaseComboBox->GetValue().ToLongLong(&value)){
            m_info->m_ram_base = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRamBaseComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RamBaseComboBox->GetValue().ToLongLong(&value)){
            m_info->m_ram_base = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRamSizeComboBoxSelected(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RamSizeComboBox->GetValue().ToLongLong(&value)){
            m_info->m_ram_size = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRamSizeComboBoxTextUpdated(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RamSizeComboBox->GetValue().ToLongLong(&value)){
            m_info->m_ram_size = value;
        }
    }
}

void T100VPCMemorySetupDialog::OnRamSizeComboBoxTextEnter(wxCommandEvent& event)
{
    if(m_info){
        T100LONG        value;

        if(RamSizeComboBox->GetValue().ToLongLong(&value)){
            m_info->m_ram_size = value;
        }
    }
}

}
