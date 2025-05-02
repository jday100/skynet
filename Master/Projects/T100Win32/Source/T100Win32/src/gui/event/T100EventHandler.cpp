#include "T100EventHandler.h"

#include <windows.h>
#include "T100AllEvents.h"

T100EVENT_WINDOW_HANDLER_HASH       T100EventHandler::m_windows;
T100EVENT_HANDLER_HASH              T100EventHandler::m_handlers;
T100WINDOW_CLASS_HASH               T100EventHandler::m_windowClass;
T100IDManager                       T100EventHandler::m_idManager;

T100EventHandler::T100EventHandler() :
    m_menus(),
    m_events(),
    m_commands()
{
    //ctor
}

T100EventHandler::~T100EventHandler()
{
    //dtor
}

T100VOID T100EventHandler::Register(HWND hwnd, T100EventHandler* handler)
{
    m_windows[hwnd]     = handler;
}

T100VOID T100EventHandler::Register(T100UINT id, T100EventHandler* handler)
{
    m_handlers[id]      = handler;
}

T100BOOL T100EventHandler::RegisterWindowClass(T100WSTRING name)
{
    T100BOOL    result  = m_windowClass[name];

    if(!result){
        m_windowClass[name] = T100TRUE;
    }

    return !result;
}

T100VOID T100EventHandler::Connect(T100EVENT_TYPE type, T100EVENT_CALL call, T100EventHandler* handler)
{
    T100EVENT_CALL_DATA     data;

    data.CALL       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    m_events[type]       = data;
}

T100VOID T100EventHandler::Connect(T100EVENT_TYPE type, T100UINT id, T100EVENT_CALL call, T100EventHandler* handler)
{
    T100EVENT_CALL_DATA     data;

    data.CALL       = call;

    if(handler){
        data.HANDLER    = handler;
    }else{
        data.HANDLER    = this;
    }

    switch(type){
    case T100EVENT_MENU:
        {
            m_menus[id]     = data;
        }
        break;
    }
    m_commands[id]      = data;
}

T100VOID T100EventHandler::ProcessMenu(T100Event& event)
{

    T100EVENT_CALL_DATA     data        = m_menus[event.ID];

    if(data.CALL != 0){
        if(data.HANDLER){
            (data.HANDLER->*data.CALL)(event);
        }else{
            (this->*data.CALL)(event);
        }
    }

}

T100VOID T100EventHandler::ProcessCommand(T100Event& event)
{
    switch(event.MessageID){
    case WM_COMMAND:
        {
            T100CommandEvent        cevent;
            T100EVENT_CALL_DATA     data        = m_commands[event.ID];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(cevent);
                }else{
                    (this->*data.CALL)(cevent);
                }
            }
        }
        break;
    }
}

T100VOID T100EventHandler::ProcessEvent(T100Event& event)
{
    switch(event.MessageID){
    case WM_CREATE:
        {
            T100EVENT_CALL_DATA     data        = m_events[T100EVENT_WINDOW_CREATE];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(event);
                }else{
                    (this->*data.CALL)(event);
                }
            }
        }
        break;
    case WM_DESTROY:
        {
            T100EVENT_CALL_DATA     data        = m_events[T100EVENT_WINDOW_DESTROY];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(event);
                }else{
                    (this->*data.CALL)(event);
                }
            }
        }
        break;
    case WM_COMMAND:
        {
            T100CommandEvent        cevent;
            T100EVENT_CALL_DATA     data        = m_events[T100EVENT_COMMAND];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(cevent);
                }else{
                    (this->*data.CALL)(cevent);
                }
            }
        }
        break;
    case WM_SIZE:
        {
            T100EVENT_CALL_DATA     data        = m_events[T100EVENT_WINDOW_SIZE];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(event);
                }else{
                    (this->*data.CALL)(event);
                }
            }
        }
        break;
    case WM_PAINT:
        {
            T100EVENT_CALL_DATA     data        = m_events[T100EVENT_WINDOW_PAINT];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(event);
                }else{
                    (this->*data.CALL)(event);
                }
            }else{
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(event.WINDOW_HWND, &ps);
                    // TODO: 在此处添加使用 hdc 的任何绘图代码...
                EndPaint(event.WINDOW_HWND, &ps);
            }
        }
        break;
    case WM_CLOSE:
        {
            T100EVENT_CALL_DATA     data        = m_events[T100EVENT_WINDOW_CLOSE];

            if(data.CALL != 0){
                if(data.HANDLER){
                    (data.HANDLER->*data.CALL)(event);
                    DefWindowProc(event.WINDOW_HWND, event.MessageID, event.ID, event.FLAGS);
                }else{
                    (this->*data.CALL)(event);
                    DefWindowProc(event.WINDOW_HWND, event.MessageID, event.ID, event.FLAGS);
                }
            }else{
                DefWindowProc(event.WINDOW_HWND, event.MessageID, event.ID, event.FLAGS);
            }
        }
        break;
    }
}

T100VOID T100EventHandler::DispatchEvent(T100Event& event)
{
    switch(event.MessageID){
    case WM_SIZE:
        {
            this->ProcessEvent(event);
        }
        break;
    case WM_PAINT:
        {
            this->ProcessEvent(event);
        }
        break;
    case WM_CLOSE:
        {
            this->ProcessEvent(event);
        }
        break;
    }
}

T100VOID T100EventHandler::DispatchMessage(T100MESSAGE_DATA& data)
{
    switch(data.MESSAGE){
    case WM_COMMAND:
        {
            if(LOWORD(data.WINDOW_LPARAM) == 0){
                T100MenuEvent           event(data);
                this->ProcessMenu(event);
            }else{
                T100EventHandler*       handler         = m_handlers[data.WINDOW_WPARAM];
                T100CommandEvent        event(data);
                if(handler){
                    handler->DispatchEvent(event);
                }
            }
        }
        break;
    case WM_SIZE:
        {
            T100EventHandler*       handler         = m_windows[data.WINDOW_HWND];
            T100WindowEvent         event(data);
            if(handler){
                handler->DispatchEvent(event);
            }
        }
        break;
    case WM_PAINT:
        {
            T100EventHandler*       handler         = m_windows[data.WINDOW_HWND];//m_handlers[data.WINDOW_WPARAM];
            T100WindowEvent         event(data);
            if(handler){
                handler->DispatchEvent(event);
            }else{
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(data.WINDOW_HWND, &ps);
                    // TODO: 在此处添加使用 hdc 的任何绘图代码...
                EndPaint(data.WINDOW_HWND, &ps);
            }
        }
        break;
    case WM_CLOSE:
        {
            T100EventHandler*       handler         = m_windows[data.WINDOW_HWND];
            T100WindowEvent         event(data);
            if(handler){
                handler->DispatchEvent(event);
            }
        }
        break;
    }
}
