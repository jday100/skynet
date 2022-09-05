#include "T100VPCDebugFrame.h"

#include <wx/intl.h>
#include <wx/string.h>
#include "T100OrderTypes.h"
#include "T100VPCCommon.h"
#include "T100VPCSetup.h"
#include "T100VPCCallback.h"
#include "T100QU32.h"


const long T100VPCDebugFrame::ID_STATICTEXT1 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_COR = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT2 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_CBR = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT3 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_CCR = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT4 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_AAR = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT5 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ACF = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT6 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ABR = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT7 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_AMF = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT8 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ACR = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT9 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_AOF = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT10 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ADR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_MEMORY_OFFSET = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX12 = wxNewId();
const long T100VPCDebugFrame::ID_LISTVIEW_MEMORY = wxNewId();
const long T100VPCDebugFrame::ID_SCROLLBAR_MEMORY = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_PORT_OFFSET = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX14 = wxNewId();
const long T100VPCDebugFrame::ID_LISTVIEW_PORT = wxNewId();
const long T100VPCDebugFrame::ID_SCROLLBAR_PORT = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_RUN = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_STEP = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON3 = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_CALL = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_RETURN = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_PAUSE = wxNewId();

BEGIN_EVENT_TABLE(T100VPCDebugFrame,wxFrame)
	//(*EventTable(T100VPCDebugFrame)
	//*)
END_EVENT_TABLE()


T100VPCDebugFrame::T100VPCDebugFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
    create();
}

T100VPCDebugFrame::~T100VPCDebugFrame()
{
    //dtor
    destroy();
}

T100VOID T100VPCDebugFrame::create()
{
    T100VPCSetup::MEMORY_WINDOW_BEGIN       = T100MEMORY_RAM_BASE;
    T100VPCSetup::MEMORY_WINDOW_END         = T100MEMORY_RAM_BASE + 256;

    T100VPCSetup::PORT_WINDOW_BEGIN         = 0;
    T100VPCSetup::PORT_WINDOW_END           = 256;

    initList();
}

T100VOID T100VPCDebugFrame::destroy()
{

}

