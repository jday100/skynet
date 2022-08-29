#include "../../../include/vpc/view/T100VPCFrame.h"

//(*InternalHeaders(T100VPCFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VPCSetup.h"
#include "T100VPCApp.h"
#include "T100VPCView.h"
#include "T100VPCSetupDialog.h"
#include "T100VPCCallbackNew.h"


//(*IdInit(T100VPCFrame)
const long T100VPCFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long T100VPCFrame::ID_STATUSBAR1 = wxNewId();
const long T100VPCFrame::ID_MENUITEM_START = wxNewId();
const long T100VPCFrame::ID_MENUITEM_STOP = wxNewId();
const long T100VPCFrame::ID_MENUITEM_QUIT = wxNewId();
const long T100VPCFrame::ID_MENUITEM_SETUP = wxNewId();
const long T100VPCFrame::ID_MENUITEM_DEBUG = wxNewId();
//*)
const long T100VPCFrame::ID_THREAD_DEBUG = wxNewId();
const long T100VPCFrame::ID_THREAD_DEBUG_UPDATE = wxNewId();
const long T100VPCFrame::ID_THREAD_DONE = wxNewId();
const long T100VPCFrame::ID_THREAD_QUIT = wxNewId();
const long T100VPCFrame::ID_DEBUG_ROM_BASE_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_RAM_BASE_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_DEVICE_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_BLOCK_BASE_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_PAGE_BASE_UPDATE = wxNewId();


BEGIN_EVENT_TABLE(T100VPCFrame,wxFrame)
	//(*EventTable(T100VPCFrame)
	//*)
	EVT_THREAD(ID_THREAD_DEBUG, T100VPCFrame::OnThreadDebug)
	EVT_THREAD(ID_THREAD_DEBUG_UPDATE, T100VPCFrame::OnThreadDebugUpdate)
	EVT_THREAD(ID_THREAD_DONE, T100VPCFrame::OnThreadDone)
	EVT_THREAD(ID_THREAD_QUIT, T100VPCFrame::OnThreadQuit)
	EVT_THREAD(ID_DEBUG_ROM_BASE_UPDATE, T100VPCFrame::OnDebugRomBaseUpdate)
    EVT_THREAD(ID_DEBUG_RAM_BASE_UPDATE, T100VPCFrame::OnDebugRamBaseUpdate)
    EVT_THREAD(ID_DEBUG_DEVICE_UPDATE, T100VPCFrame::OnDebugDeviceUpdate)
    EVT_THREAD(ID_DEBUG_BLOCK_BASE_UPDATE, T100VPCFrame::OnDebugBlockBaseUpdate)
    EVT_THREAD(ID_DEBUG_PAGE_BASE_UPDATE, T100VPCFrame::OnDebugPageBaseUpdate)
END_EVENT_TABLE()

T100VPCFrame::T100VPCFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);

	MenuStop->Enable(T100FALSE);
}

