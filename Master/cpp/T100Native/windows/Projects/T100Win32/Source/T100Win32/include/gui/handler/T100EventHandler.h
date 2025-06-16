#ifndef T100EVENTHANDLER_H
#define T100EVENTHANDLER_H

#include <unordered_map>
#include "object/T100Tree.h"
#include "gui/T100AllEvents.h"
#include "gui/data/T100WindowMessageData.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100EventHandler;
class T100Win32Application;

typedef     T100VOID(T100EventHandler::*T100EVENT_FUNCTION)(...);

typedef struct{
    T100EventHandler*           HANDLER         = T100NULL;
    T100EVENT_FUNCTION          FUNCTION;
}T100EVENT_FUNCTION_DATA;

#define     T100EVENT_FUNCTION_DATA_HASH                    std::unordered_map<T100UINT, T100EVENT_FUNCTION_DATA>

class T100EventHandler : public T100Tree
{
    public:
        T100EventHandler();
        T100EventHandler(T100EventHandler*);
        virtual ~T100EventHandler();

        virtual T100VOID                        Create(T100EventHandler*);
        virtual T100VOID                        Destroy();

        T100Win32Application*                   GetApplication();

        virtual T100VOID                        Connect(T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        virtual T100VOID                        ConnectMenu(T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);

        virtual T100VOID                        SendWindowMessage(const T100WindowMessageData&);

        virtual T100VOID                        ProcessWindowMessage(const T100WindowMessageData&);
        virtual T100VOID                        ProcessNotifyMessage(const T100WindowMessageData&);

        T100EventHandler*                       ConvertToEventHandler(T100Tree*);

    protected:
        T100EVENT_FUNCTION_DATA_HASH            m_events;
        T100EVENT_FUNCTION_DATA_HASH            m_menuEvents;
        T100EVENT_FUNCTION_DATA_HASH            m_commandEvents;
        T100EVENT_FUNCTION_DATA_HASH            m_notifyEvents;

    private:
        T100VOID                                ProcessCommand(const T100WindowMessageData&);
        T100VOID                                CallMenu(T100UINT, const T100WindowMessageData&);
        T100VOID                                CallEvent(T100UINT, const T100WindowMessageData&);
        T100VOID                                CallCommand(T100UINT, const T100WindowMessageData&);

        virtual T100VOID                        ConnectEvent(T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        virtual T100VOID                        ConnectNotify(T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        virtual T100VOID                        ConnectCommand(T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
};

}

#endif // T100EVENTHANDLER_H