void T100VPCDebugFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

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
	CORComboBox = new wxComboBox(this, ID_COMBOBOX_COR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_COR"));
	FlexGridSizer1->Add(CORComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("CBR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CBRComboBox = new wxComboBox(this, ID_COMBOBOX_CBR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CBR"));
	FlexGridSizer1->Add(CBRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CCR："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CCRComboBox = new wxComboBox(this, ID_COMBOBOX_CCR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CCR"));
	FlexGridSizer1->Add(CCRComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(FlexGridSizer1, 1, wxALL|wxALIGN_TOP, 5);
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
	StaticBoxSizer4->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Memory："));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	MemoryOffsetComboBox = new wxComboBox(this, ID_COMBOBOX_MEMORY_OFFSET, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_MEMORY_OFFSET"));
	BoxSizer3->Add(MemoryOffsetComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox12 = new wxComboBox(this, ID_COMBOBOX12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX12"));
	BoxSizer3->Add(ComboBox12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
	PortOffsetComboBox = new wxComboBox(this, ID_COMBOBOX_PORT_OFFSET, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_PORT_OFFSET"));
	BoxSizer4->Add(PortOffsetComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox14 = new wxComboBox(this, ID_COMBOBOX14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX14"));
	BoxSizer4->Add(ComboBox14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_COMBOBOX_COR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCORComboBoxSelected);
	Connect(ID_COMBOBOX_COR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCORComboBoxTextUpdated);
	Connect(ID_COMBOBOX_COR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnCORComboBoxTextEnter);
	Connect(ID_COMBOBOX_CBR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCBRComboBoxSelected);
	Connect(ID_COMBOBOX_CBR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCBRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_CBR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnCBRComboBoxTextEnter);
	Connect(ID_COMBOBOX_CCR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCCRComboBoxSelected);
	Connect(ID_COMBOBOX_CCR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCCRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_CCR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnCCRComboBoxTextEnter);
	Connect(ID_COMBOBOX_AAR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnAARComboBoxSelected);
	Connect(ID_COMBOBOX_AAR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnAARComboBoxTextUpdated);
	Connect(ID_COMBOBOX_AAR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnAARComboBoxTextEnter);
	Connect(ID_COMBOBOX_ACF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnACFComboBoxSelected);
	Connect(ID_COMBOBOX_ACF,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnACFComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ACF,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnACFComboBoxTextEnter);
	Connect(ID_COMBOBOX_ABR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnABRComboBoxSelected);
	Connect(ID_COMBOBOX_ABR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnABRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ABR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnABRComboBoxTextEnter);
	Connect(ID_COMBOBOX_AMF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnAMFComboBoxSelected);
	Connect(ID_COMBOBOX_AMF,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnAMFComboBoxTextUpdated);
	Connect(ID_COMBOBOX_AMF,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnAMFComboBoxTextEnter);
	Connect(ID_COMBOBOX_ACR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnACRComboBoxSelected);
	Connect(ID_COMBOBOX_ACR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnACRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ACR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnACRComboBoxTextEnter);
	Connect(ID_COMBOBOX_AOF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnAOFComboBoxSelected);
	Connect(ID_COMBOBOX_AOF,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnAOFComboBoxTextUpdated);
	Connect(ID_COMBOBOX_AOF,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnAOFComboBoxTextEnter);
	Connect(ID_COMBOBOX_ADR,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnADRComboBoxSelected);
	Connect(ID_COMBOBOX_ADR,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnADRComboBoxTextUpdated);
	Connect(ID_COMBOBOX_ADR,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnADRComboBoxTextEnter);
	Connect(ID_COMBOBOX_MEMORY_OFFSET,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryOffsetComboBoxSelected);
	Connect(ID_COMBOBOX_MEMORY_OFFSET,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryOffsetComboBoxTextUpdated);
	Connect(ID_COMBOBOX_MEMORY_OFFSET,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryOffsetComboBoxTextEnter);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScroll);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_TOP,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollTop);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_BOTTOM,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollBottom);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollLineUp);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollLineDown);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollPageUp);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollPageDown);
	Connect(ID_SCROLLBAR_MEMORY,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugFrame::OnMemoryScrollBarScrollChanged);
	Connect(ID_COMBOBOX_PORT_OFFSET,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortOffsetComboBoxSelected);
	Connect(ID_COMBOBOX_PORT_OFFSET,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortOffsetComboBoxTextUpdated);
	Connect(ID_COMBOBOX_PORT_OFFSET,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortOffsetComboBoxTextEnter);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScroll);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_TOP,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollTop);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_BOTTOM,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollBottom);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollLineUp);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollLineDown);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_PAGEUP,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollPageUp);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_PAGEDOWN,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollPageDown);
	Connect(ID_SCROLLBAR_PORT,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&T100VPCDebugFrame::OnPortScrollBarScrollChanged);
	Connect(ID_BUTTON_RUN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnRunButtonClick);
	Connect(ID_BUTTON_STEP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnStepButtonClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnNextButtonClick);
	Connect(ID_BUTTON_CALL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnCallButtonClick);
	Connect(ID_BUTTON_RETURN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnReturnButtonClick);
	Connect(ID_BUTTON_PAUSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnPauseButtonClick);

}

