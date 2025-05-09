#include "T100EventHandler.h"

#include <windows.h>
#include "T100CommandEvent.h"

T100EVENT_HANDLER_HASH          T100EventHandler::m_handlers;

T100EventHandler::T100EventHandler()
{
    //ctor
}

T100EventHandler::~T100EventHandler()
{
    //dtor
}

T100VOID T100EventHandler::Register(T100UINT id, T100EventHandler* handler)
{
    m_handlers[id]  = handler;
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

    m_commands[id]      = data;
}

T100VOID T100EventHandler::ProcessCommand(T100EventBase& event)
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

T100VOID T100EventHandler::ProcessEvent(T100EventBase& event)
{
    switch(event.MessageID){
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
    }
}

T100VOID T100EventHandler::DispatchEvent(T100EventBase& event)
{
    if(event.FLAGS == 0){
        this->ProcessCommand(event);
    }else{
        T100EventHandler*       handler         = m_handlers[event.ID];

        if(handler){
            handler->ProcessEvent(event);
        }
    }



}
