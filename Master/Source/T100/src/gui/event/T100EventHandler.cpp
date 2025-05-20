#include "gui/event/T100EventHandler.h"

#include "gui/common/T100EventCommon.h"


T100EventHandler::T100EventHandler() :
    T100ObjectTreeNode(),
    m_menuEvents(),
    m_events()
{
    //ctor
}

T100EventHandler::T100EventHandler(T100WSTRING label, T100EventHandler* parent) :
    T100ObjectTreeNode(label, parent),
    m_menuEvents(),
    m_events()
{
    //ctor
}

T100EventHandler::~T100EventHandler()
{
    //dtor
}

T100VOID T100EventHandler::Create(T100WSTRING label, T100EventHandler* handler)
{
    T100ObjectTreeNode::Create(label, handler);
}

T100VOID T100EventHandler::Destroy()
{

}

T100EventHandler* T100EventHandler::ConvertToEventHandler(T100ObjectTreeNode* node)
{
    return dynamic_cast<T100EventHandler*>(node);
}

T100VOID T100EventHandler::Connect(T100WORD type, T100EVENT_FUNCTION call, T100EventHandler* handler)
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
            m_commands[type]    = data;
        }
        break;
    default:
        {
            m_events[type]      = data;
        }
        break;
    }

}

T100VOID T100EventHandler::ConnectMenu(T100WORD type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    T100EVENT_FUNCTION_DATA         data;

    data.FUNCTION       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    m_menuEvents[type]       = data;
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

            for(T100ObjectTreeNode* item : m_children.getVector()){
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
            for(T100ObjectTreeNode* item : m_children.getVector()){
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
        CallCommand(LOWORD(message.WINDOW_WPARAM), message);
    }
}

T100VOID T100EventHandler::CallMenu(T100WORD type, T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data    = m_menuEvents[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }
}

T100VOID T100EventHandler::CallEvent(T100WORD type, T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data    = m_events[type];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }else{
        //DefWindowProc(message.WINDOW_HWND, message.MESSAGE_ID, message.WINDOW_WPARAM, message.WINDOW_LPARAM);
    }
}

T100VOID T100EventHandler::CallCommand(T100WORD type, T100WindowMessageData& message)
{
    T100EVENT_FUNCTION_DATA&        data    = m_commands[T100EVENT_COMMAND];

    if(data.HANDLER && data.FUNCTION){
        T100Event       event(message);
        (data.HANDLER->*(data.FUNCTION))(event);
    }else{
        //DefWindowProc(message.WINDOW_HWND, message.MESSAGE_ID, message.WINDOW_WPARAM, message.WINDOW_LPARAM);
    }
}
