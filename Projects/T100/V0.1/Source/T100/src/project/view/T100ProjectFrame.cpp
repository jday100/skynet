#include "T100ProjectFrame.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/menu.h>
#include "T100ProjectCallback.h"

namespace T100PROJECT{

const long T100ProjectFrame::ID_MENUITEM_NEW = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_SAVE = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_SAVE_AS = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_QUIT = wxNewId();

const long T100ProjectFrame::ID_MENUITEM_UNDO = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_REDO = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_CUT = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_COPY = wxNewId();
const long T100ProjectFrame::ID_MENUITEM_PASTE = wxNewId();

const long T100ProjectFrame::ID_MENUITEM_PROJECTS = wxNewId();

const long T100ProjectFrame::ID_MENUITEM_ABOUT = wxNewId();


BEGIN_EVENT_TABLE(T100ProjectFrame,wxFrame)

END_EVENT_TABLE()

T100ProjectFrame::T100ProjectFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100ProjectFrame::~T100ProjectFrame()
{
    //dtor
    destroy();
}

void T100ProjectFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxEmptyString, pos, size, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);

	create();
}

T100VOID T100ProjectFrame::create()
{
    create_menu();
}

T100VOID T100ProjectFrame::destroy()
{

}

T100BOOL T100ProjectFrame::create_menu()
{
    wxMenuBar*      menuBar         = T100NEW wxMenuBar();
    wxMenu*         menuFile        = T100NEW wxMenu();
    wxMenu*         menuHelp        = T100NEW wxMenu();

    menuFile->Append(ID_MENUITEM_NEW, wxT("New"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_OPEN, wxT("Open…"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_QUIT, wxT("Quit"));

    menuBar->Append(menuFile, wxT("File"));

    menuHelp->Append(ID_MENUITEM_ABOUT, wxT("About…"));

    menuBar->Append(menuHelp, wxT("Help"));

    SetMenuBar(menuBar);

    Connect(ID_MENUITEM_NEW,            wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuNewSelected);
    Connect(ID_MENUITEM_OPEN,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuOpenSelected);
    Connect(ID_MENUITEM_QUIT,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuQuitSelected);

    Connect(ID_MENUITEM_ABOUT,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuAboutSelected);

    return T100TRUE;
}

T100BOOL T100ProjectFrame::update_menu()
{
    wxMenuBar*      menuBar         = T100NULL;

    menuBar = GetMenuBar();

    wxMenu*         menuEdit        = T100NEW wxMenu();
    wxMenu*         menuView        = T100NEW wxMenu();

    wxMenu*         menuFile        = T100NULL;

    menuFile    = menuBar->GetMenu(0);

    menuFile->Insert(3, ID_MENUITEM_CLOSE, wxT("Close"));
    menuFile->InsertSeparator(4);
    menuFile->Insert(5, ID_MENUITEM_SAVE, wxT("Save"));
    menuFile->Insert(6, ID_MENUITEM_SAVE_AS, wxT("Save as…"));

    menuEdit->Append(ID_MENUITEM_UNDO, wxT("Undo"));
    menuEdit->Append(ID_MENUITEM_REDO, wxT("Redo"));
    menuEdit->AppendSeparator();
    menuEdit->Append(ID_MENUITEM_CUT, wxT("Cut"));
    menuEdit->Append(ID_MENUITEM_COPY, wxT("Copy"));
    menuEdit->Append(ID_MENUITEM_PASTE, wxT("Paste"));

    menuBar->Insert(1, menuEdit, wxT("Edit"));

    menuView->Append(ID_MENUITEM_PROJECTS, wxT("Projects"));

    menuBar->Insert(2, menuView, wxT("View"));

    Connect(ID_MENUITEM_CLOSE,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuCloseSelected);
    Connect(ID_MENUITEM_SAVE,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuSaveAsSelected);

    Connect(ID_MENUITEM_UNDO,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuUndoSelected);
    Connect(ID_MENUITEM_REDO,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuRedoSelected);
    Connect(ID_MENUITEM_CUT,            wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuCutSelected);
    Connect(ID_MENUITEM_COPY,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuCopySelected);
    Connect(ID_MENUITEM_PASTE,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuPasteSelected);

    Connect(ID_MENUITEM_PROJECTS,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100ProjectFrame::OnMenuProjectsSelected);

    return T100TRUE;
}

T100BOOL T100ProjectFrame::reset_menu()
{
    wxMenuBar*      menuBar         = T100NULL;
    wxMenu*         menuFile        = T100NULL;

    menuBar = GetMenuBar();

    menuBar->Remove(1);
    menuBar->Remove(1);

    menuFile    = menuBar->GetMenu(0);

    menuFile->Remove(ID_MENUITEM_CLOSE);
    menuFile->Remove(ID_MENUITEM_SAVE);
    menuFile->Remove(ID_MENUITEM_SAVE_AS);


    Disconnect(ID_MENUITEM_CLOSE);
    Disconnect(ID_MENUITEM_SAVE);
    Disconnect(ID_MENUITEM_SAVE_AS);

    Disconnect(ID_MENUITEM_UNDO);
    Disconnect(ID_MENUITEM_REDO);
    Disconnect(ID_MENUITEM_CUT);
    Disconnect(ID_MENUITEM_COPY);
    Disconnect(ID_MENUITEM_PASTE);

    Disconnect(ID_MENUITEM_PROJECTS);

    return T100TRUE;
}


void T100ProjectFrame::OnMenuNewSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_new();
}

void T100ProjectFrame::OnMenuOpenSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_open();
}

void T100ProjectFrame::OnMenuCloseSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_close();
}

void T100ProjectFrame::OnMenuSaveSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_save();
}

void T100ProjectFrame::OnMenuSaveAsSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_save_as();
}

void T100ProjectFrame::OnMenuQuitSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_quit();
}

void T100ProjectFrame::OnMenuUndoSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_undo();
}

void T100ProjectFrame::OnMenuRedoSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_redo();
}

void T100ProjectFrame::OnMenuCutSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_cut();
}

void T100ProjectFrame::OnMenuCopySelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_copy();
}

void T100ProjectFrame::OnMenuPasteSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_paste();
}

void T100ProjectFrame::OnMenuProjectsSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_projects();
}

void T100ProjectFrame::OnMenuAboutSelected(wxCommandEvent& event)
{
    T100ProjectCallback::frame_menu_about();
}

///

void T100ProjectFrame::OnClose(wxCloseEvent& event)
{
    T100ProjectCallback::frame_menu_quit();
}


}
