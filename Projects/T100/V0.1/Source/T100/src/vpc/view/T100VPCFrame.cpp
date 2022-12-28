#include "../../../include/vpc/view/T100VPCFrame.h"

//(*InternalHeaders(T100VPCFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "T100VPCCallback.h"

namespace T100VPC{

//(*IdInit(T100VPCFrame)
const long T100VPCFrame::ID_MENUITEM_START = wxNewId();
const long T100VPCFrame::ID_MENUITEM_STOP = wxNewId();
const long T100VPCFrame::ID_MENUITEM_QUIT = wxNewId();
const long T100VPCFrame::ID_MENUITEM_DEBUG = wxNewId();
const long T100VPCFrame::ID_MENUITEM_HARDWARE = wxNewId();
const long T100VPCFrame::ID_MENUITEM_SETUP = wxNewId();
const long T100VPCFrame::ID_MENUITEM_ABOUT = wxNewId();
const long T100VPCFrame::ID_STATUSBAR1 = wxNewId();
//*)

const long T100VPCFrame::ID_THREAD_START = wxNewId();
const long T100VPCFrame::ID_THREAD_STOP = wxNewId();
const long T100VPCFrame::ID_THREAD_QUIT = wxNewId();
const long T100VPCFrame::ID_DEBUG_CMT_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_REGISTER_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_MEMORY_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_PORT_UPDATE = wxNewId();
const long T100VPCFrame::ID_DEBUG_PAUSE = wxNewId();


BEGIN_EVENT_TABLE(T100VPCFrame,wxFrame)
	//(*EventTable(T100VPCFrame)
	//*)
	EVT_THREAD(ID_THREAD_START, T100VPCFrame::OnThreadStart)
	EVT_THREAD(ID_THREAD_STOP, T100VPCFrame::OnThreadStop)
	EVT_THREAD(ID_THREAD_QUIT, T100VPCFrame::OnThreadQuit)
	//
	EVT_THREAD(ID_DEBUG_CMT_UPDATE, T100VPCFrame::OnDebugCmtUpdate)
	EVT_THREAD(ID_DEBUG_REGISTER_UPDATE, T100VPCFrame::OnDebugRegisterUpdate)
	EVT_THREAD(ID_DEBUG_MEMORY_UPDATE, T100VPCFrame::OnDebugMemoryUpdate)
	EVT_THREAD(ID_DEBUG_PORT_UPDATE, T100VPCFrame::OnDebugPortUpdate)
	//
	EVT_THREAD(ID_DEBUG_PAUSE, T100VPCFrame::OnDebugPause)
END_EVENT_TABLE()

T100VPCFrame::T100VPCFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	StartMenu = new wxMenuItem(Menu1, ID_MENUITEM_START, _("Start"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(StartMenu);
	StopMenu = new wxMenuItem(Menu1, ID_MENUITEM_STOP, _("Stop"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(StopMenu);
	Menu1->AppendSeparator();
	QuitMenu = new wxMenuItem(Menu1, ID_MENUITEM_QUIT, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
	Menu1->Append(QuitMenu);
	MenuBar1->Append(Menu1, _("&File"));
	Menu6 = new wxMenu();
	DebugMenu = new wxMenuItem(Menu6, ID_MENUITEM_DEBUG, _("Debug"), wxEmptyString, wxITEM_NORMAL);
	Menu6->Append(DebugMenu);
	MenuBar1->Append(Menu6, _("Debug"));
	Menu8 = new wxMenu();
	HardwareMenu = new wxMenuItem(Menu8, ID_MENUITEM_HARDWARE, _("Hardware"), wxEmptyString, wxITEM_NORMAL);
	Menu8->Append(HardwareMenu);
	SetupMenu = new wxMenuItem(Menu8, ID_MENUITEM_SETUP, _("Setup"), wxEmptyString, wxITEM_NORMAL);
	Menu8->Append(SetupMenu);
	MenuBar1->Append(Menu8, _("Config"));
	Menu11 = new wxMenu();
	AboutMenu = new wxMenuItem(Menu11, ID_MENUITEM_ABOUT, _("About\tF1"), _("Show info about this application "), wxITEM_NORMAL);
	Menu11->Append(AboutMenu);
	MenuBar1->Append(Menu11, _("Help"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(ID_MENUITEM_START,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnStartMenuSelected);
	Connect(ID_MENUITEM_STOP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnStopMenuSelected);
	Connect(ID_MENUITEM_QUIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnQuitMenuSelected);
	Connect(ID_MENUITEM_DEBUG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnDebugMenuSelected);
	Connect(ID_MENUITEM_HARDWARE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnHardwareMenuSelected);
	Connect(ID_MENUITEM_SETUP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnSetupMenuSelected);
	Connect(ID_MENUITEM_ABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnAboutMenuSelected);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100VPCFrame::OnClose);
	//*)
}

T100VPCFrame::~T100VPCFrame()
{
	//(*Destroy(T100VPCFrame)
	//*)
}

void T100VPCFrame::OnStartMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_start();
}

void T100VPCFrame::OnStopMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_stop();
}

void T100VPCFrame::OnQuitMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_quit();
}

void T100VPCFrame::OnDebugMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_debug();
}

void T100VPCFrame::OnHardwareMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware();
}

void T100VPCFrame::OnSetupMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_setup();
}

void T100VPCFrame::OnAboutMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_about();
}


void T100VPCFrame::OnThreadStart(wxThreadEvent& event)
{

}

void T100VPCFrame::OnThreadStop(wxThreadEvent& event)
{
    T100VPCCallback::notify_thread_stop();
}

void T100VPCFrame::OnThreadQuit(wxThreadEvent& event)
{

}

void T100VPCFrame::OnDebugCmtUpdate(wxThreadEvent& event)
{
    T100VPCCallback::debug_cmt_update((void*)&event);
}

void T100VPCFrame::OnDebugRegisterUpdate(wxThreadEvent& event)
{
    T100VPCCallback::debug_register_update(event.GetEventObject());
}

void T100VPCFrame::OnDebugMemoryUpdate(wxThreadEvent& event)
{

}

void T100VPCFrame::OnDebugPortUpdate(wxThreadEvent& event)
{

}

void T100VPCFrame::OnDebugPause(wxThreadEvent& event)
{

}

void T100VPCFrame::OnClose(wxCloseEvent& event)
{
    T100VPCCallback::frame_menu_quit();
}

}


