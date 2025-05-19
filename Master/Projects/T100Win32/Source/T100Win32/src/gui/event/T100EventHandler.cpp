#include "T100EventHandler.h"

#include "T100Win32Common.h"
#include "T100Win32Application.h"

T100EventHandler::T100EventHandler() :
    T100ObjectTree(),
    m_menus(),
    m_events()
{
    //ctor
}

T100EventHandler::T100EventHandler(T100EventHandler* parent) :
    T100ObjectTree(parent),
    m_menus(),
    m_events()
{
    //ctor
}

T100EventHandler::~T100EventHandler()
{
    //dtor
}

T100VOID T100EventHandler::Create(T100EventHandler* handler)
{
    T100ObjectTree::Create(handler);
}

T100VOID T100EventHandler::Destroy()
{

}

T100EventHandler* T100EventHandler::ConvertToEventHandler(T100ObjectTree* node)
{
    return dynamic_cast<T100EventHandler*>(node);
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

    m_events[type]      = data;
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

    m_menus[type]       = data;
}

T100Win32Application* T100EventHandler::GetApplicationPtr()
{
    return dynamic_cast<T100Win32Application*>(GetRootPtr());
}

T100VOID T100EventHandler::SendWindowMessage(T100WindowMessageData& message)
{
    ProcessWindowMessage(message);
}

T100VOID T100EventHandler::ProcessWindowMessage(T100WindowMessageData& message)
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
    case WM_PAINT:
        {
            CallEvent(T100EVENT_WINDOW_PAINT, message);
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(message.WINDOW_HWND, &ps);

            EndPaint(message.WINDOW_HWND, &ps);

            for(T100ObjectTree* item : m_children.getVector()){
                T100EventHandler*   handler     = ConvertToEventHandler(item);
                if(handler){
                    handler->ProcessWindowMessage(message);
                }
            }
        }
        break;
    case WM_SIZE:
        {
            CallEvent(T100EVENT_WINDOW_SIZE, message);
            for(T100ObjectTree* item : m_children.getVector()){
                T100EventHandler*   handler     = ConvertToEventHandler(item);
                if(handler){
                    handler->ProcessWindowMessage(message);
                }
            }
        }
        break;
    }
}

T100VOID T100EventHandler::ProcessCommand(T100WindowMessageData& message)
{
    if(LOWORD(message.WINDOW_LPARAM) == 0){
        CallMenu((UINT)message.WINDOW_WPARAM, message);
    }else{
        CallEvent((T100EVENT_TYPE)message.WINDOW_WPARAM, message);
    }
}

T100VOID T100EventHandler::CallMenu(T100UINT type, T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data    = m_menus[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }
}

T100VOID T100EventHandler::CallEvent(T100EVENT_TYPE type, T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data    = m_events[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }else{
        DefWindowProc(message.WINDOW_HWND, message.MESSAGE_ID, message.WINDOW_WPARAM, message.WINDOW_LPARAM);
    }
}
