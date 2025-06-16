#include "T100WindowMessageDispatcher.h"

#include "gui/handler/T100EventHandler.h"

namespace T100WINDOWS{

T100WindowMessageDispatcher::T100WindowMessageDispatcher() :
    T100Class(),
    m_controlHandlers(),
    m_windowHandlers()
{
    //ctor
}

T100WindowMessageDispatcher::~T100WindowMessageDispatcher()
{
    //dtor
}

T100BOOL T100WindowMessageDispatcher::RegisterControlHandler(T100UINT id, T100EventHandler* handler)
{
    T100EventHandler*       result      = T100NULL;

    result  = m_controlHandlers[id];

    if(result){
        return T100FALSE;
    }

    m_controlHandlers[id]   = handler;
    return T100TRUE;
}

T100BOOL T100WindowMessageDispatcher::RegisterWindowHandler(HWND hwnd, T100EventHandler* handler)
{
    T100EventHandler*       result      = T100NULL;

    result  = m_windowHandlers[hwnd];

    if(result){
        return T100FALSE;
    }

    m_windowHandlers[hwnd]  = handler;
    return T100TRUE;
}

T100VOID T100WindowMessageDispatcher::DispatchWindowMessage(const T100WindowMessageData& message)
{
    T100EventHandler*       handler     = m_windowHandlers[message.WINDOW_HWND];

    if(handler){
        handler->ProcessWindowMessage(message);
    }
}

T100EventHandler* T100WindowMessageDispatcher::GetControlHandler(T100UINT id)
{
    return m_controlHandlers[id];
}

}
