#include "../../../include/view/frame/T100VPCDebugDemoFrame.h"

//(*InternalHeaders(T100VPCDebugDemoFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDebugDemoFrame)
const long T100VPCDebugDemoFrame::ID_STATICTEXT1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT3 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX3 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT4 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX4 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT5 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX5 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT6 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX6 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT7 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX7 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT8 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX8 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT9 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX9 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT10 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX10 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX11 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX12 = wxNewId();
const long T100VPCDebugDemoFrame::ID_LISTVIEW1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_SCROLLBAR1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX13 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX14 = wxNewId();
const long T100VPCDebugDemoFrame::ID_LISTVIEW2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_SCROLLBAR2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON3 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON4 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON5 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON6 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCDebugDemoFrame,wxFrame)
	//(*EventTable(T100VPCDebugDemoFrame)
	//*)
END_EVENT_TABLE()

T100VPCDebugDemoFrame::T100VPCDebugDemoFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDebugDemoFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDebugDemoFrame)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("CPU："));
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("CU："));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("COR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("CBR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	FlexGridSizer1->Add(ComboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CCR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox3 = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	FlexGridSizer1->Add(ComboBox3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(FlexGridSizer1, 1, wxALL|wxALIGN_TOP, 5);
	StaticBoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("AU："));
	FlexGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("AAR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox4 = new wxComboBox(this, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	FlexGridSizer2->Add(ComboBox4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("ACF："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox5 = new wxComboBox(this, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	FlexGridSizer2->Add(ComboBox5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("ABR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox6 = new wxComboBox(this, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	FlexGridSizer2->Add(ComboBox6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("AMF："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox7 = new wxComboBox(this, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	FlexGridSizer2->Add(ComboBox7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("ACR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox8 = new wxComboBox(this, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX8"));
	FlexGridSizer2->Add(ComboBox8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("AOF："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox9 = new wxComboBox(this, ID_COMBOBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX9"));
	FlexGridSizer2->Add(ComboBox9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("ADR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox10 = new wxComboBox(this, ID_COMBOBOX10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX10"));
	FlexGridSizer2->Add(ComboBox10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Memory："));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ComboBox11 = new wxComboBox(this, ID_COMBOBOX11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX11"));
	BoxSizer3->Add(ComboBox11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox12 = new wxComboBox(this, ID_COMBOBOX12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX12"));
	BoxSizer3->Add(ComboBox12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	ScrollBar1 = new wxScrollBar(this, ID_SCROLLBAR1, wxDefaultPosition, wxSize(20,17), 0, wxDefaultValidator, _T("ID_SCROLLBAR1"));
	ScrollBar1->SetScrollbar(0, 1, 10, 1);
	BoxSizer2->Add(ScrollBar1, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, this, _("Port："));
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	ComboBox13 = new wxComboBox(this, ID_COMBOBOX13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX13"));
	BoxSizer4->Add(ComboBox13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox14 = new wxComboBox(this, ID_COMBOBOX14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX14"));
	BoxSizer4->Add(ComboBox14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	ListView2 = new wxListView(this, ID_LISTVIEW2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW2"));
	BoxSizer5->Add(ListView2, 1, wxALL|wxEXPAND, 5);
	ScrollBar2 = new wxScrollBar(this, ID_SCROLLBAR2, wxDefaultPosition, wxSize(20,119), 0, wxDefaultValidator, _T("ID_SCROLLBAR2"));
	ScrollBar2->SetScrollbar(0, 1, 10, 1);
	BoxSizer5->Add(ScrollBar2, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer5->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Step"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer6->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("Next"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer6->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("Call"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer6->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button5 = new wxButton(this, ID_BUTTON5, _("Return"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer6->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button6 = new wxButton(this, ID_BUTTON6, _("Pause"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer6->Add(Button6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCDebugDemoFrame::~T100VPCDebugDemoFrame()
{
	//(*Destroy(T100VPCDebugDemoFrame)
	//*)
}

