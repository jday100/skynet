#include "T100WindowMessageDispatcher.h"

#include "gui/event/T100EventHandler.h"

T100WindowMessageDispatcher::T100WindowMessageDispatcher() :
    m_controlHandlers(),
    m_windowHandlers()
{
    //ctor
}

T100WindowMessageDispatcher::~T100WindowMessageDispatcher()
{
    //dtor
}

T100BOOL T100WindowMessageDispatcher::RegisterControlHandler(T100WORD id, T100EventHandler* handler)
{
    m_controlHandlers[id]   = handler;
    return T100TRUE;
}

T100BOOL T100WindowMessageDispatcher::RegisterWindowHandler(HWND hwnd, T100EventHandler* handler)
{
    m_windowHandlers[hwnd]  = handler;
    return T100TRUE;
}

T100VOID T100WindowMessageDispatcher::DispatchWindowMessage(T100WindowMessageData& message)
{
    T100EventHandler*       handerPtr       = m_windowHandlers[message.WINDOW_HWND];

    if(handerPtr){
        handerPtr->ProcessWindowMessage(message);
    }
}
