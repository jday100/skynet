#include "../../include/wx/T100DebugFrame.h"

//(*InternalHeaders(T100DebugFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VM.h"

//(*IdInit(T100DebugFrame)
const long T100DebugFrame::ID_STATICTEXT1 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX1 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT2 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX2 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT3 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX3 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT4 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX4 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT5 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX5 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT6 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX6 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT7 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX7 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT8 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX8 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT9 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX9 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT10 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX10 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT11 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX11 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT12 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX12 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT13 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX13 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT14 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX14 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT15 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX15 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT16 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX16 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT17 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX17 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT18 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX18 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT19 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX19 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT20 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX20 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT21 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX21 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT22 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX22 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT23 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX23 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT24 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX24 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT25 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX25 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT26 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX26 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT27 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX27 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT28 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX28 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT29 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX29 = wxNewId();
const long T100DebugFrame::ID_STATICTEXT30 = wxNewId();
const long T100DebugFrame::ID_COMBOBOX30 = wxNewId();
const long T100DebugFrame::ID_BUTTON_RUN = wxNewId();
const long T100DebugFrame::ID_BUTTON2 = wxNewId();
const long T100DebugFrame::ID_BUTTON_STEP_IN = wxNewId();
const long T100DebugFrame::ID_BUTTON4 = wxNewId();
const long T100DebugFrame::ID_BUTTON5 = wxNewId();
const long T100DebugFrame::ID_BUTTON6 = wxNewId();
const long T100DebugFrame::ID_BUTTON7 = wxNewId();
const long T100DebugFrame::ID_BUTTON8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DebugFrame,wxFrame)
	//(*EventTable(T100DebugFrame)
	//*)
END_EVENT_TABLE()

