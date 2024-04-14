/***************************************************************
 * Name:      T100PainterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-04-14
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100PainterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100PainterFrame)
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

//(*IdInit(T100PainterFrame)
const long T100PainterFrame::ID_MENUITEM1 = wxNewId();
const long T100PainterFrame::ID_MENUITEM2 = wxNewId();
const long T100PainterFrame::ID_MENUITEM3 = wxNewId();
const long T100PainterFrame::ID_MENUITEM4 = wxNewId();
const long T100PainterFrame::ID_MENUITEM5 = wxNewId();
const long T100PainterFrame::idMenuQuit = wxNewId();
const long T100PainterFrame::ID_MENUITEM6 = wxNewId();
const long T100PainterFrame::ID_MENUITEM7 = wxNewId();
const long T100PainterFrame::ID_MENUITEM8 = wxNewId();
const long T100PainterFrame::ID_MENUITEM9 = wxNewId();
const long T100PainterFrame::ID_MENUITEM10 = wxNewId();
const long T100PainterFrame::ID_MENUITEM11 = wxNewId();
const long T100PainterFrame::ID_MENUITEM12 = wxNewId();
const long T100PainterFrame::ID_MENUITEM13 = wxNewId();
const long T100PainterFrame::idMenuAbout = wxNewId();
const long T100PainterFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PainterFrame,wxFrame)
    //(*EventTable(T100PainterFrame)
    //*)
END_EVENT_TABLE()

T100PainterFrame::T100PainterFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100PainterFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu1, ID_MENUITEM3, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    Menu1->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu1, ID_MENUITEM5, _("Save As"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu3, ID_MENUITEM6, _("Undo"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(Menu3, ID_MENUITEM7, _("Redo"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem9);
    Menu3->AppendSeparator();
    MenuItem10 = new wxMenuItem(Menu3, ID_MENUITEM8, _("Cut"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(Menu3, ID_MENUITEM9, _("Copy"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem11);
    MenuItem12 = new wxMenuItem(Menu3, ID_MENUITEM10, _("Paste"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem12);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu4 = new wxMenu();
    MenuItem13 = new wxMenuItem(Menu4, ID_MENUITEM11, _("Toolbars"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem13);
    MenuItem14 = new wxMenuItem(Menu4, ID_MENUITEM12, _("Panels"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem14);
    MenuBar1->Append(Menu4, _("View"));
    Menu5 = new wxMenu();
    MenuItem15 = new wxMenuItem(Menu5, ID_MENUITEM13, _("Config"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem15);
    MenuBar1->Append(Menu5, _("Setting"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnAbout);
    //*)
}

T100PainterFrame::~T100PainterFrame()
{
    //(*Destroy(T100PainterFrame)
    //*)
}

void T100PainterFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100PainterFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
