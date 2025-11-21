/***************************************************************
 * Name:      T1003DEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-01-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T1003DEditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T1003DEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <iostream>
#include <thread>
#include <wx/dcclient.h>

#include "T1003DEditorSkeletal.h"
#include "T1003DEditorView.h"
#include "T1003DEditorCallback.h"

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
const long T1003DEditorFrame::ID_MENU_NEW = wxNewId();
const long T1003DEditorFrame::ID_MENU_OPEN = wxNewId();
const long T1003DEditorFrame::ID_MENUITEM3 = wxNewId();
const long T1003DEditorFrame::ID_MENU_SAVE = wxNewId();
const long T1003DEditorFrame::ID_MENUITEM5 = wxNewId();
const long T1003DEditorFrame::idMenuQuit = wxNewId();
const long T1003DEditorFrame::ID_MENUITEM_CONFIG = wxNewId();
const long T1003DEditorFrame::idMenuAbout = wxNewId();
const long T1003DEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T1003DEditorFrame,wxFrame)
    //(*EventTable(T1003DEditorFrame)
    //*)
    //EVT_IDLE(T1003DEditorFrame::OnIdle)
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
    MenuItemNew = new wxMenuItem(Menu1, ID_MENU_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENU_OPEN, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItem5 = new wxMenuItem(Menu1, ID_MENUITEM3, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    Menu1->AppendSeparator();
    MenuItemSave = new wxMenuItem(Menu1, ID_MENU_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    MenuItem7 = new wxMenuItem(Menu1, ID_MENUITEM5, _("Save As"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItemConfig = new wxMenuItem(Menu3, ID_MENUITEM_CONFIG, _("Config"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemConfig);
    MenuBar1->Append(Menu3, _("Settings"));
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
    static const char *ImageList1_0_XPM[] = {
    "64 64 2 1",
    ". c Black",
    "_ c None",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "______________________________..._______________________________",
    "_____________________________.....______________________________",
    "____________________________......._____________________________",
    "____________________________......._____________________________",
    "____________________________......._____________________________",
    "_____________________________.....______________________________",
    "______________________________..._______________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________",
    "________________________________________________________________"
    };
    ImageList1 = new wxImageList(64, 64, 2);
    ImageList1->Add(wxBitmap(ImageList1_0_XPM));

    Connect(ID_MENU_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnMenuItemNewSelected);
    Connect(ID_MENU_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnMenuItemOpenSelected);
    Connect(ID_MENU_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnMenuItemSaveSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnQuit);
    Connect(ID_MENUITEM_CONFIG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnMenuItemConfigSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnAbout);
    Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&T1003DEditorFrame::OnKeyDown);
    Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&T1003DEditorFrame::OnKeyUp);
    Connect(wxEVT_CHAR,(wxObjectEventFunction)&T1003DEditorFrame::OnChar);
    Connect(wxEVT_MOTION,(wxObjectEventFunction)&T1003DEditorFrame::OnMouseMove);
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

    m_skeletal  = T100NEW T1003DEditorSkeletal();
    m_skeletal->GetView()->Create(this);
}

T100VOID T1003DEditorFrame::uninit()
{
    T100SAFE_DELETE m_skeletal;
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

void T1003DEditorFrame::OnMenuItemConfigSelected(wxCommandEvent& event)
{
    m_skeletal->GetView()->ShowConfigDialog();
}

void T1003DEditorFrame::OnKeyDown(wxKeyEvent& event)
{
    T1003DEditorCallback::KeyDown(event.GetKeyCode());
}

void T1003DEditorFrame::OnKeyUp(wxKeyEvent& event)
{
    T1003DEditorCallback::KeyUp(event.GetKeyCode());
}

void T1003DEditorFrame::OnChar(wxKeyEvent& event)
{
}

void T1003DEditorFrame::OnMouseMove(wxMouseEvent& event)
{

}

void T1003DEditorFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    m_skeletal->New();
}

void T1003DEditorFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    m_skeletal->Open();
}

void T1003DEditorFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    m_skeletal->Save();
}
