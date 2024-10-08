#include "T100PainterFrame.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/menu.h>
#include "T100PainterCallback.h"

namespace T100Painter{

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

const long T100PainterFrame::ID_MENUITEM_ELEMENTS = wxNewId();
const long T100PainterFrame::ID_MENUITEM_PROPERTIES = wxNewId();

const long T100PainterFrame::ID_MENUITEM_ABOUT = wxNewId();


BEGIN_EVENT_TABLE(T100PainterFrame,wxFrame)

END_EVENT_TABLE()

T100PainterFrame::T100PainterFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100PainterFrame::~T100PainterFrame()
{
    //dtor
    destroy();
}

void T100PainterFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxEmptyString, pos, size, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);

	create();
}

T100VOID T100PainterFrame::create()
{
    create_menu();

    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100PainterFrame::OnClose);
}

T100VOID T100PainterFrame::destroy()
{

}

T100BOOL T100PainterFrame::create_menu()
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

    Connect(ID_MENUITEM_NEW,            wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuNewSelected);
    Connect(ID_MENUITEM_OPEN,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuOpenSelected);
    Connect(ID_MENUITEM_QUIT,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuQuitSelected);

    Connect(ID_MENUITEM_ABOUT,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuAboutSelected);

    return T100TRUE;
}

/*
T100BOOL T100PainterFrame::create_menu()
{
    wxMenuBar*      menuBar         = T100NEW wxMenuBar();
    wxMenu*         menuFile        = T100NEW wxMenu();
    wxMenu*         menuEdit        = T100NEW wxMenu();
    wxMenu*         menuView        = T100NEW wxMenu();
    wxMenu*         menuHelp        = T100NEW wxMenu();

    menuFile->Append(ID_MENUITEM_NEW, wxT("New"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_OPEN, wxT("Open…"));
    menuFile->Append(ID_MENUITEM_CLOSE, wxT("Close"));
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENUITEM_SAVE, wxT("Save"));
    menuFile->Append(ID_MENUITEM_SAVE_AS, wxT("Save as…"));
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

    menuView->Append(ID_MENUITEM_ELEMENTS, wxT("Elements"));
    menuView->Append(ID_MENUITEM_PROPERTIES, wxT("Properties"));

    menuBar->Append(menuView, wxT("View"));

    menuHelp->Append(ID_MENUITEM_ABOUT, wxT("About…"));

    menuBar->Append(menuHelp, wxT("Help"));

    SetMenuBar(menuBar);

    //

    Connect(ID_MENUITEM_NEW,            wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuNewSelected);
    Connect(ID_MENUITEM_OPEN,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuOpenSelected);
    Connect(ID_MENUITEM_CLOSE,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuCloseSelected);
    Connect(ID_MENUITEM_SAVE,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuSaveAsSelected);
    Connect(ID_MENUITEM_QUIT,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuQuitSelected);

    Connect(ID_MENUITEM_UNDO,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuUndoSelected);
    Connect(ID_MENUITEM_REDO,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuRedoSelected);
    Connect(ID_MENUITEM_CUT,            wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuCutSelected);
    Connect(ID_MENUITEM_COPY,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuCopySelected);
    Connect(ID_MENUITEM_PASTE,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuPasteSelected);

    Connect(ID_MENUITEM_ELEMENTS,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuElementsSelected);
    Connect(ID_MENUITEM_PROPERTIES,     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuPropertiesSelected);

    Connect(ID_MENUITEM_ABOUT,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuAboutSelected);

    ////
    Connect(wxID_ANY,                   wxEVT_CLOSE_WINDOW,             (wxObjectEventFunction)&T100PainterFrame::OnClose);


    return T100TRUE;
}
*/

T100BOOL T100PainterFrame::update_menu()
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

    menuView->Append(ID_MENUITEM_ELEMENTS, wxT("Elements"));
    menuView->Append(ID_MENUITEM_PROPERTIES, wxT("Properties"));

    menuBar->Insert(2, menuView, wxT("View"));

    Connect(ID_MENUITEM_CLOSE,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuCloseSelected);
    Connect(ID_MENUITEM_SAVE,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuSaveSelected);
    Connect(ID_MENUITEM_SAVE_AS,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuSaveAsSelected);

    Connect(ID_MENUITEM_UNDO,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuUndoSelected);
    Connect(ID_MENUITEM_REDO,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuRedoSelected);
    Connect(ID_MENUITEM_CUT,            wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuCutSelected);
    Connect(ID_MENUITEM_COPY,           wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuCopySelected);
    Connect(ID_MENUITEM_PASTE,          wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuPasteSelected);

    Connect(ID_MENUITEM_ELEMENTS,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuElementsSelected);
    Connect(ID_MENUITEM_PROPERTIES,     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PainterFrame::OnMenuPropertiesSelected);

    return T100TRUE;
}

T100BOOL T100PainterFrame::reset_menu()
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

    Disconnect(ID_MENUITEM_ELEMENTS);
    Disconnect(ID_MENUITEM_PROPERTIES);

    return T100TRUE;
}


void T100PainterFrame::OnMenuNewSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_new();
}

void T100PainterFrame::OnMenuOpenSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_open();
}

void T100PainterFrame::OnMenuCloseSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_close();
}

void T100PainterFrame::OnMenuSaveSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_save();
}

void T100PainterFrame::OnMenuSaveAsSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_save_as();
}

void T100PainterFrame::OnMenuQuitSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_quit();
}

void T100PainterFrame::OnMenuUndoSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_undo();
}

void T100PainterFrame::OnMenuRedoSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_redo();
}

void T100PainterFrame::OnMenuCutSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_cut();
}

void T100PainterFrame::OnMenuCopySelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_copy();
}

void T100PainterFrame::OnMenuPasteSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_paste();
}

void T100PainterFrame::OnMenuElementsSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_elements();
}

void T100PainterFrame::OnMenuPropertiesSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_properties();
}

void T100PainterFrame::OnMenuAboutSelected(wxCommandEvent& event)
{
    T100PainterCallback::frame_menu_about();
}

///

void T100PainterFrame::OnClose(wxCloseEvent& event)
{
    T100PainterCallback::frame_menu_quit();
}

}
