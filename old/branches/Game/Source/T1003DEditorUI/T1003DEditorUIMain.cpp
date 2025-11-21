/***************************************************************
 * Name:      T1003DEditorUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-03-02
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T1003DEditorUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T1003DEditorUIFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(T1003DEditorUIFrame)
const long T1003DEditorUIFrame::ID_MENU_NEW = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_OPEN = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_CLOSE = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_SAVE = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_SAVE_AS = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_IMPORT = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_EXPORT = wxNewId();
const long T1003DEditorUIFrame::idMenuQuit = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_UNDO = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_REDO = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_CUT = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_COPY = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_PASTE = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_MANAGER = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_PROPERTIES = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_CONFIG = wxNewId();
const long T1003DEditorUIFrame::ID_MENU_SETTINGS = wxNewId();
const long T1003DEditorUIFrame::idMenuAbout = wxNewId();
const long T1003DEditorUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T1003DEditorUIFrame,wxFrame)
    //(*EventTable(T1003DEditorUIFrame)
    //*)
    EVT_AUI_PANE_CLOSE(T1003DEditorUIFrame::OnAuiPaneClose)
END_EVENT_TABLE()

T1003DEditorUIFrame::T1003DEditorUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T1003DEditorUIFrame)
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
    MenuItemClose = new wxMenuItem(Menu1, ID_MENU_CLOSE, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemClose);
    Menu1->AppendSeparator();
    MenuItemSave = new wxMenuItem(Menu1, ID_MENU_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    MenuItemSaveAs = new wxMenuItem(Menu1, ID_MENU_SAVE_AS, _("Save as"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemSaveAs);
    Menu1->AppendSeparator();
    MenuItemImport = new wxMenuItem(Menu1, ID_MENU_IMPORT, _("Import"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemImport);
    MenuItemExport = new wxMenuItem(Menu1, ID_MENU_EXPORT, _("Export"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItemExport);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu4 = new wxMenu();
    MenuItemUndo = new wxMenuItem(Menu4, ID_MENU_UNDO, _("Undo"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItemUndo);
    MenuItemRedo = new wxMenuItem(Menu4, ID_MENU_REDO, _("Redo"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItemRedo);
    Menu4->AppendSeparator();
    MenuItemCut = new wxMenuItem(Menu4, ID_MENU_CUT, _("Cut"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItemCut);
    MenuItemCopy = new wxMenuItem(Menu4, ID_MENU_COPY, _("Copy"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItemCopy);
    MenuItemPaste = new wxMenuItem(Menu4, ID_MENU_PASTE, _("Paste"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItemPaste);
    MenuBar1->Append(Menu4, _("Edit"));
    Menu5 = new wxMenu();
    MenuItemManager = new wxMenuItem(Menu5, ID_MENU_MANAGER, _("Manager"), wxEmptyString, wxITEM_CHECK);
    Menu5->Append(MenuItemManager);
    MenuItemProperties = new wxMenuItem(Menu5, ID_MENU_PROPERTIES, _("Properties"), wxEmptyString, wxITEM_CHECK);
    Menu5->Append(MenuItemProperties);
    MenuBar1->Append(Menu5, _("View"));
    Menu3 = new wxMenu();
    MenuItemConfig = new wxMenuItem(Menu3, ID_MENU_CONFIG, _("Config"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemConfig);
    MenuItemSettings = new wxMenuItem(Menu3, ID_MENU_SETTINGS, _("Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemSettings);
    MenuBar1->Append(Menu3, _("Settings"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[5] = { -5, -10, -30, -10, -10 };
    int __wxStatusBarStyles_1[5] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(5,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(5,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_MENU_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemNewSelected);
    Connect(ID_MENU_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemOpenSelected);
    Connect(ID_MENU_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemCloseSelected);
    Connect(ID_MENU_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemSaveSelected);
    Connect(ID_MENU_SAVE_AS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemSaveAsSelected);
    Connect(ID_MENU_IMPORT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemImportSelected);
    Connect(ID_MENU_EXPORT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemExportSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnQuit);
    Connect(ID_MENU_UNDO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemUndoSelected);
    Connect(ID_MENU_REDO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemRedoSelected);
    Connect(ID_MENU_CUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemCutSelected);
    Connect(ID_MENU_COPY,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemCopySelected);
    Connect(ID_MENU_PASTE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemPasteSelected);
    Connect(ID_MENU_MANAGER,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemManagerSelected);
    Connect(ID_MENU_PROPERTIES,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemPropertiesSelected);
    Connect(ID_MENU_CONFIG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemConfigSelected);
    Connect(ID_MENU_SETTINGS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnMenuItemSettingsSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorUIFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T1003DEditorUIFrame::OnClose);
    //*)

    init();
}

T1003DEditorUIFrame::~T1003DEditorUIFrame()
{
    //(*Destroy(T1003DEditorUIFrame)
    //*)

    uninit();
}

T100VOID T1003DEditorUIFrame::init()
{
    Maximize();
    T1003DEditorCallback::Create(this);
}

T100VOID T1003DEditorUIFrame::uninit()
{
    T1003DEditorCallback::Destroy();
}

void T1003DEditorUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T1003DEditorUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T1003DEditorUIFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
}

void T1003DEditorUIFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuNew();
}

void T1003DEditorUIFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuOpen();
}

void T1003DEditorUIFrame::OnMenuItemCloseSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuClose();
}

void T1003DEditorUIFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuSave();
}

void T1003DEditorUIFrame::OnMenuItemSaveAsSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuSaveAs();
}

void T1003DEditorUIFrame::OnMenuItemUndoSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuUndo();
}

void T1003DEditorUIFrame::OnMenuItemRedoSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuRedo();
}

void T1003DEditorUIFrame::OnMenuItemCutSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuCut();
}

void T1003DEditorUIFrame::OnMenuItemCopySelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuCopy();
}

void T1003DEditorUIFrame::OnMenuItemPasteSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuPaste();
}

void T1003DEditorUIFrame::OnMenuItemManagerSelected(wxCommandEvent& event)
{
    T100BOOL    flag    = event.IsChecked();
    T1003DEditorCallback::MenuManager(flag);
}

void T1003DEditorUIFrame::OnMenuItemPropertiesSelected(wxCommandEvent& event)
{
    T100BOOL    flag    = event.IsChecked();
    T1003DEditorCallback::MenuProperties(flag);
}

void T1003DEditorUIFrame::OnMenuItemConfigSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuConfig();
}

T100VOID T1003DEditorUIFrame::SetStatus(T100UINT id, wxString msg)
{
    StatusBar1->SetStatusText(msg, --id);
}

void T1003DEditorUIFrame::OnAuiPaneClose(wxAuiManagerEvent& event)
{
    T100WSTRING     name;

    name    = event.GetPane()->name.ToStdWstring();

    T1003DEditorCallback::SetMenu(name, T100FALSE);
}

void T1003DEditorUIFrame::OnMenuItemImportSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuImport();
}

void T1003DEditorUIFrame::OnMenuItemExportSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuExport();
}

void T1003DEditorUIFrame::OnMenuItemSettingsSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuSettings();
}
