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

#include "T100PainterCallback.h"

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
const long T100PainterFrame::ID_AUITOOLBARITEM1 = wxNewId();
const long T100PainterFrame::ID_AUITOOLBARLABEL1 = wxNewId();
const long T100PainterFrame::ID_AUITOOLBAR1 = wxNewId();
const long T100PainterFrame::ID_MENUITEM_NEW = wxNewId();
const long T100PainterFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100PainterFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100PainterFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100PainterFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100PainterFrame::ID_MENUITEM_QUIT = wxNewId();
const long T100PainterFrame::ID_MENUITEM_UNDO = wxNewId();
const long T100PainterFrame::ID_MENUITEM_REDO = wxNewId();
const long T100PainterFrame::ID_MENUITEM_CUT = wxNewId();
const long T100PainterFrame::ID_MENUITEM_COPY = wxNewId();
const long T100PainterFrame::ID_MENUITEM_PASTE = wxNewId();
const long T100PainterFrame::ID_MENUITEM11 = wxNewId();
const long T100PainterFrame::ID_MENUITEM12 = wxNewId();
const long T100PainterFrame::ID_MENUITEM_CONFIG = wxNewId();
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
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItemQuit;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    AuiToolBar1 = new wxAuiToolBar(this, ID_AUITOOLBAR1, wxPoint(61,39), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBar1->AddTool(ID_AUITOOLBARITEM1, _("Item label"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBar1->AddLabel(ID_AUITOOLBARLABEL1, _("Item label"));
    AuiToolBar1->Realize();
    AuiManager1->AddPane(AuiToolBar1, wxAuiPaneInfo().Name(_T("PaneName0")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());
    AuiManager1->Update();
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemNew = new wxMenuItem(Menu1, ID_MENUITEM_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENUITEM_OPEN, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItemClose = new wxMenuItem(Menu1, ID_MENUITEM_CLOSE, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemClose);
    Menu1->AppendSeparator();
    MenuItemSave = new wxMenuItem(Menu1, ID_MENUITEM_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    MenuItemSaveAs = new wxMenuItem(Menu1, ID_MENUITEM_SAVE_AS, _("Save As"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSaveAs);
    Menu1->AppendSeparator();
    MenuItemQuit = new wxMenuItem(Menu1, ID_MENUITEM_QUIT, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItemQuit);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItemUndo = new wxMenuItem(Menu3, ID_MENUITEM_UNDO, _("Undo"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemUndo);
    MenuItemRedo = new wxMenuItem(Menu3, ID_MENUITEM_REDO, _("Redo"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemRedo);
    Menu3->AppendSeparator();
    MenuItemCut = new wxMenuItem(Menu3, ID_MENUITEM_CUT, _("Cut"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemCut);
    MenuItemCopy = new wxMenuItem(Menu3, ID_MENUITEM_COPY, _("Copy"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemCopy);
    MenuItemPaste = new wxMenuItem(Menu3, ID_MENUITEM_PASTE, _("Paste"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemPaste);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu4 = new wxMenu();
    MenuItem13 = new wxMenuItem(Menu4, ID_MENUITEM11, _("Toolbars"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem13);
    MenuItem14 = new wxMenuItem(Menu4, ID_MENUITEM12, _("Panels"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem14);
    MenuBar1->Append(Menu4, _("View"));
    Menu5 = new wxMenu();
    MenuItemConfig = new wxMenuItem(Menu5, ID_MENUITEM_CONFIG, _("Config"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItemConfig);
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

    Connect(ID_MENUITEM_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemNewSelected);
    Connect(ID_MENUITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemOpenSelected);
    Connect(ID_MENUITEM_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemCloseSelected);
    Connect(ID_MENUITEM_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemSaveAsSelected);
    Connect(ID_MENUITEM_QUIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnQuit);
    Connect(ID_MENUITEM_UNDO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemUndoSelected);
    Connect(ID_MENUITEM_REDO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemRedoSelected);
    Connect(ID_MENUITEM_CUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemCutSelected);
    Connect(ID_MENUITEM_COPY,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemCopySelected);
    Connect(ID_MENUITEM_PASTE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemPasteSelected);
    Connect(ID_MENUITEM_CONFIG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnMenuItemConfigSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PainterFrame::OnAbout);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&T100PainterFrame::OnResize);
    //*)
    create();
}

T100PainterFrame::~T100PainterFrame()
{
    //(*Destroy(T100PainterFrame)
    //*)
    destroy();
}

T100VOID T100PainterFrame::create()
{

}

T100VOID T100PainterFrame::destroy()
{
    AuiManager1->UnInit();
}

wxAuiManager* T100PainterFrame::getAuiManager()
{
    return AuiManager1;
}

void T100PainterFrame::OnQuit(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_quit();

    Close();
}

void T100PainterFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100PainterFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_new();
}

void T100PainterFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_open();
}

void T100PainterFrame::OnMenuItemCloseSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_close();
}

void T100PainterFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_save();
}

void T100PainterFrame::OnMenuItemSaveAsSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_save_as();
}

void T100PainterFrame::OnMenuItemUndoSelected(wxCommandEvent& event)
{
}

void T100PainterFrame::OnMenuItemRedoSelected(wxCommandEvent& event)
{
}

void T100PainterFrame::OnMenuItemCutSelected(wxCommandEvent& event)
{
}

void T100PainterFrame::OnMenuItemCopySelected(wxCommandEvent& event)
{
}

void T100PainterFrame::OnMenuItemPasteSelected(wxCommandEvent& event)
{
}

void T100PainterFrame::OnMenuItemConfigSelected(wxCommandEvent& event)
{
}

void T100PainterFrame::OnResize(wxSizeEvent& event)
{
    AuiManager1->Update();
}
