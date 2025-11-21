#include "T100ExtensionPanel.h"

namespace T100UNIVERSAL{

T100ExtensionPanel::T100ExtensionPanel() :
    T100Extension(),
    m_events()
{
    //ctor
}

T100ExtensionPanel::~T100ExtensionPanel()
{
    //dtor
}

T100Panel* T100ExtensionPanel::GetPanel()
{
    return m_panel;
}

T100VOID T100ExtensionPanel::SignIn(T100INT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    if(!call || !handler){
        return;
    }

    T100EVENT_FUNCTION_DATA         data;

    data.HANDLER    = handler;
    data.FUNCTION   = call;
    m_events[type]  = data;

    m_panel->Connect(type, call, handler);
}

}
