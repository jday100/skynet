#include "T100EventHandler.h"

#include "gui/event/T100Event.h"
#include "gui/T100Win32Application.h"
#include "gui/common/T100EventCommon.h"

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
    case T100EVENT_COMMAND:
        {
            ConnectCommand(type, call, handler);
        }
        break;
    default:
        {
            ConnectEvent(type, call, handler);
        }
        break;
    }
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

T100VOID T100EventHandler::SendWindowMessage(const T100WindowMessageData& data)
{
    ProcessWindowMessage(data);
}

T100VOID T100EventHandler::ProcessWindowMessage(const T100WindowMessageData& message)
{
    switch(message.MESSAGE_ID){
    case WM_COMMAND:
        {
            ProcessCommand(message);
        }
        break;
    case WM_CREATE:
        {
            CallEvent(T100EVENT_WINDOW_CREATE, message);
        }
        break;
    case WM_DESTROY:
        {
            CallEvent(T100EVENT_WINDOW_DESTROY, message);
        }
        break;
    case WM_MOVE:
        {
            CallEvent(T100EVENT_WINDOW_MOVE, message);
        }
        break;
    case WM_SIZE:
        {
            CallEvent(T100EVENT_WINDOW_SIZE, message);
            for(T100Tree* item : m_children){
                T100EventHandler*   handler     = ConvertToEventHandler(item);
                if(handler){
                    handler->ProcessWindowMessage(message);
                }
            }
        }
        break;
    case WM_ACTIVATE:
        {
            CallEvent(T100EVENT_WINDOW_ACTIVATE, message);
        }
        break;
    case WM_SETFOCUS:
        {
            CallEvent(T100EVENT_WINDOW_SET_FOCUS, message);
        }
        break;
    case WM_KILLFOCUS:
        {
            CallEvent(T100EVENT_WINDOW_KILL_FOCUS, message);
        }
        break;
    case WM_ENABLE:
        {
            CallEvent(T100EVENT_WINDOW_ENABLE, message);
        }
        break;
    case WM_SETREDRAW:
        {
            CallEvent(T100EVENT_WINDOW_SET_REDRAW, message);
        }
        break;
    case WM_SETTEXT:
        {
            CallEvent(T100EVENT_WINDOW_SET_TEXT, message);
        }
        break;
    case WM_GETTEXT:
        {
            CallEvent(T100EVENT_WINDOW_GET_TEXT, message);
        }
        break;
    case WM_GETTEXTLENGTH:
        {
            CallEvent(T100EVENT_WINDOW_GET_TEXT_LENGTH, message);
        }
        break;
    case WM_LBUTTONDOWN:
        {
            CallEvent(T100EVENT_MOUSE_LEFT_DOWN, message);
        }
        break;
    case WM_LBUTTONUP:
        {
            CallEvent(T100EVENT_MOUSE_LEFT_UP, message);
        }
        break;
    case WM_LBUTTONDBLCLK:
        {
            CallEvent(T100EVENT_MOUSE_LEFT_DOUBLE_CLICK, message);
        }
        break;
    case WM_RBUTTONDOWN:
        {
            CallEvent(T100EVENT_MOUSE_RIGHT_DOWN, message);
        }
        break;
    case WM_RBUTTONUP:
        {
            CallEvent(T100EVENT_MOUSE_RIGHT_UP, message);
        }
        break;
    case WM_RBUTTONDBLCLK:
        {
            CallEvent(T100EVENT_MOUSE_RIGHT_DOUBLE_CLICK, message);
        }
        break;
    case WM_MBUTTONDOWN:
        {
            CallEvent(T100EVENT_MOUSE_MIDDLE_DOWN, message);
        }
        break;
    case WM_MBUTTONUP:
        {
            CallEvent(T100EVENT_MOUSE_MIDDLE_UP, message);
        }
        break;
    case WM_MBUTTONDBLCLK:
        {
            CallEvent(T100EVENT_MOUSE_MIDDLE_DOUBLE_CLICK, message);
        }
        break;
    case WM_MOUSEWHEEL:
        {
            CallEvent(T100EVENT_MOUSE_WHEEL, message);
        }
        break;
    case WM_MOUSEACTIVATE:
        {
            CallEvent(T100EVENT_MOUSE_ENTER_WINDOW, message);
        }
        break;
    case WM_MOUSEMOVE:
        {
            CallEvent(T100EVENT_MOUSE_MOVING, message);
        }
        break;
    case WM_MOUSELEAVE:
        {
            CallEvent(T100EVENT_MOUSE_LEAVE_WINDOW, message);
        }
        break;
    case WM_PAINT:
        {
            CallEvent(T100EVENT_WINDOW_PAINT, message);
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(message.WINDOW_HWND, &ps);

            EndPaint(message.WINDOW_HWND, &ps);

            for(T100Tree* item : m_children){
                T100EventHandler*   handler     = ConvertToEventHandler(item);
                if(handler){
                    handler->ProcessWindowMessage(message);
                }
            }
        }
        break;
    case WM_NOTIFY:
        {
            CallEvent(T100EVENT_WINDOW_NOTIFY, message);
        }
        break;
    default:
        {

        }
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
