#include "T100ExtensionMenu.h"



namespace T100UNIVERSAL{

T100ExtensionMenu::T100ExtensionMenu() :
    T100Extension(),
    m_children()
{
    //ctor
}

T100ExtensionMenu::~T100ExtensionMenu()
{
    //dtor
}

T100Menu* T100ExtensionMenu::GetMenu()
{
    return m_menu;
}

T100VOID T100ExtensionMenu::Bind(T100Menu* menu, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    if(!menu || !handler){
        return;
    }
    m_menu      = menu;
    m_event.HANDLER     = handler;
    m_event.FUNCTION    = call;
}

T100VOID T100ExtensionMenu::SignIn(T100INT id, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;
    data.HANDLER    = handler;
    data.FUNCTION   = call;
    m_children[id]  = data;
    m_event.HANDLER->ConnectMenu(id, m_event.FUNCTION, m_event.HANDLER);
}

T100VOID T100ExtensionMenu::Send(T100MenuEvent& event)
{
    T100EVENT_FUNCTION_DATA         data;
    T100INT     id      = event.GetID();

    data    = m_children[id];

    if(!data.HANDLER || !data.FUNCTION){
        return;
    }

    (data.HANDLER->*(data.FUNCTION))(event);
}

}
