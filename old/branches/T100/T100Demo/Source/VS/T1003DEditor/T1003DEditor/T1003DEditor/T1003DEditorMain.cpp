/***************************************************************
 * Name:      T1003DEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-03-18
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T1003DEditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T1003DEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "skeletal/T1003DEditorCallback.h"

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

//(*IdInit(T1003DEditorFrame)
const long T1003DEditorFrame::idMenuQuit = wxNewId();
const long T1003DEditorFrame::idMenuAbout = wxNewId();
const long T1003DEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T1003DEditorFrame,wxFrame)
    //(*EventTable(T1003DEditorFrame)
    //*)
END_EVENT_TABLE()

T1003DEditorFrame::T1003DEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T1003DEditorFrame)
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
    int __wxStatusBarWidths_1[5] = { -5, -5, -10, -20, -10 };
    int __wxStatusBarStyles_1[5] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(5,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(5,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnAbout);
    //*)

    init();
}

T1003DEditorFrame::~T1003DEditorFrame()
{
    //(*Destroy(T1003DEditorFrame)
    //*)

    uninit();
}

T100VOID T1003DEditorFrame::init()
{
    Maximize();
    T1003DEditorCallback::Create(this);
}

T100VOID T1003DEditorFrame::uninit()
{
    T1003DEditorCallback::Destroy();
}

void T1003DEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T1003DEditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

T100VOID T1003DEditorFrame::SetStatus(T100UINT id, wxString msg)
{
    StatusBar1->SetStatusText(msg, --id);
}
