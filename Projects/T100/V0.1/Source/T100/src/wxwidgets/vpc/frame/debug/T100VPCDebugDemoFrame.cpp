#include "../../../../include/wxwidgets/vpc/frame/debug/T100VPCDebugDemoFrame.h"

//(*InternalHeaders(T100VPCDebugDemoFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDebugDemoFrame)
const long T100VPCDebugDemoFrame::ID_STATICTEXT1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_COR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT15 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX3 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_CBR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT16 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX4 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT3 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_CCR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT17 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX5 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT18 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX6 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT19 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX7 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT20 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX8 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT21 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX9 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT4 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_AAR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT5 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_ACF = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT6 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_ABR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT7 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_AMF = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT8 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_ACR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT9 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_AOF = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT10 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_ADR = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT22 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX10 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT23 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX11 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT24 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX13 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT11 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_MEMORY_OFFSET = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX12 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT12 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX1 = wxNewId();
const long T100VPCDebugDemoFrame::ID_LISTVIEW_MEMORY = wxNewId();
const long T100VPCDebugDemoFrame::ID_SCROLLBAR_MEMORY = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT13 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX_PORT_OFFSET = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX14 = wxNewId();
const long T100VPCDebugDemoFrame::ID_STATICTEXT14 = wxNewId();
const long T100VPCDebugDemoFrame::ID_COMBOBOX2 = wxNewId();
const long T100VPCDebugDemoFrame::ID_LISTVIEW_PORT = wxNewId();
const long T100VPCDebugDemoFrame::ID_SCROLLBAR_PORT = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON_RUN = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON_STEP = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON3 = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON_CALL = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON_RETURN = wxNewId();
const long T100VPCDebugDemoFrame::ID_BUTTON_PAUSE = wxNewId();
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
	FlexGridSizer1 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("COR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CORComboBox = new wxComboBox(this, ID_COMBOBOX_COR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_COR"));
	FlexGridSizer1->Add(CORComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	FlexGridSizer1->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox3 = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	FlexGridSizer1->Add(ComboBox3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("CBR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CBRComboBox = new wxComboBox(this, ID_COMBOBOX_CBR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CBR"));
	FlexGridSizer1->Add(CBRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	FlexGridSizer1->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox4 = new wxComboBox(this, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	FlexGridSizer1->Add(ComboBox4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CCR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCRComboBox = new wxComboBox(this, ID_COMBOBOX_CCR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CCR"));
	FlexGridSizer1->Add(CCRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	FlexGridSizer1->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox5 = new wxComboBox(this, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	FlexGridSizer1->Add(ComboBox5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	FlexGridSizer1->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox6 = new wxComboBox(this, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	FlexGridSizer1->Add(ComboBox6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	FlexGridSizer1->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox7 = new wxComboBox(this, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	FlexGridSizer1->Add(ComboBox7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText20 = new wxStaticText(this, ID_STATICTEXT20, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	FlexGridSizer1->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox8 = new wxComboBox(this, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX8"));
	FlexGridSizer1->Add(ComboBox8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	FlexGridSizer1->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox9 = new wxComboBox(this, ID_COMBOBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX9"));
	FlexGridSizer1->Add(ComboBox9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("AU："));
	FlexGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("AAR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AARComboBox = new wxComboBox(this, ID_COMBOBOX_AAR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_AAR"));
	FlexGridSizer2->Add(AARComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("ACF："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ACFComboBox = new wxComboBox(this, ID_COMBOBOX_ACF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ACF"));
	FlexGridSizer2->Add(ACFComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("ABR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ABRComboBox = new wxComboBox(this, ID_COMBOBOX_ABR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ABR"));
	FlexGridSizer2->Add(ABRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("AMF："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AMFComboBox = new wxComboBox(this, ID_COMBOBOX_AMF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_AMF"));
	FlexGridSizer2->Add(AMFComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("ACR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ACRComboBox = new wxComboBox(this, ID_COMBOBOX_ACR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ACR"));
	FlexGridSizer2->Add(ACRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("AOF："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AOFComboBox = new wxComboBox(this, ID_COMBOBOX_AOF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_AOF"));
	FlexGridSizer2->Add(AOFComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("ADR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ADRComboBox = new wxComboBox(this, ID_COMBOBOX_ADR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ADR"));
	FlexGridSizer2->Add(ADRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	FlexGridSizer2->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox10 = new wxComboBox(this, ID_COMBOBOX10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX10"));
	FlexGridSizer2->Add(ComboBox10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	FlexGridSizer2->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox11 = new wxComboBox(this, ID_COMBOBOX11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX11"));
	FlexGridSizer2->Add(ComboBox11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText24 = new wxStaticText(this, ID_STATICTEXT24, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	FlexGridSizer2->Add(StaticText24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox13 = new wxComboBox(this, ID_COMBOBOX13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX13"));
	FlexGridSizer2->Add(ComboBox13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Memory："));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer3->Add(StaticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	MemoryOffsetComboBox = new wxComboBox(this, ID_COMBOBOX_MEMORY_OFFSET, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_MEMORY_OFFSET"));
	BoxSizer3->Add(MemoryOffsetComboBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox12 = new wxComboBox(this, ID_COMBOBOX12, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX12"));
	BoxSizer3->Add(ComboBox12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer3->Add(StaticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	BoxSizer3->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	MemoryListView = new wxListView(this, ID_LISTVIEW_MEMORY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_MEMORY"));
	BoxSizer2->Add(MemoryListView, 1, wxALL|wxEXPAND, 5);
	MemoryScrollBar = new wxScrollBar(this, ID_SCROLLBAR_MEMORY, wxDefaultPosition, wxSize(20,17), 0, wxDefaultValidator, _T("ID_SCROLLBAR_MEMORY"));
	MemoryScrollBar->SetScrollbar(0, 1, 10, 1);
	BoxSizer2->Add(MemoryScrollBar, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, this, _("Port："));
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizer4->Add(StaticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	PortOffsetComboBox = new wxComboBox(this, ID_COMBOBOX_PORT_OFFSET, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_PORT_OFFSET"));
	BoxSizer4->Add(PortOffsetComboBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox14 = new wxComboBox(this, ID_COMBOBOX14, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX14"));
	BoxSizer4->Add(ComboBox14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	BoxSizer4->Add(StaticText14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	BoxSizer4->Add(ComboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	PortListView = new wxListView(this, ID_LISTVIEW_PORT, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_PORT"));
	BoxSizer5->Add(PortListView, 1, wxALL|wxEXPAND, 5);
	PortScrollBar = new wxScrollBar(this, ID_SCROLLBAR_PORT, wxDefaultPosition, wxSize(20,119), 0, wxDefaultValidator, _T("ID_SCROLLBAR_PORT"));
	PortScrollBar->SetScrollbar(0, 1, 10, 1);
	BoxSizer5->Add(PortScrollBar, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer5->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	RunButton = new wxButton(this, ID_BUTTON_RUN, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RUN"));
	BoxSizer6->Add(RunButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StepButton = new wxButton(this, ID_BUTTON_STEP, _("Step"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_STEP"));
	BoxSizer6->Add(StepButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NextButton = new wxButton(this, ID_BUTTON3, _("Next"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer6->Add(NextButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CallButton = new wxButton(this, ID_BUTTON_CALL, _("Call"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CALL"));
	BoxSizer6->Add(CallButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ReturnButton = new wxButton(this, ID_BUTTON_RETURN, _("Return"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RETURN"));
	BoxSizer6->Add(ReturnButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	PauseButton = new wxButton(this, ID_BUTTON_PAUSE, _("Pause"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PAUSE"));
	BoxSizer6->Add(PauseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_COR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCORComboBoxSelected);
	Connect(ID_COMBOBOX_COR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCORComboBoxTextUpdated);
	Connect(ID_COMBOBOX_COR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCORComboBoxTextEnter);
	Connect(ID_COMBOBOX_CBR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCBRComboBoxSelected);
	Connect(ID_COMBOBOX_CBR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCBRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_CBR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCBRComboBoxTextEnter);
	Connect(ID_COMBOBOX_CCR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCCRComboBoxSelected);
	Connect(ID_COMBOBOX_CCR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCCRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_CCR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCCRComboBoxTextEnter);
	Connect(ID_COMBOBOX_AAR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAARComboBoxSelected);
	Connect(ID_COMBOBOX_AAR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAARComboBoxTextUpdated);
	Connect(ID_COMBOBOX_AAR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAARComboBoxTextEnter);
	Connect(ID_COMBOBOX_ACF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnACFComboBoxSelected);
	Connect(ID_COMBOBOX_ACF,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnACFComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ACF,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnACFComboBoxTextEnter);
	Connect(ID_COMBOBOX_ABR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnABRComboBoxSelected);
	Connect(ID_COMBOBOX_ABR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnABRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ABR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnABRComboBoxTextEnter);
	Connect(ID_COMBOBOX_AMF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAMFComboBoxSelected);
	Connect(ID_COMBOBOX_AMF,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAMFComboBoxTextUpdated);
	Connect(ID_COMBOBOX_AMF,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAMFComboBoxTextEnter);
	Connect(ID_COMBOBOX_ACR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnACRComboBoxSelected);
	Connect(ID_COMBOBOX_ACR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnACRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ACR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnACRComboBoxTextEnter);
	Connect(ID_COMBOBOX_AOF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAOFComboBoxSelected);
	Connect(ID_COMBOBOX_AOF,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAOFComboBoxTextUpdated);
	Connect(ID_COMBOBOX_AOF,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnAOFComboBoxTextEnter);
	Connect(ID_COMBOBOX_ADR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnADRComboBoxSelected);
	Connect(ID_COMBOBOX_ADR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnADRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ADR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnADRComboBoxTextEnter);
	Connect(ID_COMBOBOX_MEMORY_OFFSET,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryOffsetComboBoxSelected);
	Connect(ID_COMBOBOX_MEMORY_OFFSET,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryOffsetComboBoxTextUpdated);
	Connect(ID_COMBOBOX_MEMORY_OFFSET,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryOffsetComboBoxTextEnter);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScroll);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_TOP,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollTop);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_BOTTOM,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollBottom);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollLineUp);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollLineDown);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollPageUp);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollPageDown);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnMemoryScrollBarScrollChanged);
	Connect(ID_COMBOBOX_PORT_OFFSET,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortOffsetComboBoxSelected);
	Connect(ID_COMBOBOX_PORT_OFFSET,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortOffsetComboBoxTextUpdated);
	Connect(ID_COMBOBOX_PORT_OFFSET,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortOffsetComboBoxTextEnter);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScroll);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_TOP,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollTop);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_BOTTOM,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollBottom);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollLineUp);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollLineDown);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollPageUp);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollPageDown);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPortScrollBarScrollChanged);
	Connect(ID_BUTTON_RUN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnRunButtonClick);
	Connect(ID_BUTTON_STEP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnStepButtonClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnNextButtonClick);
	Connect(ID_BUTTON_CALL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnCallButtonClick);
	Connect(ID_BUTTON_RETURN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnReturnButtonClick);
	Connect(ID_BUTTON_PAUSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugDemoFrame::OnPauseButtonClick);
	//*)
}

T100VPCDebugDemoFrame::~T100VPCDebugDemoFrame()
{
	//(*Destroy(T100VPCDebugDemoFrame)
	//*)
}


void T100VPCDebugDemoFrame::OnCORComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCORComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCORComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCBRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCBRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCBRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCCRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCCRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCCRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAARComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAARComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAARComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnABRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnABRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnABRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnACRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnACRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnACRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnADRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnADRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnADRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnACFComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnACFComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnACFComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAMFComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAMFComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAMFComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAOFComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAOFComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnAOFComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryOffsetComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryOffsetComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryOffsetComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollLineDown(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollPageUp(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollPageDown(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollChanged(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortOffsetComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortOffsetComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortOffsetComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollLineUp(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScroll(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollTop(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnMemoryScrollBarScrollBottom(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScroll(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollTop(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollBottom(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollLineUp(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollLineDown(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollPageUp(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollPageDown(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPortScrollBarScrollChanged(wxScrollEvent& event)
{
}

void T100VPCDebugDemoFrame::OnRunButtonClick(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnPauseButtonClick(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnStepButtonClick(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnNextButtonClick(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnCallButtonClick(wxCommandEvent& event)
{
}

void T100VPCDebugDemoFrame::OnReturnButtonClick(wxCommandEvent& event)
{
}