T100BOOL T100VPCDebugFrame::load(T100QU32* host)
{
    CORComboBox->SetValue(std::to_string(host->getCU32()->m_cor.getValue()));
    CBRComboBox->SetValue(std::to_string(host->getCU32()->getCBR()));
    CCRComboBox->SetValue(std::to_string(host->getCU32()->getCCR()));

    AARComboBox->SetValue(std::to_string(host->getAU32()->getAAR()));
    ABRComboBox->SetValue(std::to_string(host->getAU32()->getABR()));
    ACRComboBox->SetValue(std::to_string(host->getAU32()->getACR()));
    ADRComboBox->SetValue(std::to_string(host->getAU32()->getADR()));
    ACFComboBox->SetValue(std::to_string(host->getAU32()->getACF()));
    AMFComboBox->SetValue(std::to_string(host->getAU32()->getAMF()));
    AOFComboBox->SetValue(std::to_string(host->getAU32()->getAOF()));

    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::save()
{
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::initList()
{
    MemoryListView->ClearAll();

    MemoryListView->AppendColumn(_("Offset"), wxLIST_FORMAT_CENTER, 200);
    MemoryListView->AppendColumn(_("Value"), wxLIST_FORMAT_CENTER, 200);
    MemoryListView->AppendColumn(_("Symbol"), wxLIST_FORMAT_CENTER, 200);
    MemoryListView->AppendColumn(_(""), wxLIST_FORMAT_CENTER, 200);

    T100WORD        start;
    T100WORD        stop;
    T100WORD        offset;
    T100WORD        index;


    start   = T100VPCSetup::MEMORY_WINDOW_BEGIN;
    stop    = T100VPCSetup::MEMORY_WINDOW_END;

    offset  = start;
    index   = offset - start;

    for(;offset < stop;offset++){
        long id = MemoryListView->InsertItem(index++, std::to_string(offset));

        //MemoryListView->InsertItem(id, std::to_string(0));
    }

    int i = MemoryListView->GetCountPerPage();



    MemoryListView->ClearAll();

    MemoryListView->AppendColumn(_("Offset"), wxLIST_FORMAT_CENTER, 200);
    MemoryListView->AppendColumn(_("Value"), wxLIST_FORMAT_CENTER, 200);
    MemoryListView->AppendColumn(_("Symbol"), wxLIST_FORMAT_CENTER, 200);
    MemoryListView->AppendColumn(_(""), wxLIST_FORMAT_CENTER, 200);

    start   = T100VPCSetup::MEMORY_WINDOW_BEGIN;
    stop    = start + i;
    offset  = start;
    index   = 0;

    for(;offset < stop;offset++){
        long id = MemoryListView->InsertItem(index++, std::to_string(offset));
    }

    ///
    i = PortListView->GetCountPerPage();
    PortListView->ClearAll();

    PortListView->AppendColumn(_("Offset"), wxLIST_FORMAT_CENTER, 200);
    PortListView->AppendColumn(_("Value"), wxLIST_FORMAT_CENTER, 200);
    PortListView->AppendColumn(_("Symbol"), wxLIST_FORMAT_CENTER, 200);
    PortListView->AppendColumn(_(""), wxLIST_FORMAT_CENTER, 200);

    start   = T100VPCSetup::PORT_WINDOW_BEGIN;
    stop    = start + i;
    offset  = start;
    index   = 0;

    for(;offset < stop;offset++){
        long id = PortListView->InsertItem(index++, std::to_string(offset));
    }

    return T100TRUE;
}

void T100VPCDebugFrame::OnCORComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCORComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCORComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCBRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCBRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCBRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCCRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCCRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnCCRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAARComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAARComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAARComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnABRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnABRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnABRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnACRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnACRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnACRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnADRComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnADRComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnADRComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnACFComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnACFComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnACFComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAMFComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAMFComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAMFComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAOFComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAOFComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnAOFComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryOffsetComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryOffsetComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryOffsetComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollLineDown(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollPageUp(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollPageDown(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollChanged(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortOffsetComboBoxSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnPortOffsetComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnPortOffsetComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollLineUp(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScroll(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollTop(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnMemoryScrollBarScrollBottom(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScroll(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollTop(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollBottom(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollLineUp(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollLineDown(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollPageUp(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollPageDown(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnPortScrollBarScrollChanged(wxScrollEvent& event)
{
}

void T100VPCDebugFrame::OnRunButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::debug_button_run_click();
}

void T100VPCDebugFrame::OnPauseButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::debug_button_pause_click();
}

void T100VPCDebugFrame::OnStepButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::debug_button_step_click();
}

void T100VPCDebugFrame::OnNextButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::debug_button_next_click();
}

void T100VPCDebugFrame::OnCallButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::debug_button_call_click();
}

void T100VPCDebugFrame::OnReturnButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::debug_button_return_click();
}

T100BOOL T100VPCDebugFrame::OnRegisterUpdate(T100WORD type, T100WORD value)
{
    switch(type){
    case T100COR:
        {
            CORComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100CBR:
        {
            CBRComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100CCR:
        {
            CCRComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100AAR:
        {
            AARComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100ABR:
        {
            ABRComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100ACR:
        {
            ACRComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100ADR:
        {
            ADRComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100ACF:
        {
            ACFComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100AMF:
        {
            AMFComboBox->SetValue(std::to_string(value));
        }
        break;
    case T100AOF:
        {
            AOFComboBox->SetValue(std::to_string(value));
        }
        break;
    default:
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::OnMemoryUpdate(T100WORD offset, T100WORD value)
{

}

T100BOOL T100VPCDebugFrame::OnPortUpdate(T100WORD offset, T100WORD value)
{

}
