#ifndef T100EVENTHANDLER_H
#define T100EVENTHANDLER_H

#include <unordered_map>
#include <windows.h>
#include "T100Common.h"
#include "object/T100ObjectTreeNode.h"
#include "T100Event.h"
#include "gui/data/T100WindowMessageData.h"

class T100EventHandler;
class T100Win32Application;

typedef void(T100EventHandler::*T100EVENT_FUNCTION)(...);

typedef struct{
    T100EventHandler*           HANDLER         = T100NULL;
    T100EVENT_FUNCTION          FUNCTION;
}T100EVENT_FUNCTION_DATA;

#define     T100EVENT_FUNCTION_DATA_HASH        std::unordered_map<int, T100EVENT_FUNCTION_DATA>

class T100EventHandler : public T100ObjectTreeNode
{
    public:
        T100EventHandler();
        T100EventHandler(T100EventHandler*);
        virtual ~T100EventHandler();

        T100VOID                                Create(T100EventHandler*);
        T100VOID                                Destroy();

        virtual T100VOID                        Connect(T100WORD, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        virtual T100VOID                        ConnectMenu(T100WORD, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);

        T100Win32Application*                   GetApplicationPtr();

        T100VOID                                SendWindowMessage(T100WindowMessageData&);

        T100VOID                                ProcessWindowMessage(T100WindowMessageData&);

        T100EventHandler*                       ConvertToEventHandler(T100ObjectTreeNode*);

    protected:
        T100EVENT_FUNCTION_DATA_HASH            m_menus;
        T100EVENT_FUNCTION_DATA_HASH            m_events;

    private:
        T100VOID                                ProcessCommand(T100WindowMessageData&);
        T100VOID                                CallMenu(T100WORD, T100WindowMessageData&);
        T100VOID                                CallEvent(T100EVENT_TYPE, T100WindowMessageData&);
};

#endif // T100EVENTHANDLER_H
