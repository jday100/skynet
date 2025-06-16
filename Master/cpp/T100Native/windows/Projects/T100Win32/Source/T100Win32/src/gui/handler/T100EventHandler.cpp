#include "T100EventHandler.h"

#include "gui/event/T100Event.h"
#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100EventHandler::T100EventHandler() :
    T100Tree()
{
    //ctor
}

T100EventHandler::~T100EventHandler()
{
    //dtor
}

T100VOID T100EventHandler::Create(T100EventHandler* parent)
{

}

T100VOID T100EventHandler::Destroy()
{

}

T100Win32Application* T100EventHandler::GetApplication()
{
    return dynamic_cast<T100Win32Application*>(GetRoot());
}

T100VOID T100EventHandler::Connect(T100UINT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;

    data.FUNCTION       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    switch(type){

    }
}

T100VOID T100EventHandler::SendWindowMessage(const T100WindowMessageData& data)
{
    ProcessWindowMessage(data);
}

T100VOID T100EventHandler::ProcessWindowMessage(const T100WindowMessageData& message)
{
    switch(message.MESSAGE_ID){
    }
}

T100VOID T100EventHandler::ProcessNotifyMessage(const T100WindowMessageData& message)
{

}

T100VOID T100EventHandler::ProcessCommand(const T100WindowMessageData& message)
{
    if(LOWORD(message.WINDOW_LPARAM) == 0){
        CallMenu((T100UINT)message.WINDOW_WPARAM, message);
    }else{
        CallCommand(LOWORD(message.WINDOW_WPARAM), message);
    }
}

T100EventHandler* T100EventHandler::ConvertToEventHandler(T100Tree* node)
{
    return dynamic_cast<T100EventHandler*>(node);
}

T100VOID T100EventHandler::ConnectMenu(T100UINT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;

    data.FUNCTION       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    m_menuEvents[type]  = data;
}

T100VOID T100EventHandler::ConnectEvent(T100UINT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;

    data.FUNCTION       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    m_events[type]      = data;
}

T100VOID T100EventHandler::ConnectNotify(T100UINT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;

    data.FUNCTION       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    m_notifyEvents[type]        = data;
}

T100VOID T100EventHandler::ConnectCommand(T100UINT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;

    data.FUNCTION       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    m_commandEvents[type]   = data;
}

T100VOID T100EventHandler::CallMenu(T100UINT type, const T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data        = m_menuEvents[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }
}

T100VOID T100EventHandler::CallEvent(T100UINT type, const T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data        = m_events[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }
}

T100VOID T100EventHandler::CallCommand(T100UINT type, const T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data        = m_commandEvents[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }
}

}
