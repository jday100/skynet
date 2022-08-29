#include "../../../include/view/dialog/T100VPCDebugDemoDialog.h"

//(*InternalHeaders(T100VPCDebugDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDebugDemoDialog)
const long T100VPCDebugDemoDialog::ID_STATICTEXT1 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX3 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT2 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX1 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT3 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX2 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT4 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX4 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT5 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX5 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT6 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX10 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT7 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX6 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT8 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX7 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT9 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX8 = wxNewId();
const long T100VPCDebugDemoDialog::ID_STATICTEXT10 = wxNewId();
const long T100VPCDebugDemoDialog::ID_COMBOBOX9 = wxNewId();
const long T100VPCDebugDemoDialog::ID_LISTCTRL1 = wxNewId();
const long T100VPCDebugDemoDialog::ID_SCROLLBAR1 = wxNewId();
const long T100VPCDebugDemoDialog::ID_LISTCTRL2 = wxNewId();
const long T100VPCDebugDemoDialog::ID_SCROLLBAR2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCDebugDemoDialog,wxDialog)
	//(*EventTable(T100VPCDebugDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCDebugDemoDialog::T100VPCDebugDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDebugDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDebugDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("CPU："));
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("CU："));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox3 = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	FlexGridSizer1->Add(ComboBox3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	FlexGridSizer1->Add(ComboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(FlexGridSizer1, 1, wxALL|wxALIGN_TOP, 5);
	StaticBoxSizer1->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("AU："));
	FlexGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox4 = new wxComboBox(this, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	FlexGridSizer2->Add(ComboBox4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox5 = new wxComboBox(this, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	FlexGridSizer2->Add(ComboBox5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox10 = new wxComboBox(this, ID_COMBOBOX10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX10"));
	FlexGridSizer2->Add(ComboBox10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox6 = new wxComboBox(this, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	FlexGridSizer2->Add(ComboBox6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox7 = new wxComboBox(this, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	FlexGridSizer2->Add(ComboBox7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox8 = new wxComboBox(this, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX8"));
	FlexGridSizer2->Add(ComboBox8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox9 = new wxComboBox(this, ID_COMBOBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX9"));
	FlexGridSizer2->Add(ComboBox9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("内存："));
	ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL1"));
	StaticBoxSizer2->Add(ListCtrl1, 1, wxALL|wxEXPAND, 5);
	ScrollBar1 = new wxScrollBar(this, ID_SCROLLBAR1, wxDefaultPosition, wxSize(18,102), wxBORDER_SIMPLE, wxDefaultValidator, _T("ID_SCROLLBAR1"));
	ScrollBar1->SetScrollbar(0, 1, 10, 1);
	StaticBoxSizer2->Add(ScrollBar1, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("端口："));
	ListCtrl2 = new wxListCtrl(this, ID_LISTCTRL2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL2"));
	StaticBoxSizer3->Add(ListCtrl2, 1, wxALL|wxEXPAND, 5);
	ScrollBar2 = new wxScrollBar(this, ID_SCROLLBAR2, wxDefaultPosition, wxSize(25,174), wxBORDER_SIMPLE, wxDefaultValidator, _T("ID_SCROLLBAR2"));
	ScrollBar2->SetScrollbar(0, 1, 10, 1);
	StaticBoxSizer3->Add(ScrollBar2, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer3, 1, wxALL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCDebugDemoDialog::~T100VPCDebugDemoDialog()
{
	//(*Destroy(T100VPCDebugDemoDialog)
	//*)
}

