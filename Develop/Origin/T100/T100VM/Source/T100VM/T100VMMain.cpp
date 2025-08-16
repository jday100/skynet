/***************************************************************
 * Name:      T100VMMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-08-10
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VMMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100VMFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VMInvoking.h"

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

//(*IdInit(T100VMFrame)
const long T100VMFrame::ID_MENU_START = wxNewId();
const long T100VMFrame::ID_MENUSTOP = wxNewId();
const long T100VMFrame::idMenuQuit = wxNewId();
const long T100VMFrame::idMenuAbout = wxNewId();
const long T100VMFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VMFrame,wxFrame)
    //(*EventTable(T100VMFrame)
    //*)
END_EVENT_TABLE()

T100VMFrame::T100VMFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100VMFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuStart = new wxMenuItem(Menu1, ID_MENU_START, _("Start"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuStart);
    MenuStop = new wxMenuItem(Menu1, ID_MENUSTOP, _("Stop"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuStop);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&VM"));
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

    Connect(ID_MENU_START,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VMFrame::OnMenuStartSelected);
    Connect(ID_MENUSTOP,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VMFrame::OnMenuStopSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VMFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VMFrame::OnAbout);
    //*)
}

T100VMFrame::~T100VMFrame()
{
    //(*Destroy(T100VMFrame)
    //*)
}

void T100VMFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100VMFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100VMFrame::OnMenuStartSelected(wxCommandEvent& event)
{
    T100VMInvoking::OnStart();
}

void T100VMFrame::OnMenuStopSelected(wxCommandEvent& event)
{
    T100VMInvoking::OnStop();
}
