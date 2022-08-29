#include "../../../include/vpc/view/T100VPCDebugFrame.h"

//(*InternalHeaders(T100VPCDebugFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VPCCallbackNew.h"
#include "T100VPCServe.h"
#include "T100VPCView.h"

//(*IdInit(T100VPCDebugFrame)
const long T100VPCDebugFrame::ID_STATICBOX1 = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX3 = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX2 = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_STEP = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_RUN = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX4 = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX5 = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX6 = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX7 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT1 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT2 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT3 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT5 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT6 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT7 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT8 = wxNewId();
const long T100VPCDebugFrame::ID_LISTCTRL_ROM = wxNewId();
const long T100VPCDebugFrame::ID_LISTCTRL_RAM = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX8 = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX9 = wxNewId();
const long T100VPCDebugFrame::ID_LISTCTRL_DEVICE = wxNewId();
const long T100VPCDebugFrame::ID_LISTCTRL_BLOCK = wxNewId();
const long T100VPCDebugFrame::ID_STATICBOX10 = wxNewId();
const long T100VPCDebugFrame::ID_LISTCTRL_PAGE = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT9 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT10 = wxNewId();
const long T100VPCDebugFrame::ID_STATICTEXT11 = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_COR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_CBR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_CCR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_AAR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ABR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ACR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ADR = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ACF = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_AMF = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_AOF = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_ROM_BASE = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_RAM_BASE = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_BLOCK_BASE = wxNewId();
const long T100VPCDebugFrame::ID_COMBOBOX_PAGE_BASE = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_NEXT = wxNewId();
const long T100VPCDebugFrame::ID_BUTTON_PAUSE = wxNewId();
const long T100VPCDebugFrame::ID_MENUITEM_LOG_ON = wxNewId();
const long T100VPCDebugFrame::ID_MENUITEM_LOG_OFF = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCDebugFrame,wxFrame)
	//(*EventTable(T100VPCDebugFrame)
	//*)
END_EVENT_TABLE()

