#include "../../../include/view/dialog/T100VPCHostRunDemoDialog.h"

//(*InternalHeaders(T100VPCHostRunDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCHostRunDemoDialog)
const long T100VPCHostRunDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCHostRunDemoDialog::ID_COMBOBOX_BASE = wxNewId();
const long T100VPCHostRunDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCHostRunDemoDialog::ID_COMBOBOX_OFFSET = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHostRunDemoDialog,wxDialog)
	//(*EventTable(T100VPCHostRunDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCHostRunDemoDialog::T100VPCHostRunDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHostRunDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHostRunDemoDialog)
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

	Connect(ID_COMBOBOX_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostRunDemoDialog::OnComboBoxBaseSelected);
	Connect(ID_COMBOBOX_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostRunDemoDialog::OnComboBoxBaseTextUpdated);
	Connect(ID_COMBOBOX_BASE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostRunDemoDialog::OnComboBoxBaseTextEnter);
	Connect(ID_COMBOBOX_OFFSET,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCHostRunDemoDialog::OnComboBoxOffsetSelected);
	Connect(ID_COMBOBOX_OFFSET,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCHostRunDemoDialog::OnComboBoxOffsetTextUpdated);
	Connect(ID_COMBOBOX_OFFSET,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCHostRunDemoDialog::OnComboBoxOffsetTextEnter);
	//*)
}

T100VPCHostRunDemoDialog::~T100VPCHostRunDemoDialog()
{
	//(*Destroy(T100VPCHostRunDemoDialog)
	//*)
}


void T100VPCHostRunDemoDialog::OnComboBoxBaseSelected(wxCommandEvent& event)
{
}

void T100VPCHostRunDemoDialog::OnComboBoxBaseTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostRunDemoDialog::OnComboBoxBaseTextEnter(wxCommandEvent& event)
{
}

void T100VPCHostRunDemoDialog::OnComboBoxOffsetSelected(wxCommandEvent& event)
{
}

void T100VPCHostRunDemoDialog::OnComboBoxOffsetTextUpdated(wxCommandEvent& event)
{
}

void T100VPCHostRunDemoDialog::OnComboBoxOffsetTextEnter(wxCommandEvent& event)
{
}
