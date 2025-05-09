/***************************************************************
 * Name:      T100PainterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-13
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100PainterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100PainterFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100PainterCallback.h"
#include "wx\paint\view\T100WxPaintElementsPanel.h"
#include "wx\paint\view\T100WxPaintCtrl.h"

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
const long T100PainterFrame::ID_MENUITEM_NEW = wxNewId();
const long T100PainterFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100PainterFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100PainterFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100PainterFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100PainterFrame::idMenuQuit = wxNewId();
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
    AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemNew = new wxMenuItem(Menu1, ID_MENUITEM_NEW, _("New"), _("New"), wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENUITEM_OPEN, _("Open"), _("Open"), wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItemSave = new wxMenuItem(Menu1, ID_MENUITEM_SAVE, _("Save"), _("Save"), wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    MenuItemSaveAs = new wxMenuItem(Menu1, ID_MENUITEM_SAVE_AS, _("Save As"), _("Save As"), wxITEM_NORMAL);
    Menu1->Append(MenuItemSaveAs);
    MenuItemClose = new wxMenuItem(Menu1, ID_MENUITEM_CLOSE, _("Close"), _("Close"), wxITEM_NORMAL);
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

    Connect(ID_MENUITEM_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemNewSelected);
    Connect(ID_MENUITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemOpenSelected);
    Connect(ID_MENUITEM_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemSaveAsSelected);
    Connect(ID_MENUITEM_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemCloseSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnAbout);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&T100PainterFrame::OnResize);
    //*)

    create();
}

T100PainterFrame::~T100PainterFrame()
{
    //(*Destroy(T100PainterFrame)
    //*)

    AuiManager1->UnInit();
    destroy();
}

T100VOID T100PainterFrame::create()
{
    T100WxPaintElementsPanel*   panel   = T100NEW T100WxPaintElementsPanel(this);

    AuiManager1->AddPane(panel, wxAuiPaneInfo().Name(wxT("Elements")).MinSize(wxSize(300, -1)).Left());

    T100WxPaintCtrl*    paint = T100NEW T100WxPaintCtrl(this, wxID_ANY);

    AuiManager1->AddPane(paint, wxAuiPaneInfo().Name(wxT("Paint")).DefaultPane().CenterPane());
}

T100VOID T100PainterFrame::destroy()
{

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

void T100PainterFrame::OnResize(wxSizeEvent& event)
{
    AuiManager1->Update();
}

void T100PainterFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_new();
}

void T100PainterFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_open();
}

void T100PainterFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_save();
}

void T100PainterFrame::OnMenuItemSaveAsSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_save_as();
}

void T100PainterFrame::OnMenuItemCloseSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_close();
}
