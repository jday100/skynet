#include "T100IDEViewEdit.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackEdit.h"

const long T100IDEViewEdit::ID_MENUITEM_EDIT_UNDO       = wxNewId();
const long T100IDEViewEdit::ID_MENUITEM_EDIT_REDO       = wxNewId();
const long T100IDEViewEdit::ID_MENUITEM_EDIT_CUT        = wxNewId();
const long T100IDEViewEdit::ID_MENUITEM_EDIT_COPY       = wxNewId();
const long T100IDEViewEdit::ID_MENUITEM_EDIT_PASTE      = wxNewId();


T100IDEViewEdit::T100IDEViewEdit(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewEdit::~T100IDEViewEdit()
{
    //dtor
}

T100BOOL T100IDEViewEdit::create_menu()
{
    T100IDEFrameNew*    frame       = T100NULL;
    wxMenuBar*          menubar     = T100NULL;

    frame   = m_view->getFrame();

    if(!frame){
        return T100FALSE;
    }

    menubar = frame->GetMenuBar();

    if(!menubar){
        return T100FALSE;
    }

    wxMenu*         menu    = T100NEW wxMenu();
    wxMenuItem*     item;

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_EDIT_UNDO,   _("Undo"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_EDIT_REDO,   _("Redo"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    menu->AppendSeparator();

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_EDIT_CUT,    _("Cut"),   wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_EDIT_COPY,   _("Copy"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_EDIT_PASTE,  _("Paste"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Edit"));

    frame->Connect(ID_MENUITEM_EDIT_UNDO,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewEdit::OnMenuEditUndoSelected);
    frame->Connect(ID_MENUITEM_EDIT_REDO,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewEdit::OnMenuEditRedoSelected);
    frame->Connect(ID_MENUITEM_EDIT_CUT,    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewEdit::OnMenuEditCutSelected);
    frame->Connect(ID_MENUITEM_EDIT_COPY,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewEdit::OnMenuEditCopySelected);
    frame->Connect(ID_MENUITEM_EDIT_PASTE,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewEdit::OnMenuEditPasteSelected);

    return T100TRUE;
}

void T100IDEViewEdit::OnMenuEditUndoSelected(wxCommandEvent& event)
{
    T100IDECallbackEdit::frame_menu_undo();
}

void T100IDEViewEdit::OnMenuEditRedoSelected(wxCommandEvent& event)
{
    T100IDECallbackEdit::frame_menu_redo();
}

void T100IDEViewEdit::OnMenuEditCutSelected(wxCommandEvent& event)
{
    T100IDECallbackEdit::frame_menu_cut();
}

void T100IDEViewEdit::OnMenuEditCopySelected(wxCommandEvent& event)
{
    T100IDECallbackEdit::frame_menu_copy();
}

void T100IDEViewEdit::OnMenuEditPasteSelected(wxCommandEvent& event)
{
    T100IDECallbackEdit::frame_menu_paste();
}

