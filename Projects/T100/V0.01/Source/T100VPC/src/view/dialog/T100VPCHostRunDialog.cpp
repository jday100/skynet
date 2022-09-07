#include "T100VPCHostRunDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

const long T100VPCHostRunDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCHostRunDialog::ID_COMBOBOX_BASE = wxNewId();
const long T100VPCHostRunDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCHostRunDialog::ID_COMBOBOX_OFFSET = wxNewId();

BEGIN_EVENT_TABLE(T100VPCHostRunDialog,wxDialog)

END_EVENT_TABLE()

T100VPCHostRunDialog::T100VPCHostRunDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCHostRunDialog::~T100VPCHostRunDialog()
{
    //dtor
}

void T100VPCHostRunDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("运行："));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Base："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxBase = new wxComboBox(this, ID_COMBOBOX_BASE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_BASE"));
	FlexGridSizer1->Add(ComboBoxBase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Offset："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxOffset = new wxComboBox(this, ID_COMBOBOX_OFFSET, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_OFFSET"));
	FlexGridSizer1->Add(ComboBoxOffset, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostRunDialog::OnComboBoxBaseSelected);
	Connect(ID_COMBOBOX_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostRunDialog::OnComboBoxBaseTextUpdated);
	Connect(ID_COMBOBOX_BASE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostRunDialog::OnComboBoxBaseTextEnter);
	Connect(ID_COMBOBOX_OFFSET,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostRunDialog::OnComboBoxOffsetSelected);
	Connect(ID_COMBOBOX_OFFSET,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostRunDialog::OnComboBoxOffsetTextUpdated);
	Connect(ID_COMBOBOX_OFFSET,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostRunDialog::OnComboBoxOffsetTextEnter);

    BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                   wxSizerFlags().Right().Border());

    SetSizerAndFit(BoxSizer1);
}

void T100VPCHostRunDialog::OnComboBoxBaseSelected(wxCommandEvent& event)
{
}

void T100VPCHostRunDialog::OnComboBoxBaseTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostRunDialog::OnComboBoxBaseTextEnter(wxCommandEvent& event)
{
}

void T100VPCHostRunDialog::OnComboBoxOffsetSelected(wxCommandEvent& event)
{
}

void T100VPCHostRunDialog::OnComboBoxOffsetTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostRunDialog::OnComboBoxOffsetTextEnter(wxCommandEvent& event)
{
}
