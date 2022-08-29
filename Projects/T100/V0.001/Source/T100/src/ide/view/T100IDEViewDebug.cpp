#include "T100IDEViewDebug.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"
#include "T100IDECallbackDebug.h"

const long T100IDEViewDebug::ID_MENUITEM_DEBUG_STEP     = wxNewId();
const long T100IDEViewDebug::ID_MENUITEM_DEBUG_RUN      = wxNewId();
const long T100IDEViewDebug::ID_MENUITEM_DEBUG_PAUSE    = wxNewId();
const long T100IDEViewDebug::ID_MENUITEM_DEBUG_STOP     = wxNewId();


T100IDEViewDebug::T100IDEViewDebug(T100IDEView* view)
    :T100IDEViewBase(view)
{
    //ctor
}

T100IDEViewDebug::~T100IDEViewDebug()
{
    //dtor
}

T100BOOL T100IDEViewDebug::create_menu()
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

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_DEBUG_STEP,      _("Step"),   wxEmptyString, wxITEM_NORMAL);

    menu->Append(item);
    menu->AppendSeparator();

    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_DEBUG_RUN,       _("Run"),  wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    item    = T100NEW wxMenuItem(menu, ID_MENUITEM_DEBUG_PAUSE,     _("Pause"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menubar->Append(menu, _("Debug"));

    frame->Connect(ID_MENUITEM_DEBUG_STEP,  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewDebug::OnMenuDebugStepSelected);
    frame->Connect(ID_MENUITEM_DEBUG_RUN,   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewDebug::OnMenuDebugRunSelected);
    frame->Connect(ID_MENUITEM_DEBUG_PAUSE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100IDEViewDebug::OnMenuDebugPauseSelected);

    return T100TRUE;
}

T100BOOL T100IDEViewDebug::step()
{
    T100IDEServe* serve     = T100NULL;

    serve = dynamic_cast<T100IDEServe*>(m_view->getServe());

    if(!serve){
        //exception
        return T100FALSE;
    }

    return serve->getFile()->opened();
}

T100BOOL T100IDEViewDebug::run()
{
    T100BOOL        result;
    T100IDEServe*   serve     = T100NULL;

    serve = dynamic_cast<T100IDEServe*>(m_view->getServe());

    if(!serve){
        //exception
        return T100FALSE;
    }

    return result;
}

T100BOOL T100IDEViewDebug::pause()
{
    return T100FALSE;
}

void T100IDEViewDebug::OnMenuDebugStepSelected(wxCommandEvent& event)
{
    T100IDECallbackDebug::frame_menu_step();
}

void T100IDEViewDebug::OnMenuDebugRunSelected(wxCommandEvent& event)
{
    T100IDECallbackDebug::frame_menu_run();
}

void T100IDEViewDebug::OnMenuDebugPauseSelected(wxCommandEvent& event)
{
    T100IDECallbackDebug::frame_menu_pause();
}

void T100IDEViewDebug::OnMenuDebugStopSelected(wxCommandEvent& event)
{
    T100IDECallbackDebug::frame_menu_stop();
}