T100VPCDebugFrame::T100VPCDebugFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDebugFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDebugFrame)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(600,800));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Memory："), wxPoint(8,168), wxSize(584,376), 0, _T("ID_STATICBOX1"));
	StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("IO："), wxPoint(8,544), wxSize(584,200), 0, _T("ID_STATICBOX3"));
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("CPU："), wxPoint(8,0), wxSize(584,168), 0, _T("ID_STATICBOX2"));
	StepButton = new wxButton(this, ID_BUTTON_STEP, _("Step"), wxPoint(56,760), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_STEP"));
	RunButton = new wxButton(this, ID_BUTTON_RUN, _("Run"), wxPoint(472,760), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RUN"));
	StaticBox4 = new wxStaticBox(this, ID_STATICBOX4, _("CU："), wxPoint(16,16), wxSize(168,144), 0, _T("ID_STATICBOX4"));
	StaticBox5 = new wxStaticBox(this, ID_STATICBOX5, _("AU："), wxPoint(192,16), wxSize(336,144), 0, _T("ID_STATICBOX5"));
	StaticBox6 = new wxStaticBox(this, ID_STATICBOX6, _("ROM："), wxPoint(16,184), wxSize(280,352), 0, _T("ID_STATICBOX6"));
	StaticBox7 = new wxStaticBox(this, ID_STATICBOX7, _("RAM："), wxPoint(304,184), wxSize(280,352), 0, _T("ID_STATICBOX7"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("COR："), wxPoint(24,32), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("CBR："), wxPoint(24,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CCR："), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("AAR："), wxPoint(200,32), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("ABR："), wxPoint(200,64), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("ACR："), wxPoint(200,96), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("ADR："), wxPoint(200,128), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	ListCtrlRom = new wxListCtrl(this, ID_LISTCTRL_ROM, wxPoint(24,232), wxSize(264,296), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_ROM"));
	ListCtrlRam = new wxListCtrl(this, ID_LISTCTRL_RAM, wxPoint(312,232), wxSize(264,296), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_RAM"));
	StaticBox8 = new wxStaticBox(this, ID_STATICBOX8, _("Device："), wxPoint(16,560), wxSize(184,176), 0, _T("ID_STATICBOX8"));
	StaticBox9 = new wxStaticBox(this, ID_STATICBOX9, _("Block："), wxPoint(208,560), wxSize(184,176), 0, _T("ID_STATICBOX9"));
	ListCtrlDevice = new wxListCtrl(this, ID_LISTCTRL_DEVICE, wxPoint(24,576), wxSize(168,152), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_DEVICE"));
	ListCtrlBlock = new wxListCtrl(this, ID_LISTCTRL_BLOCK, wxPoint(216,608), wxSize(168,120), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_BLOCK"));
	StaticBox10 = new wxStaticBox(this, ID_STATICBOX10, _("Page："), wxPoint(400,560), wxSize(184,176), 0, _T("ID_STATICBOX10"));
	ListCtrlPage = new wxListCtrl(this, ID_LISTCTRL_PAGE, wxPoint(408,608), wxSize(168,120), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_PAGE"));
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("ACF："), wxPoint(368,32), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("AMF："), wxPoint(368,64), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("AOF："), wxPoint(368,96), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	ComboBoxCOR = new wxComboBox(this, ID_COMBOBOX_COR, wxEmptyString, wxPoint(64,32), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_COR"));
	ComboBoxCBR = new wxComboBox(this, ID_COMBOBOX_CBR, wxEmptyString, wxPoint(64,64), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CBR"));
	ComboBoxCCR = new wxComboBox(this, ID_COMBOBOX_CCR, wxEmptyString, wxPoint(64,96), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CCR"));
	ComboBoxAAR = new wxComboBox(this, ID_COMBOBOX_AAR, wxEmptyString, wxPoint(240,32), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_AAR"));
	ComboBoxABR = new wxComboBox(this, ID_COMBOBOX_ABR, wxEmptyString, wxPoint(240,64), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ABR"));
	ComboBoxACR = new wxComboBox(this, ID_COMBOBOX_ACR, wxEmptyString, wxPoint(240,96), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ACR"));
	ComboBoxADR = new wxComboBox(this, ID_COMBOBOX_ADR, wxEmptyString, wxPoint(240,128), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ADR"));
	ComboBoxACF = new wxComboBox(this, ID_COMBOBOX_ACF, wxEmptyString, wxPoint(408,32), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ACF"));
	ComboBoxAMF = new wxComboBox(this, ID_COMBOBOX_AMF, wxEmptyString, wxPoint(408,64), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_AMF"));
	ComboBoxAOF = new wxComboBox(this, ID_COMBOBOX_AOF, wxEmptyString, wxPoint(408,96), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_AOF"));
	ComboBoxRomBase = new wxComboBox(this, ID_COMBOBOX_ROM_BASE, wxEmptyString, wxPoint(24,200), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_ROM_BASE"));
	ComboBoxRamBase = new wxComboBox(this, ID_COMBOBOX_RAM_BASE, wxEmptyString, wxPoint(312,200), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_RAM_BASE"));
	ComboBoxBlockBase = new wxComboBox(this, ID_COMBOBOX_BLOCK_BASE, wxEmptyString, wxPoint(216,576), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_BLOCK_BASE"));
	ComboBoxPageBase = new wxComboBox(this, ID_COMBOBOX_PAGE_BASE, wxEmptyString, wxPoint(408,576), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_PAGE_BASE"));
	NextButton = new wxButton(this, ID_BUTTON_NEXT, _("Next"), wxPoint(192,760), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_NEXT"));
	PauseButton = new wxButton(this, ID_BUTTON_PAUSE, _("Pause"), wxPoint(336,760), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PAUSE"));
	MenuBar = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuLogOn = new wxMenuItem(Menu1, ID_MENUITEM_LOG_ON, _("Log ON"), wxEmptyString, wxITEM_RADIO);
	Menu1->Append(MenuLogOn);
	MenuLogOff = new wxMenuItem(Menu1, ID_MENUITEM_LOG_OFF, _("Log OFF"), wxEmptyString, wxITEM_RADIO);
	Menu1->Append(MenuLogOff);
	MenuBar->Append(Menu1, _("Setup"));
	SetMenuBar(MenuBar);

	Connect(ID_BUTTON_STEP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnStepButtonClick);
	Connect(ID_BUTTON_RUN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnRunButtonClick);
	Connect(ID_COMBOBOX_ROM_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxRomBaseSelected);
	Connect(ID_COMBOBOX_ROM_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxRomBaseTextUpdated);
	Connect(ID_COMBOBOX_RAM_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxRamBaseSelected);
	Connect(ID_COMBOBOX_RAM_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxRamBaseTextUpdated);
	Connect(ID_COMBOBOX_BLOCK_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxBlockBaseSelected);
	Connect(ID_COMBOBOX_BLOCK_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxBlockBaseTextUpdated);
	Connect(ID_COMBOBOX_PAGE_BASE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxPageBaseSelected);
	Connect(ID_COMBOBOX_PAGE_BASE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100VPCDebugFrame::OnComboBoxPageBaseTextUpdated);
	Connect(ID_BUTTON_NEXT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnNextButtonClick);
	Connect(ID_BUTTON_PAUSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCDebugFrame::OnPauseButtonClick);
	Connect(ID_MENUITEM_LOG_ON,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnMenuLogOnSelected);
	Connect(ID_MENUITEM_LOG_OFF,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCDebugFrame::OnMenuLogOffSelected);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100VPCDebugFrame::OnClose);
	//*)
}

T100VPCDebugFrame::~T100VPCDebugFrame()
{
	//(*Destroy(T100VPCDebugFrame)
	//*)
}

T100VOID T100VPCDebugFrame::setView(T100VPCView* view)
{
    m_view = view;
}

T100VPCView* T100VPCDebugFrame::getView()
{
    return m_view;
}

T100BOOL T100VPCDebugFrame::start()
{
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::stop()
{
    return T100TRUE;
}

void T100VPCDebugFrame::OnStepButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_debug_step();

    /*
    if(m_view){
        T100VPCServe* serve;

        serve = dynamic_cast<T100VPCServe*>(m_view->getServe());

        if(serve){
            serve->step();
        }
    }
    */
}

void T100VPCDebugFrame::OnRunButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_debug_run();

    /*
    if(m_view){
        T100VPCServe* serve;

        serve = dynamic_cast<T100VPCServe*>(m_view->getServe());

        if(serve){
            serve->resume();
        }
    }
    */
}

T100BOOL T100VPCDebugFrame::load()
{
    if(m_view){
        T100VPCServe* serve;

        serve = dynamic_cast<T100VPCServe*>(m_view->getServe());

        if(serve){
            load(serve);
        }
    }
    return T100FALSE;
}

T100BOOL T100VPCDebugFrame::update()
{
    if(m_view){
        T100VPCServe* serve;

        serve = dynamic_cast<T100VPCServe*>(m_view->getServe());

        if(serve){
            update(serve);
        }
    }
    return T100FALSE;
}

T100VOID T100VPCDebugFrame::load(T100VPCServe* serve)
{
    if(!serve){
        return;
    }

    T100QU32*       host    = T100NULL;
    T100CU32*       cu      = T100NULL;
    T100AU32*       au      = T100NULL;
    T100Memory32*   memory  = T100NULL;

    host = serve->getHost();

    if(!host){
        return;
    }

    cu = host->getCU32();
    if(!cu){
        return;
    }

    ComboBoxCOR->SetValue(std::to_string(cu->m_cor.getValue()));
    ComboBoxCBR->SetValue(std::to_string(cu->m_cbr.getValue()));
    ComboBoxCCR->SetValue(std::to_string(cu->m_ccr.getValue()));

    au = host->getAU32();
    if(!au){
        return;
    }

    ComboBoxAAR->SetValue(std::to_string(au->getAAR()));
    ComboBoxABR->SetValue(std::to_string(au->getABR()));
    ComboBoxACR->SetValue(std::to_string(au->getACR()));
    ComboBoxADR->SetValue(std::to_string(au->getADR()));

    ComboBoxACF->SetValue(std::to_string(au->getACF()));
    ComboBoxAMF->SetValue(std::to_string(au->getAMF()));
    ComboBoxAOF->SetValue(std::to_string(au->getAOF()));

    memory = host->getMemory32();
    if(!memory){
        return;
    }

    ComboBoxRomBase->Append(wxString("0"));
    ComboBoxRomBase->Append(wxString("1024"));
    ComboBoxRomBase->Append(wxString("1048576"));

    ComboBoxRamBase->Append(wxString("1048576"));
    ComboBoxRamBase->Append(wxString("1073741824"));

    ComboBoxBlockBase->Append(wxString("1024"));
    ComboBoxPageBase->Append(wxString("1048576"));

    updateRom(wxString("0"));
    updateRam(wxString("1048576"));
    updateDevice();
    updateBlock(wxString("1024"));
    updatePage(wxString("1048576"));
}

T100VOID T100VPCDebugFrame::update(T100VPCServe* serve)
{
    if(!serve){
        return;
    }

    T100QU32*       host    = T100NULL;
    T100CU32*       cu      = T100NULL;
    T100AU32*       au      = T100NULL;
    T100Memory32*   memory  = T100NULL;

    host = serve->getHost();

    if(!host){
        return;
    }

    cu = host->getCU32();
    if(!cu){
        return;
    }

    ComboBoxCOR->SetValue(std::to_string(cu->m_cor.getValue()));
    ComboBoxCBR->SetValue(std::to_string(cu->m_cbr.getValue()));
    ComboBoxCCR->SetValue(std::to_string(cu->m_ccr.getValue()));

    au = host->getAU32();
    if(!au){
        return;
    }

    ComboBoxAAR->SetValue(std::to_string(au->getAAR()));
    ComboBoxABR->SetValue(std::to_string(au->getABR()));
    ComboBoxACR->SetValue(std::to_string(au->getACR()));
    ComboBoxADR->SetValue(std::to_string(au->getADR()));

    ComboBoxACF->SetValue(std::to_string(au->getACF()));
    ComboBoxAMF->SetValue(std::to_string(au->getAMF()));
    ComboBoxAOF->SetValue(std::to_string(au->getAOF()));

}

T100VOID T100VPCDebugFrame::update(T100Memory32* memory)
{
    if(!memory){
        return;
    }

    T100WORD    offset;

    offset = memory->m_rom_base;

    ListCtrlRom->ClearAll();
    ListCtrlRom->AppendColumn(wxString("Offset"));
    ListCtrlRom->AppendColumn(wxString("Value"));

    for(auto mem : memory->m_rom){
        long index = ListCtrlRom->InsertItem(index + 1, std::to_string(offset));
        ListCtrlRom->SetItem(index, 1, std::to_string(mem));
        offset++;
    }

    return;

    offset = memory->m_ram_base;

    ListCtrlRam->ClearAll();
    ListCtrlRam->AppendColumn(wxString("Offset"));
    ListCtrlRam->AppendColumn(wxString("Value"));

    for(auto mem : memory->m_ram){
        long index = ListCtrlRam->InsertItem(index + 1, std::to_string(offset));
        ListCtrlRam->SetItem(index, 1, std::to_string(mem));
        offset++;
    }
}

void T100VPCDebugFrame::OnComboBoxRomBaseSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnComboBoxRomBaseTextUpdated(wxCommandEvent& event)
{
    wxThreadEvent custom(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_ROM_BASE_UPDATE);

    custom.SetString(ComboBoxRomBase->GetValue().ToStdString());

    wxQueueEvent(m_view->getFrame(), custom.Clone());
}

void T100VPCDebugFrame::OnComboBoxRamBaseSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnComboBoxRamBaseTextUpdated(wxCommandEvent& event)
{
    wxThreadEvent custom(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_RAM_BASE_UPDATE);

    custom.SetString(ComboBoxRamBase->GetValue().ToStdString());

    wxQueueEvent(m_view->getFrame(), custom.Clone());
}

void T100VPCDebugFrame::OnComboBoxBlockBaseSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnComboBoxBlockBaseTextUpdated(wxCommandEvent& event)
{
    wxThreadEvent custom(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_BLOCK_BASE_UPDATE);

    custom.SetString(ComboBoxBlockBase->GetValue().ToStdString());

    wxQueueEvent(m_view->getFrame(), custom.Clone());
}

void T100VPCDebugFrame::OnComboBoxPageBaseSelected(wxCommandEvent& event)
{
}

void T100VPCDebugFrame::OnComboBoxPageBaseTextUpdated(wxCommandEvent& event)
{
    wxThreadEvent custom(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PAGE_BASE_UPDATE);

    custom.SetString(ComboBoxPageBase->GetValue().ToStdString());

    wxQueueEvent(m_view->getFrame(), custom.Clone());
}

T100BOOL T100VPCDebugFrame::updateRom(wxString value)
{
    T100VPCServe*   serve       = T100NULL;
    T100WORD        offset;
    T100WORD        osend;
    long            temp;

    if(!value.ToLong(&temp)){
        return T100FALSE;
    }

    if(!m_view){
        return T100FALSE;
    }
    serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
    if(!serve){
        return T100FALSE;
    }

    offset  = temp;
    osend   = offset + 256;

    ListCtrlRom->ClearAll();
    ListCtrlRom->AppendColumn(wxString("Offset"));
    ListCtrlRom->AppendColumn(wxString("Value"));

    for(T100WORD i=offset; i<osend; i++){
        long index = ListCtrlRom->InsertItem(index + 1, std::to_string(i));
        T100WORD mem;

        mem = serve->getHost()->getMemory32()->raw_read(i);
        ListCtrlRom->SetItem(index, 1, std::to_string(mem));
    }
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::updateRam(wxString value)
{
    T100VPCServe*   serve       = T100NULL;
    T100WORD        offset;
    T100WORD        osend;
    long            temp;

    if(value.empty()){
        if(ComboBoxRamBase->GetValue().empty()){
            temp = 1048576;
        }else{
            if(!ComboBoxRamBase->GetValue().ToLong(&temp)){
                return T100FALSE;
            }
        }
    }else{
        if(!value.ToLong(&temp)){
            return T100FALSE;
        }
    }

    if(!m_view){
        return T100FALSE;
    }
    serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
    if(!serve){
        return T100FALSE;
    }

    offset  = temp;
    osend   = offset + 256;

    ListCtrlRam->ClearAll();
    ListCtrlRam->AppendColumn(wxString("Offset"));
    ListCtrlRam->AppendColumn(wxString("Value"));

    for(T100WORD i=offset; i<osend; i++){
        long index = ListCtrlRam->InsertItem(index + 1, std::to_string(i));
        T100WORD mem;

        mem = serve->getHost()->getMemory32()->raw_read(i);
        ListCtrlRam->SetItem(index, 1, std::to_string(mem));
    }
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::updateDevice()
{
    T100VPCServe*   serve       = T100NULL;
    T100WORD        offset;
    T100WORD        osend;

    if(!m_view){
        return T100FALSE;
    }
    serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
    if(!serve){
        return T100FALSE;
    }

    offset = 0;
    osend = 1024;

    ListCtrlDevice->ClearAll();
    ListCtrlDevice->AppendColumn(wxString("Offset"));
    ListCtrlDevice->AppendColumn(wxString("Value"));

    for(T100WORD i=offset; i<osend; i++){
        long index = ListCtrlDevice->InsertItem(index + 1, std::to_string(i));
        T100WORD mem;

        //mem = serve->getHost()->getManager32()->in(i);
        T100QU32* host = serve->getHost();
        if(host){
            mem = host->getManager32()->in(i);
            ListCtrlDevice->SetItem(index, 1, std::to_string(mem));
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::updateBlock(wxString value)
{
    T100VPCServe*   serve       = T100NULL;
    T100WORD        offset;
    T100WORD        osend;
    long            temp;

    if(value.empty()){
        if(ComboBoxBlockBase->GetValue().empty()){
            temp = 1024;
        }else{
            if(!ComboBoxBlockBase->GetValue().ToLong(&temp)){
                return T100FALSE;
            }
        }
    }else{
        if(!value.ToLong(&temp)){
            return T100FALSE;
        }
    }

    if(!m_view){
        return T100FALSE;
    }
    serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
    if(!serve){
        return T100FALSE;
    }

    offset  = temp;
    osend   = offset + 256;

    ListCtrlBlock->ClearAll();
    ListCtrlBlock->AppendColumn(wxString("Offset"));
    ListCtrlBlock->AppendColumn(wxString("Value"));

    for(T100WORD i=offset; i<osend; i++){
        long index = ListCtrlBlock->InsertItem(index + 1, std::to_string(i));
        T100WORD mem;

        mem = serve->getHost()->getManager32()->in(i);
        ListCtrlBlock->SetItem(index, 1, std::to_string(mem));
    }
    return T100TRUE;
}

T100BOOL T100VPCDebugFrame::updatePage(wxString value)
{
    T100VPCServe*   serve       = T100NULL;
    T100WORD        offset;
    T100WORD        osend;
    long            temp;

    if(value.empty()){
        if(ComboBoxPageBase->GetValue().empty()){
            temp = 1048576;
        }else{
            if(!ComboBoxPageBase->GetValue().ToLong(&temp)){
                return T100FALSE;
            }
        }
    }else{
        if(!value.ToLong(&temp)){
            return T100FALSE;
        }
    }

    if(!m_view){
        return T100FALSE;
    }
    serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
    if(!serve){
        return T100FALSE;
    }

    offset  = temp;
    osend   = offset + 256;

    ListCtrlPage->ClearAll();
    ListCtrlPage->AppendColumn(wxString("Offset"));
    ListCtrlPage->AppendColumn(wxString("Value"));

    for(T100WORD i=offset; i<osend; i++){
        long index = ListCtrlPage->InsertItem(index + 1, std::to_string(i));
        T100WORD mem;

        mem = serve->getHost()->getManager32()->in(i);
        ListCtrlPage->SetItem(index, 1, std::to_string(mem));
    }
    return T100TRUE;
}

void T100VPCDebugFrame::OnClose(wxCloseEvent& event)
{
    T100VPCServe*   serve       = T100NULL;

    if(!m_view){
        return;
    }
    serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
    if(!serve){
        return;
    }

    //serve->getHost()->getExecutor32()->m_frame = T100NULL;
    serve->resume();

    Destroy();
}

void T100VPCDebugFrame::OnNextButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_debug_next();
}

void T100VPCDebugFrame::OnPauseButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_debug_pause();
}

void T100VPCDebugFrame::OnMenuLogOffSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_debug_log_off();
}

void T100VPCDebugFrame::OnMenuLogOnSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_debug_log_on();
}
