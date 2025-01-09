/***************************************************************
 * Name:      T100FireMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-05
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100FireMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100FireFrame)
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

//(*IdInit(T100FireFrame)
const long T100FireFrame::idMenuQuit = wxNewId();
const long T100FireFrame::idMenuAbout = wxNewId();
const long T100FireFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100FireFrame,wxFrame)
    //(*EventTable(T100FireFrame)
    //*)
END_EVENT_TABLE()

T100FireFrame::T100FireFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100FireFrame)
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100FireFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100FireFrame::OnAbout);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100FireFrame::OnPaint);
    Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&T100FireFrame::OnKeyDown);
    Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&T100FireFrame::OnKeyUp);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&T100FireFrame::OnResize);
    //*)

    create();
}

T100FireFrame::~T100FireFrame()
{
    //(*Destroy(T100FireFrame)
    //*)

    destroy();
}

T100VOID T100FireFrame::create()
{
    Maximize();

    m_game  = T100NEW T100FireGame();

    m_game->Create(GetHWND(), GetClientSize().GetWidth(), GetClientSize().GetHeight());

    m_game->Load();
}

T100VOID T100FireFrame::destroy()
{
    T100SAFE_DELETE m_game;
}

void T100FireFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100FireFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100FireFrame::OnPaint(wxPaintEvent& event)
{
    m_game->Render();
    Refresh();
}

void T100FireFrame::OnKeyDown(wxKeyEvent& event)
{
    m_game->OnKeyDown(event.GetKeyCode());
    Refresh();
}

void T100FireFrame::OnKeyUp(wxKeyEvent& event)
{
    m_game->OnKeyUp(event.GetKeyCode());
    Refresh();
}

void T100FireFrame::OnResize(wxSizeEvent& event)
{
    m_game->SetSize(event.GetSize().GetWidth(), event.GetSize().GetHeight());
    Refresh();
}
