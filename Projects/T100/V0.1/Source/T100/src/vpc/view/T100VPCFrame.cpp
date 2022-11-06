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

BEGIN_EVENT_TABLE(T100VPCFrame,wxFrame)
	//(*EventTable(T100VPCFrame)
	//*)
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
	//*)
}

T100VPCFrame::~T100VPCFrame()
{
	//(*Destroy(T100VPCFrame)
	//*)
}

void T100VPCFrame::OnStartMenuSelected(wxCommandEvent& event)
{
}

void T100VPCFrame::OnStopMenuSelected(wxCommandEvent& event)
{
}

void T100VPCFrame::OnQuitMenuSelected(wxCommandEvent& event)
{
}

void T100VPCFrame::OnDebugMenuSelected(wxCommandEvent& event)
{
}

void T100VPCFrame::OnHardwareMenuSelected(wxCommandEvent& event)
{
}

void T100VPCFrame::OnSetupMenuSelected(wxCommandEvent& event)
{
}

void T100VPCFrame::OnAboutMenuSelected(wxCommandEvent& event)
{
}

}
