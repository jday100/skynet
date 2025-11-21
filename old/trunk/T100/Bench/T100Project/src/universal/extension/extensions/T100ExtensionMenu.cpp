#include "T100ExtensionMenu.h"

T100ExtensionMenu::T100ExtensionMenu() :
    T100Extension(),
    m_events()
{
    //ctor
}

T100ExtensionMenu::~T100ExtensionMenu()
{
    //dtor
}

T100VOID T100ExtensionMenu::SetMenuBar(wxFrame* frame, wxMenuBar* menuBar)
{
    m_frame         = frame;
    m_menuBar       = menuBar;
}

wxMenuBar* T100ExtensionMenu::GetMenuBar()
{
    return m_menuBar;
}

T100VOID T100ExtensionMenu::SetHandler(wxEvtHandler* handler, wxObjectEventFunction call)
{
    m_eventHandler.Handler      = handler;
    m_eventHandler.Function     = call;
}

T100EventHandlerData& T100ExtensionMenu::GetHandler()
{
    return m_eventHandler;
}

T100VOID T100ExtensionMenu::Update()
{
    m_frame->SetMenuBar(m_menuBar);
}

T100VOID T100ExtensionMenu::SignIn(T100UINT id, T100Plugin* plugin, T100EXTENSION_EVENT_FUNCTION call)
{
    T100EXTENSION_EVENT_FUNCTION_DATA*      data        = T100NEW T100EXTENSION_EVENT_FUNCTION_DATA();

    data->Plugin    = plugin;
    data->Function  = call;

    m_events.Append(id, data);
}

T100VOID T100ExtensionMenu::SendEvent(wxCommandEvent& event)
{
    T100UINT        id      = event.GetId();
    T100EXTENSION_EVENT_FUNCTION_DATA*          data        = T100NULL;

    data    = m_events[id];

    if(!data){
        return;
    }

    (data->Plugin->*(data->Function))(event);
}

