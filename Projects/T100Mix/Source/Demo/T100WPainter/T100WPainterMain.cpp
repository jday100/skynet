/***************************************************************
 * Name:      T100WPainterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-24
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WPainterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100WPainterFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100WPainterCallback.h"

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

//(*IdInit(T100WPainterFrame)
const long T100WPainterFrame::ID_MENUITEM_NEW = wxNewId();
const long T100WPainterFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100WPainterFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100WPainterFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100WPainterFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100WPainterFrame::idMenuQuit = wxNewId();
const long T100WPainterFrame::idMenuAbout = wxNewId();
const long T100WPainterFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100WPainterFrame,wxFrame)
    //(*EventTable(T100WPainterFrame)
    //*)
END_EVENT_TABLE()

T100WPainterFrame::T100WPainterFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100WPainterFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemNew = new wxMenuItem(Menu1, ID_MENUITEM_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENUITEM_OPEN, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItemSave = new wxMenuItem(Menu1, ID_MENUITEM_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    MenuItemSaveAs = new wxMenuItem(Menu1, ID_MENUITEM_SAVE_AS, _("Save As"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSaveAs);
    MenuItemClose = new wxMenuItem(Menu1, ID_MENUITEM_CLOSE, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemClose);
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

    Connect(ID_MENUITEM_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnMenuItemNewSelected);
    Connect(ID_MENUITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnMenuItemOpenSelected);
    Connect(ID_MENUITEM_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnMenuItemSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnMenuItemSaveAsSelected);
    Connect(ID_MENUITEM_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnMenuItemCloseSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WPainterFrame::OnAbout);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&T100WPainterFrame::OnResize);
    //*)

    create();
}

T100WPainterFrame::~T100WPainterFrame()
{
    //(*Destroy(T100WPainterFrame)
    //*)

    destroy();
}

T100VOID T100WPainterFrame::create()
{
    SetSize(800, 600);
}

T100VOID T100WPainterFrame::destroy()
{
    AuiManager1->UnInit();
}

void T100WPainterFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100WPainterFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100WPainterFrame::OnResize(wxSizeEvent& event)
{
    AuiManager1->Update();
}

void T100WPainterFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    T100WPainterCallback::frame_menu_new();
}

void T100WPainterFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    T100WPainterCallback::frame_menu_open();
}

void T100WPainterFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    T100WPainterCallback::frame_menu_save();
}

void T100WPainterFrame::OnMenuItemSaveAsSelected(wxCommandEvent& event)
{
    T100WPainterCallback::frame_menu_save_as();
}

void T100WPainterFrame::OnMenuItemCloseSelected(wxCommandEvent& event)
{
    T100WPainterCallback::frame_menu_close();
}
