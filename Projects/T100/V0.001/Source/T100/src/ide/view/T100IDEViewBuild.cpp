#include "T100IDEViewBuild.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackBuild.h"

const long T100IDEViewBuild::ID_MENUITEM_BUILD_BUILD    = wxNewId();
const long T100IDEViewBuild::ID_MENUITEM_BUILD_RUN      = wxNewId();
const long T100IDEViewBuild::ID_MENUITEM_BUILD_CLEAN    = wxNewId();
const long T100IDEViewBuild::ID_MENUITEM_BUILD_STOP     = wxNewId();


T100IDEViewBuild::T100IDEViewBuild(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewBuild::~T100IDEViewBuild()
{
    //dtor
}

T100BOOL T100IDEViewBuild::create_menu()
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

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_BUILD_BUILD,     _("Build"),     wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    menu->AppendSeparator();
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_BUILD_CLEAN,     _("Clean"),     wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    menu->AppendSeparator();
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_BUILD_RUN,       _("Run"),       wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_BUILD_STOP,      _("Stop"),      wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Build"));

    frame->Connect(ID_MENUITEM_BUILD_BUILD, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewBuild::OnMenuBuildBuildSelected);
    frame->Connect(ID_MENUITEM_BUILD_CLEAN, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewBuild::OnMenuBuildCleanSelected);
    frame->Connect(ID_MENUITEM_BUILD_RUN,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewBuild::OnMenuBuildRunSelected);
    frame->Connect(ID_MENUITEM_BUILD_STOP,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewBuild::OnMenuBuildStopSelected);

    return T100TRUE;
}

void T100IDEViewBuild::OnMenuBuildBuildSelected(wxCommandEvent& event)
{
    T100IDECallbackBuild::frame_menu_build();
}

void T100IDEViewBuild::OnMenuBuildRunSelected(wxCommandEvent& event)
{
    T100IDECallbackBuild::frame_menu_run();
}

void T100IDEViewBuild::OnMenuBuildCleanSelected(wxCommandEvent& event)
{
    T100IDECallbackBuild::frame_menu_clean();
}

void T100IDEViewBuild::OnMenuBuildStopSelected(wxCommandEvent& event)
{
    T100IDECallbackBuild::frame_menu_stop();
}
