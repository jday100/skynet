/***************************************************************
 * Name:      T100GameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-05
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100GameMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100GameFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(T100GameFrame)
const long T100GameFrame::idMenuQuit = wxNewId();
const long T100GameFrame::idMenuAbout = wxNewId();
const long T100GameFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100GameFrame,wxFrame)
    //(*EventTable(T100GameFrame)
    //*)
END_EVENT_TABLE()

T100GameFrame::T100GameFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100GameFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100GameFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100GameFrame::OnAbout);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100GameFrame::OnPaint);
    //*)

    create();
}

T100GameFrame::~T100GameFrame()
{
    //(*Destroy(T100GameFrame)
    //*)

    destroy();
}

T100VOID T100GameFrame::create()
{
    m_demo  = T100NEW T100Demo();

    m_demo->Create(GetHWND(), GetClientSize().GetWidth(), GetClientSize().GetHeight());
    m_demo->Start();
}

T100VOID T100GameFrame::destroy()
{
    T100SAFE_DELETE m_demo;
}

void T100GameFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100GameFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100GameFrame::OnPaint(wxPaintEvent& event)
{
    m_demo->Render();
}
