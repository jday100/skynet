/***************************************************************
 * Name:      T100ThreadMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ThreadMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100ThreadFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/filedlg.h>
#include "T100OpenThreadTask.h"

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

//(*IdInit(T100ThreadFrame)
const long T100ThreadFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100ThreadFrame::idMenuQuit = wxNewId();
const long T100ThreadFrame::idMenuAbout = wxNewId();
const long T100ThreadFrame::ID_STATUSBAR1 = wxNewId();
//*)

const long T100ThreadFrame::ID_THREAD_OPEN = wxNewId();

BEGIN_EVENT_TABLE(T100ThreadFrame,wxFrame)
    //(*EventTable(T100ThreadFrame)
    //*)
    EVT_THREAD(ID_THREAD_OPEN, T100ThreadFrame::OnThreadOpen)
END_EVENT_TABLE()

T100ThreadFrame::T100ThreadFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100ThreadFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENUITEM_OPEN, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { -1, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_MENUITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100ThreadFrame::OnMenuItemOpenSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100ThreadFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100ThreadFrame::OnAbout);
    //*)
}

T100ThreadFrame::~T100ThreadFrame()
{
    //(*Destroy(T100ThreadFrame)
    //*)
}

void T100ThreadFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100ThreadFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100ThreadFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    wxFileDialog        dialog(this);

    if(wxID_OK == dialog.ShowModal()){
        T100OpenThreadTask*     task    = new T100OpenThreadTask(this);

        //m_gauge = new wxGauge(&StatusBar1->GetField(2));
        m_gauge = new wxGauge(StatusBar1, wxID_ANY, 100);
        task->start();
    }
}

void T100ThreadFrame::OnThreadOpen(wxThreadEvent& event)
{
    int         result;

    result  = event.GetInt();

    m_gauge->SetValue(result);
}
