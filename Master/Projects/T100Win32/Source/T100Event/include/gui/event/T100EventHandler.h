#ifndef T100EVENTHANDLER_H
#define T100EVENTHANDLER_H

#include <unordered_map>
#include "T100Common.h"
#include "gui/event/T100Event.h"
#include "object/T100ObjectTreeNode.h"
#include "gui/data/T100WindowMessageData.h"

class T100EventHandler;

typedef T100VOID(T100EventHandler::*T100EVENT_FUNCTION)(...);

typedef struct{
    T100EventHandler*       HANDLER         = T100NULL;
    T100EVENT_FUNCTION      FUNCTION;
}T100EVENT_FUNCTION_DATA;

#define     T100EVENT_FUNCTION_DATA_HASH        std::unordered_map<T100INT, T100EVENT_FUNCTION_DATA>

class T100EventHandler : public T100ObjectTreeNode
{
    public:
        T100EventHandler();
        T100EventHandler(T100WSTRING, T100EventHandler*);
        virtual ~T100EventHandler();

        T100VOID                                Create(T100WSTRING, T100EventHandler*);
        T100VOID                                Destroy();

        virtual T100VOID                        Connect(T100WORD, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        virtual T100VOID                        ConnectMenu(T100WORD, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);

        T100VOID                                SendWindowMessage(T100WindowMessageData&);

        T100VOID                                ProcessWindowMessage(T100WindowMessageData&);

        T100EventHandler*                       ConvertToEventHandler(T100ObjectTreeNode*);

    protected:
        T100EVENT_FUNCTION_DATA_HASH            m_menuEvents;
        T100EVENT_FUNCTION_DATA_HASH            m_events;

    private:
        T100VOID                                ProcessCommand(T100WindowMessageData&);
        T100VOID                                CallMenu(T100WORD, T100WindowMessageData&);
        T100VOID                                CallEvent(T100WORD, T100WindowMessageData&);
};

#endif // T100EVENTHANDLER_H
