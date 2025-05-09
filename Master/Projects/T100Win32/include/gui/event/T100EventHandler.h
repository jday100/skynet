#ifndef T100EVENTHANDLER_H
#define T100EVENTHANDLER_H

#include <unordered_map>
#include "T100EventBase.h"

typedef struct{
    T100EVENT_CALL      CALL            = 0;
    T100EventHandler*   HANDLER         = T100NULL;
}T100EVENT_CALL_DATA;

#define     T100EVENT_HANDLER_HASH          std::unordered_map<T100UINT, T100EventHandler*>
#define     T100EVENT_CALL_HASH             std::unordered_map<T100UINT, T100EVENT_CALL_DATA>


class T100EventHandler
{
    public:
        T100EventHandler();
        virtual ~T100EventHandler();

        virtual T100VOID            Connect(T100EVENT_TYPE, T100EVENT_CALL, T100EventHandler* = T100NULL);
        virtual T100VOID            Connect(T100EVENT_TYPE, T100UINT, T100EVENT_CALL, T100EventHandler* = T100NULL);

        T100VOID                    Register(T100UINT, T100EventHandler*);

        T100VOID                    ProcessCommand(T100EventBase&);
        T100VOID                    ProcessEvent(T100EventBase&);

        T100VOID                    DispatchEvent(T100EventBase&);

    protected:

    private:
        T100EVENT_CALL_HASH                     m_commands;
        T100EVENT_CALL_HASH                     m_events;
        static T100EVENT_HANDLER_HASH           m_handlers;
};

#endif // T100EVENTHANDLER_H
