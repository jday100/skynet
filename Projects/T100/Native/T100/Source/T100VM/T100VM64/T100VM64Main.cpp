/***************************************************************
 * Name:      T100VM64Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-02-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VM64Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100VM64Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VM64Host.h"


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

//(*IdInit(T100VM64Frame)
const long T100VM64Frame::ID_MENUITEM_NEW = wxNewId();
const long T100VM64Frame::idMenuQuit = wxNewId();
const long T100VM64Frame::idMenuAbout = wxNewId();
const long T100VM64Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VM64Frame,wxFrame)
    //(*EventTable(T100VM64Frame)
    //*)
END_EVENT_TABLE()

T100VM64Frame::T100VM64Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100VM64Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
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

    Connect(ID_MENUITEM_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VM64Frame::OnMenuItemNew);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VM64Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VM64Frame::OnAbout);
    //*)
}

T100VM64Frame::~T100VM64Frame()
{
    //(*Destroy(T100VM64Frame)
    //*)
}

void T100VM64Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100VM64Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100VM64Frame::OnMenuItemNew(wxCommandEvent& event)
{
    T100VM64Host        host;

    host.start();
}
