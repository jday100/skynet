/***************************************************************
 * Name:      T100VPCMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100VPCMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100VPCFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VPCApp.h"
#include "T100VPCCallback.h"


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(T100VPCFrame)
const long T100VPCFrame::ID_MENUITEM_START = wxNewId();
const long T100VPCFrame::ID_MENUITEM_STOP = wxNewId();
const long T100VPCFrame::idMenuQuit = wxNewId();
const long T100VPCFrame::ID_MENU_DEBUG = wxNewId();
const long T100VPCFrame::ID_MENU_HARDWARE = wxNewId();
const long T100VPCFrame::ID_MENU_SETUP = wxNewId();
const long T100VPCFrame::idMenuAbout = wxNewId();
const long T100VPCFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCFrame,wxFrame)
    //(*EventTable(T100VPCFrame)
    //*)
END_EVENT_TABLE()

T100VPCFrame::T100VPCFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100VPCFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    StartMenu = new wxMenuItem(Menu1, ID_MENUITEM_START, _("Start"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(StartMenu);
    StopMenu = new wxMenuItem(Menu1, ID_MENUITEM_STOP, _("Stop"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(StopMenu);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuDebug = new wxMenuItem(Menu3, ID_MENU_DEBUG, _("Debug"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuDebug);
    MenuBar1->Append(Menu3, _("Debug"));
    Menu4 = new wxMenu();
    MenuHardware = new wxMenuItem(Menu4, ID_MENU_HARDWARE, _("Hardware"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuHardware);
    MenuSetup = new wxMenuItem(Menu4, ID_MENU_SETUP, _("Setup"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuSetup);
    MenuBar1->Append(Menu4, _("Config"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_MENUITEM_START,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnStartMenuSelected);
    Connect(ID_MENUITEM_STOP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnStopMenuSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnQuit);
    Connect(ID_MENU_DEBUG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuDebugSelected);
    Connect(ID_MENU_HARDWARE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuHardwareSelected);
    Connect(ID_MENU_SETUP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnMenuSetupSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCFrame::OnAbout);
    //*)

    create();
}

T100VPCFrame::~T100VPCFrame()
{
    //(*Destroy(T100VPCFrame)
    //*)

    destroy();
}

T100VOID T100VPCFrame::create()
{
    wxGetApp().m_view.setFrame(this);

    T100VPCCallback::init(&wxGetApp().m_serve, &wxGetApp().m_view);
}

T100VOID T100VPCFrame::destroy()
{

}

void T100VPCFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100VPCFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100VPCFrame::OnStartMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_start();
}

void T100VPCFrame::OnStopMenuSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_stop();
}

void T100VPCFrame::OnMenuHardwareSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware();
}

void T100VPCFrame::OnMenuSetupSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_setup();
}

void T100VPCFrame::OnMenuDebugSelected(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_debug();
}
