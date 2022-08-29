#include "T100IDEViewSetup.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackSetup.h"

const long T100IDEViewSetup::ID_MENUITEM_SETUP_CONFIG       = wxNewId();
const long T100IDEViewSetup::ID_MENUITEM_SETUP_EDITOR       = wxNewId();
const long T100IDEViewSetup::ID_MENUITEM_SETUP_COMPILER     = wxNewId();
const long T100IDEViewSetup::ID_MENUITEM_SETUP_DEBUGGER     = wxNewId();


T100IDEViewSetup::T100IDEViewSetup(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewSetup::~T100IDEViewSetup()
{
    //dtor
}

T100BOOL T100IDEViewSetup::create_menu()
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

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_SETUP_CONFIG,    _("Config"),    wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_SETUP_EDITOR,    _("Editor"),    wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_SETUP_COMPILER,  _("Compiler"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_SETUP_DEBUGGER,  _("Debugger"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Setup"));

    frame->Connect(ID_MENUITEM_SETUP_CONFIG,    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewSetup::OnMenuSetupConfigSelected);
    frame->Connect(ID_MENUITEM_SETUP_EDITOR,    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewSetup::OnMenuSetupEditorSelected);
    frame->Connect(ID_MENUITEM_SETUP_COMPILER,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewSetup::OnMenuSetupCompilerSelected);
    frame->Connect(ID_MENUITEM_SETUP_DEBUGGER,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewSetup::OnMenuSetupDebuggerSelected);

    return T100TRUE;
}

void T100IDEViewSetup::OnMenuSetupConfigSelected(wxCommandEvent& event)
{
    T100IDECallbackSetup::frame_menu_config();
}

void T100IDEViewSetup::OnMenuSetupEditorSelected(wxCommandEvent& event)
{
    T100IDECallbackSetup::frame_menu_editor();
}

void T100IDEViewSetup::OnMenuSetupCompilerSelected(wxCommandEvent& event)
{
    T100IDECallbackSetup::frame_menu_compiler();
}

void T100IDEViewSetup::OnMenuSetupDebuggerSelected(wxCommandEvent& event)
{
    T100IDECallbackSetup::frame_menu_debugger();
}
