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
const long T100EditorFrame::ID_AUITOOLBARITEM1 = wxNewId();
const long T100EditorFrame::ID_AUITOOLBAR1 = wxNewId();
const long T100EditorFrame::ID_MENUITEM_NEW = wxNewId();
const long T100EditorFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100EditorFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100EditorFrame::idMenuQuit = wxNewId();
const long T100EditorFrame::ID_MENUITEM_UNDO = wxNewId();
const long T100EditorFrame::ID_MENUITEM_REDO = wxNewId();
const long T100EditorFrame::ID_MENUITEM_CUT = wxNewId();
const long T100EditorFrame::ID_MENUITEM_COPY = wxNewId();
const long T100EditorFrame::ID_MENUITEM_PASTE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_FIND = wxNewId();
const long T100EditorFrame::ID_MENUITEM_REPLACE = wxNewId();
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
    AuiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    AuiToolBar1 = new wxAuiToolBar(this, ID_AUITOOLBAR1, wxPoint(135,253), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBar1->AddTool(ID_AUITOOLBARITEM1, _("Item label"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBar1->Realize();
    AuiManager->AddPane(AuiToolBar1, wxAuiPaneInfo().Name(_T("PaneName0")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());
    AuiManager->Update();
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
    MenuBar1->Append(Menu4, _("View"));
    Menu5 = new wxMenu();
    MenuItemFind = new wxMenuItem(Menu5, ID_MENUITEM_FIND, _("Find"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItemFind);
    Menu5->AppendSeparator();
    MenuItemReplace = new wxMenuItem(Menu5, ID_MENUITEM_REPLACE, _("Replace"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItemReplace);
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
    Connect(ID_MENUITEM_UNDO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemUndoSelected);
    Connect(ID_MENUITEM_REDO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemRedoSelected);
    Connect(ID_MENUITEM_CUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemCutSelected);
    Connect(ID_MENUITEM_COPY,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemCopySelected);
    Connect(ID_MENUITEM_PASTE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemPasteSelected);
    Connect(ID_MENUITEM_FIND,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemFindSelected);
    Connect(ID_MENUITEM_REPLACE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnMenuItemReplaceSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100EditorFrame::OnAbout);
    //*)

    create();
}

T100EditorFrame::~T100EditorFrame()
{
    //(*Destroy(T100EditorFrame)
    //*)

    destroy();
}

T100VOID T100EditorFrame::create()
{

}

T100VOID T100EditorFrame::destroy()
{
    AuiManager->UnInit();
}

wxAuiManager* T100EditorFrame::getAuiManager()
{
    return AuiManager;
}

void T100EditorFrame::OnQuit(wxCommandEvent& event)
{
    //Close();
    T100EditorCallback::OnMenuQuitSelected();
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

void T100EditorFrame::OnMenuItemUndoSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuUndoSelected();
}

void T100EditorFrame::OnMenuItemRedoSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuRedoSelected();
}

void T100EditorFrame::OnMenuItemCutSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuCutSelected();
}

void T100EditorFrame::OnMenuItemCopySelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuCopySelected();
}

void T100EditorFrame::OnMenuItemPasteSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuPasteSelected();
}

void T100EditorFrame::OnMenuItemFindSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuFindSelected();
}

void T100EditorFrame::OnMenuItemReplaceSelected(wxCommandEvent& event)
{
    T100EditorCallback::OnMenuReplaceSelected();
}