T100DebugFrame::T100DebugFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100DebugFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100DebugFrame)
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer14;
	wxBoxSizer* BoxSizer15;
	wxBoxSizer* BoxSizer16;
	wxBoxSizer* BoxSizer17;
	wxBoxSizer* BoxSizer18;
	wxBoxSizer* BoxSizer19;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer20;
	wxBoxSizer* BoxSizer21;
	wxBoxSizer* BoxSizer22;
	wxBoxSizer* BoxSizer23;
	wxBoxSizer* BoxSizer24;
	wxBoxSizer* BoxSizer25;
	wxBoxSizer* BoxSizer26;
	wxBoxSizer* BoxSizer27;
	wxBoxSizer* BoxSizer28;
	wxBoxSizer* BoxSizer29;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer30;
	wxBoxSizer* BoxSizer31;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("RAX:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer5->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRAX = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	BoxSizer5->Add(ComboBoxRAX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 1, wxALL, 0);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("RBX:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRBX = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	BoxSizer6->Add(ComboBoxRBX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("RCX:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer7->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRCX = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	BoxSizer7->Add(ComboBoxRCX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("RDX:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer8->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRDX = new wxComboBox(this, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	BoxSizer8->Add(ComboBoxRDX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("RSI:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer10->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRSI = new wxComboBox(this, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	BoxSizer10->Add(ComboBoxRSI, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("RDI:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer11->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRDI = new wxComboBox(this, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	BoxSizer11->Add(ComboBoxRDI, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("RBP:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer12->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRBP = new wxComboBox(this, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	BoxSizer12->Add(ComboBoxRBP, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("RSP:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer13->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRSP = new wxComboBox(this, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX8"));
	BoxSizer13->Add(ComboBoxRSP, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer9 = new wxBoxSizer(wxVERTICAL);
	BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("CS:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer14->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxCS = new wxComboBox(this, ID_COMBOBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX9"));
	BoxSizer14->Add(ComboBoxCS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("RIP:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer14->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxRIP = new wxComboBox(this, ID_COMBOBOX10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX10"));
	BoxSizer14->Add(ComboBoxRIP, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer14, 1, wxALL|wxEXPAND, 0);
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("SS:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer15->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxSS = new wxComboBox(this, ID_COMBOBOX11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX11"));
	BoxSizer15->Add(ComboBoxSS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("EFER:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer15->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxEFER = new wxComboBox(this, ID_COMBOBOX12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX12"));
	BoxSizer15->Add(ComboBoxEFER, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer15, 1, wxALL|wxEXPAND, 0);
	BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("DS:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizer16->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxDS = new wxComboBox(this, ID_COMBOBOX13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX13"));
	BoxSizer16->Add(ComboBoxDS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("MXCSR:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	BoxSizer16->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxMXCSR = new wxComboBox(this, ID_COMBOBOX14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX14"));
	BoxSizer16->Add(ComboBoxMXCSR, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer16, 1, wxALL|wxEXPAND, 0);
	BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("ES:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	BoxSizer17->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxES = new wxComboBox(this, ID_COMBOBOX15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX15"));
	BoxSizer17->Add(ComboBoxES, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	BoxSizer17->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox16 = new wxComboBox(this, ID_COMBOBOX16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX16"));
	BoxSizer17->Add(ComboBox16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer17, 1, wxALL|wxEXPAND, 0);
	BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("FS:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	BoxSizer18->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxFS = new wxComboBox(this, ID_COMBOBOX17, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX17"));
	BoxSizer18->Add(ComboBoxFS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("FS Base:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	BoxSizer18->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxFSBase = new wxComboBox(this, ID_COMBOBOX18, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX18"));
	BoxSizer18->Add(ComboBoxFSBase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer18, 1, wxALL|wxEXPAND, 0);
	BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
	StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("GS:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	BoxSizer19->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxGS = new wxComboBox(this, ID_COMBOBOX19, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX19"));
	BoxSizer19->Add(ComboBoxGS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText20 = new wxStaticText(this, ID_STATICTEXT20, _("GS Base:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	BoxSizer19->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxGSBase = new wxComboBox(this, ID_COMBOBOX20, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX20"));
	BoxSizer19->Add(ComboBoxGSBase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer19, 1, wxALL|wxEXPAND, 0);
	BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
	StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("EFLAGS:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	BoxSizer20->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxEFLAGS = new wxComboBox(this, ID_COMBOBOX21, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX21"));
	BoxSizer20->Add(ComboBoxEFLAGS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("K GS Base:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	BoxSizer20->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxKGSBase = new wxComboBox(this, ID_COMBOBOX22, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX22"));
	BoxSizer20->Add(ComboBoxKGSBase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer20, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer2->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
	BoxSizer21 = new wxBoxSizer(wxVERTICAL);
	BoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
	StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("R8:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	BoxSizer22->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR8 = new wxComboBox(this, ID_COMBOBOX23, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX23"));
	BoxSizer22->Add(ComboBoxR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText24 = new wxStaticText(this, ID_STATICTEXT24, _("R12:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	BoxSizer22->Add(StaticText24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR12 = new wxComboBox(this, ID_COMBOBOX24, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX24"));
	BoxSizer22->Add(ComboBoxR12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21->Add(BoxSizer22, 1, wxALL|wxEXPAND, 0);
	BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
	StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("R9:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	BoxSizer23->Add(StaticText25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR9 = new wxComboBox(this, ID_COMBOBOX25, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX25"));
	BoxSizer23->Add(ComboBoxR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("R13:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	BoxSizer23->Add(StaticText26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR13 = new wxComboBox(this, ID_COMBOBOX26, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX26"));
	BoxSizer23->Add(ComboBoxR13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21->Add(BoxSizer23, 1, wxALL|wxEXPAND, 0);
	BoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
	StaticText27 = new wxStaticText(this, ID_STATICTEXT27, _("R10:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
	BoxSizer24->Add(StaticText27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR10 = new wxComboBox(this, ID_COMBOBOX27, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX27"));
	BoxSizer24->Add(ComboBoxR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText28 = new wxStaticText(this, ID_STATICTEXT28, _("R14:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	BoxSizer24->Add(StaticText28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR14 = new wxComboBox(this, ID_COMBOBOX28, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX28"));
	BoxSizer24->Add(ComboBoxR14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21->Add(BoxSizer24, 1, wxALL|wxEXPAND, 0);
	BoxSizer25 = new wxBoxSizer(wxHORIZONTAL);
	StaticText29 = new wxStaticText(this, ID_STATICTEXT29, _("R11:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
	BoxSizer25->Add(StaticText29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR11 = new wxComboBox(this, ID_COMBOBOX29, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX29"));
	BoxSizer25->Add(ComboBoxR11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText30 = new wxStaticText(this, ID_STATICTEXT30, _("R15:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
	BoxSizer25->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBoxR15 = new wxComboBox(this, ID_COMBOBOX30, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX30"));
	BoxSizer25->Add(ComboBoxR15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21->Add(BoxSizer25, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer3->Add(BoxSizer21, 1, wxALL, 0);
	BoxSizer1->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, this, _("Label"));
	BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
	ButtonRun = new wxButton(this, ID_BUTTON_RUN, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RUN"));
	BoxSizer26->Add(ButtonRun, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer26->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer26, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
	ButtonStepIn = new wxButton(this, ID_BUTTON_STEP_IN, _("Step"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_STEP_IN"));
	BoxSizer27->Add(ButtonStepIn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer27->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer27, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer28 = new wxBoxSizer(wxHORIZONTAL);
	Button5 = new wxButton(this, ID_BUTTON5, _("Next"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer28->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer28, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
	Button6 = new wxButton(this, ID_BUTTON6, _("Continue"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer29->Add(Button6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer29, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer30 = new wxBoxSizer(wxHORIZONTAL);
	Button7 = new wxButton(this, ID_BUTTON7, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	BoxSizer30->Add(Button7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer30, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
	Button8 = new wxButton(this, ID_BUTTON8, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer31->Add(Button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer31, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_RUN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100DebugFrame::OnButtonRunClick);
	Connect(ID_BUTTON_STEP_IN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100DebugFrame::OnButtonStepInClick);
	//*)
}

T100DebugFrame::~T100DebugFrame()
{
	//(*Destroy(T100DebugFrame)
	//*)
}

T100VOID T100DebugFrame::SetVM(T100VM* vm)
{
    m_vm        = vm;
    m_vm->Info(this);
}

T100VM* T100DebugFrame::GetVM()
{
    return m_vm;
}

void T100DebugFrame::OnButtonRunClick(wxCommandEvent& event)
{
    m_vm->Debug();
    m_vm->Info(this);
}

void T100DebugFrame::OnButtonStepInClick(wxCommandEvent& event)
{
    m_vm->Step();
    m_vm->Info(this);
}