void T100VPCFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	RichTextCtrl1 = new wxRichTextCtrl(this, ID_RICHTEXTCTRL1, _("Text"), wxPoint(232,312), wxDefaultSize, wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
	wxRichTextAttr rchtxtAttr_1;
	rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuStart = new wxMenuItem(Menu1, ID_MENUITEM_START, _("Start"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuStart);
	MenuStop = new wxMenuItem(Menu1, ID_MENUITEM_STOP, _("Stop"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuStop);
	Menu1->AppendSeparator();
	MenuQuit = new wxMenuItem(Menu1, ID_MENUITEM_QUIT, _("Quit"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuQuit);
	MenuBar1->Append(Menu1, _("File"));
	Menu4 = new wxMenu();
	MenuSetup = new wxMenuItem(Menu4, ID_MENUITEM_SETUP, _("Setup"), wxEmptyString, wxITEM_NORMAL);
	Menu4->Append(MenuSetup);
	MenuDebug = new wxMenuItem(Menu4, ID_MENUITEM_DEBUG, _("Debug"), wxEmptyString, wxITEM_NORMAL);
	Menu4->Append(MenuDebug);
	MenuBar1->Append(Menu4, _("Config"));
	SetMenuBar(MenuBar1);

	Connect(ID_MENUITEM_START,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuStartSelected);
	Connect(ID_MENUITEM_STOP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuStopSelected);
	Connect(ID_MENUITEM_QUIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuQuitSelected);
	Connect(ID_MENUITEM_SETUP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuSetupSelected);
	Connect(ID_MENUITEM_DEBUG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuDebugSelected);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100VPCFrame::OnClose);
	//*)

}

T100VPCFrame::~T100VPCFrame()
{
	//(*Destroy(T100VPCFrame)
	//*)

	if(m_view){
        m_view->m_quit = T100TRUE;
	}
}

T100VOID T100VPCFrame::setView(T100VPCView* view)
{
    m_view = view;
}

T100VPCView* T100VPCFrame::getView()
{
    return m_view;
}

T100BOOL T100VPCFrame::start()
{
    MenuStart->Enable(T100FALSE);
    MenuSetup->Enable(T100FALSE);
    MenuStop->Enable();

    return T100TRUE;
}

T100BOOL T100VPCFrame::stop()
{
    MenuStart->Enable();
    MenuSetup->Enable();
    MenuStop->Enable(T100FALSE);

    return T100TRUE;
}

void T100VPCFrame::OnMenuStartSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_start();

    //T100VPCCallback::start(m_view, this);

    /*
    MenuStart->Enable(T100FALSE);
    MenuSetup->Enable(T100FALSE);
    if(m_view->start()){
        MenuStop->Enable();
    }else{
        MenuStart->Enable();
        MenuSetup->Enable();
    }
    */
}

void T100VPCFrame::OnMenuStopSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_stop();

    //T100VPCCallback::stop(m_view, this);

    /*
    if(m_view->stop()){
        MenuStart->Enable();
        MenuSetup->Enable();
        MenuStop->Enable(T100FALSE);
    }
    */
}

void T100VPCFrame::OnMenuQuitSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_quit();

    //T100VPCCallback::quit(m_view, this);

    //Destroy();
    //Close();
    //exit(0);
}

void T100VPCFrame::OnMenuSetupSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_setup();

    //T100VPCCallback::setup(m_view, this);
}

void T100VPCFrame::OnThreadDebug(wxThreadEvent& event)
{
    if(m_view){
        m_view->getDebugFrame()->Show();
        m_debugging = T100TRUE;
        m_view->getDebugFrame()->load();
    }
}

void T100VPCFrame::OnThreadDebugUpdate(wxThreadEvent& event)
{
    if(m_view){
        m_view->getDebugFrame()->update();
    }
}

void T100VPCFrame::OnThreadDone(wxThreadEvent& event)
{
    if(m_view){
        T100VPCServe* serve = T100NULL;

        serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
        if(serve){
            T100VPCSetup::m_return = serve->getReturn();
        }
    }
}

void T100VPCFrame::OnThreadQuit(wxThreadEvent& event)
{
    if(m_view){
        T100VPCServe* serve = T100NULL;

        serve = dynamic_cast<T100VPCServe*>(m_view->getServe());
        if(serve){
            T100VPCSetup::m_return = serve->getReturn();
        }
    }

    Close();
}

void T100VPCFrame::OnDebugRomBaseUpdate(wxThreadEvent& event)
{
    if(m_view){
        m_view->getDebugFrame()->updateRom(event.GetString());
    }
}

void T100VPCFrame::OnDebugRamBaseUpdate(wxThreadEvent& event)
{
    if(m_view){
        m_view->getDebugFrame()->updateRam(event.GetString());
    }
}

void T100VPCFrame::OnDebugDeviceUpdate(wxThreadEvent& event)
{
    if(m_view){
        if(m_view->getDebugFrame()->IsShown()){
            m_view->getDebugFrame()->updateDevice();
        }
    }
}

void T100VPCFrame::OnDebugBlockBaseUpdate(wxThreadEvent& event)
{
    if(m_view){
        m_view->getDebugFrame()->updateBlock(event.GetString());
    }
}

void T100VPCFrame::OnDebugPageBaseUpdate(wxThreadEvent& event)
{
    if(m_view){
        m_view->getDebugFrame()->updatePage(event.GetString());
    }
}

void T100VPCFrame::OnClose(wxCloseEvent& event)
{
    T100VPCCallback::frame_event_close();

    //T100VPCCallback::close(this, getView()->getServe());
}

void T100VPCFrame::OnMenuDebugSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_debug();
}
