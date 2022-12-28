#include "T100EditorFrame.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/menu.h>
#include "T100EditorCallback.h"

namespace T100Editor{

const long T100EditorFrame::ID_MENUITEM_NEW = wxNewId();
const long T100EditorFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100EditorFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100EditorFrame::ID_MENUITEM_QUIT = wxNewId();

const long T100EditorFrame::ID_MENUITEM_UNDO = wxNewId();
const long T100EditorFrame::ID_MENUITEM_REDO = wxNewId();
const long T100EditorFrame::ID_MENUITEM_CUT = wxNewId();
const long T100EditorFrame::ID_MENUITEM_COPY = wxNewId();
const long T100EditorFrame::ID_MENUITEM_PASTE = wxNewId();

const long T100EditorFrame::ID_MENUITEM_SEARCH = wxNewId();
const long T100EditorFrame::ID_MENUITEM_REPLACE = wxNewId();
const long T100EditorFrame::ID_MENUITEM_ABOUT = wxNewId();


BEGIN_EVENT_TABLE(T100EditorFrame,wxFrame)

END_EVENT_TABLE()


T100EditorFrame::T100EditorFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100EditorFrame::~T100EditorFrame()
{
    //dtor
    destroy();
}

void T100EditorFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	Move(wxDefaultPosition);

	create();
}

T100VOID T100EditorFrame::create()
{
    create_menu();
}

T100VOID T100EditorFrame::destroy()
{
}

T100BOOL T100EditorFrame::create_menu()
{
    wxMenuBar*      menuBar         = T100NEW wxMenuBar();
    wxMenu*         menuFile        = T100NEW wxMenu();
    wxMenu*         menuEdit        = T100NEW wxMenu();
    wxMenu*         menuSearch      = T100NEW wxMenu();
    wxMenu*         menuHelp        = T100NEW wxMenu();

    menuFile->Append(ID_MENUITEM_NEW, wxT("New"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_OPEN, wxT("Open"));
    menuFile->Append(ID_MENUITEM_CLOSE, wxT("Close"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_OPEN, wxT("Save"));
    menuFile->Append(ID_MENUITEM_CLOSE, wxT("Save as…"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_QUIT, wxT("Quit"));

    menuBar->Append(menuFile, wxT("File"));

    //

    menuEdit->Append(ID_MENUITEM_UNDO, wxT("Undo"));
    menuEdit->Append(ID_MENUITEM_REDO, wxT("Redo"));
    menuEdit->AppendSeparator();
    menuEdit->Append(ID_MENUITEM_CUT, wxT("Cut"));
    menuEdit->Append(ID_MENUITEM_COPY, wxT("Copy"));
    menuEdit->Append(ID_MENUITEM_PASTE, wxT("Paste"));

    menuBar->Append(menuEdit, wxT("Edit"));

    menuSearch->Append(ID_MENUITEM_SEARCH, wxT("Search…"));
    menuSearch->Append(ID_MENUITEM_REPLACE, wxT("Replace…"));

    menuBar->Append(menuSearch, wxT("Search"));

    menuHelp->Append(ID_MENUITEM_ABOUT, wxT("About…"));

    menuBar->Append(menuHelp, wxT("Help"));

    SetMenuBar(menuBar);

    //

    Connect(ID_MENUITEM_NEW,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuNewSelected);
    Connect(ID_MENUITEM_OPEN,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuOpenSelected);
    Connect(ID_MENUITEM_CLOSE,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuCloseSelected);
    Connect(ID_MENUITEM_SAVE,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,    wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuSaveAsSelected);
    Connect(ID_MENUITEM_QUIT,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuQuitSelected);

    Connect(ID_MENUITEM_UNDO,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuUndoSelected);
    Connect(ID_MENUITEM_REDO,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuRedoSelected);
    Connect(ID_MENUITEM_CUT,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuCutSelected);
    Connect(ID_MENUITEM_COPY,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuCopySelected);
    Connect(ID_MENUITEM_PASTE,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuPasteSelected);

    Connect(ID_MENUITEM_SEARCH,     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuSearchSelected);
    Connect(ID_MENUITEM_REPLACE,    wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuReplaceSelected);
    Connect(ID_MENUITEM_ABOUT,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100EditorFrame::OnMenuAboutSelected);

    return T100TRUE;
}

void T100EditorFrame::OnMenuNewSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_new();
}

void T100EditorFrame::OnMenuOpenSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_open();
}

void T100EditorFrame::OnMenuCloseSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_close();
}

void T100EditorFrame::OnMenuSaveSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_save();
}

void T100EditorFrame::OnMenuSaveAsSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_save_as();
}

void T100EditorFrame::OnMenuQuitSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_quit();
}

void T100EditorFrame::OnMenuUndoSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_undo();
}

void T100EditorFrame::OnMenuRedoSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_redo();
}

void T100EditorFrame::OnMenuCutSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_cut();
}

void T100EditorFrame::OnMenuCopySelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_copy();
}

void T100EditorFrame::OnMenuPasteSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_paste();
}

void T100EditorFrame::OnMenuSearchSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_search();
}

void T100EditorFrame::OnMenuReplaceSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_replace();
}

void T100EditorFrame::OnMenuAboutSelected(wxCommandEvent& event)
{
    T100EditorCallback::frame_menu_about();
}

}
