/***************************************************************
 * Name:      T100EditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100EditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100EditorFrame)
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


#include "T100EditorCallback.h"

//(*IdInit(T100EditorFrame)
const long T100EditorFrame::ID_MENUITEM_NEW = wxNewId();
const long T100EditorFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100EditorFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100EditorFrame::idMenuQuit = wxNewId();
const long T100EditorFrame::ID_MENUITEM1 = wxNewId();
const long T100EditorFrame::ID_MENUITEM2 = wxNewId();
const long T100EditorFrame::ID_MENUITEM3 = wxNewId();
const long T100EditorFrame::ID_MENUITEM4 = wxNewId();
const long T100EditorFrame::ID_MENUITEM5 = wxNewId();
const long T100EditorFrame::ID_MENUITEM6 = wxNewId();
const long T100EditorFrame::ID_MENUITEM7 = wxNewId();
const long T100EditorFrame::idMenuAbout = wxNewId();
const long T100EditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100EditorFrame,wxFrame)
    //(*EventTable(T100EditorFrame)
    //*)
END_EVENT_TABLE()

T100EditorFrame::T100EditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100EditorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemNew = new wxMenuItem(Menu1, ID_MENUITEM_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENUITEM_OPEN, _("Open..."), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItemClose = new wxMenuItem(Menu1, ID_MENUITEM_CLOSE, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemClose);
    Menu1->AppendSeparator();
    MenuItemSave = new wxMenuItem(Menu1, ID_MENUITEM_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    MenuItemSaveAs = new wxMenuItem(Menu1, ID_MENUITEM_SAVE_AS, _("Save As..."), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSaveAs);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Undo"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("Redo"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    Menu3->AppendSeparator();
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Cut"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Copy"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu3, ID_MENUITEM5, _("Paste"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu4 = new wxMenu();
    MenuBar1->Append(Menu4, _("View"));
    Menu5 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu5, ID_MENUITEM6, _("Find"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem8);
    Menu5->AppendSeparator();
    MenuItem9 = new wxMenuItem(Menu5, ID_MENUITEM7, _("Replace"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem9);
    MenuBar1->Append(Menu5, _("Search"));
    Menu6 = new wxMenu();
    MenuBar1->Append(Menu6, _("Settings"));
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

    Connect(ID_MENUITEM_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemNewSelected);
    Connect(ID_MENUITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemOpenSelected);
    Connect(ID_MENUITEM_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemCloseSelected);
    Connect(ID_MENUITEM_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemSaveAsSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnAbout);
    //*)
}

T100EditorFrame::~T100EditorFrame()
{
    //(*Destroy(T100EditorFrame)
    //*)
}

void T100EditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100EditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100EditorFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuNewSelected();
}

void T100EditorFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuOpenSelected();
}

void T100EditorFrame::OnMenuItemCloseSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuCloseSelected();
}

void T100EditorFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuSaveSelected();
}

void T100EditorFrame::OnMenuItemSaveAsSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuSaveAsSelected();
}
