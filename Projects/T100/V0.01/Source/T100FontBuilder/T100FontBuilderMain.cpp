/***************************************************************
 * Name:      T100FontBuilderMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100FontBuilderMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100FontBuilderFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100FontBuilderApp.h"
#include "T100FontCallback.h"


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

//(*IdInit(T100FontBuilderFrame)
const long T100FontBuilderFrame::ID_CUSTOM1 = wxNewId();
const long T100FontBuilderFrame::idMenuQuit = wxNewId();
const long T100FontBuilderFrame::idMenuAbout = wxNewId();
const long T100FontBuilderFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100FontBuilderFrame,wxFrame)
    //(*EventTable(T100FontBuilderFrame)
    //*)
END_EVENT_TABLE()

T100FontBuilderFrame::T100FontBuilderFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100FontBuilderFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(410,600));
    Custom1 = new T100FontPanel(this,ID_CUSTOM1,wxPoint(224,136),wxDefaultSize);
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100FontBuilderFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100FontBuilderFrame::OnAbout);
    //*)

    create();
}

T100FontBuilderFrame::~T100FontBuilderFrame()
{
    //(*Destroy(T100FontBuilderFrame)
    //*)

    destroy();
}

T100VOID T100FontBuilderFrame::create()
{
    T100FontCallback::init(&wxGetApp().m_serve, &wxGetApp().m_view);
}

T100VOID T100FontBuilderFrame::destroy()
{

}

void T100FontBuilderFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100FontBuilderFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
