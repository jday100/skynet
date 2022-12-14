#include "../../../../../../include/wxwidgets/vpc/dialog/config/hardware/T100VPCDisplaySetupDemoDialog.h"

//(*InternalHeaders(T100VPCDisplaySetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDisplaySetupDemoDialog)
const long T100VPCDisplaySetupDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCDisplaySetupDemoDialog::ID_COMBOBOX1 = wxNewId();
const long T100VPCDisplaySetupDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCDisplaySetupDemoDialog::ID_COMBOBOX2 = wxNewId();
const long T100VPCDisplaySetupDemoDialog::ID_STATICTEXT3 = wxNewId();
const long T100VPCDisplaySetupDemoDialog::ID_COMBOBOX3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCDisplaySetupDemoDialog,wxDialog)
	//(*EventTable(T100VPCDisplaySetupDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCDisplaySetupDemoDialog::T100VPCDisplaySetupDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDisplaySetupDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDisplaySetupDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Label"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	StaticBoxSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_LEFT, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	StaticBoxSizer1->Add(ComboBox2, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Label"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer2->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
	ComboBox3 = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxSize(300,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	StaticBoxSizer2->Add(ComboBox3, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCDisplaySetupDemoDialog::~T100VPCDisplaySetupDemoDialog()
{
	//(*Destroy(T100VPCDisplaySetupDemoDialog)
	//*)
}

