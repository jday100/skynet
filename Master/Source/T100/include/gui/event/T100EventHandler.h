#ifndef T100EVENTHANDLER_H
#define T100EVENTHANDLER_H

#include <unordered_map>
#include "T100Class.h"
#include "T100Event.h"
#include "T100AllEvents.h"
#include "T100IDManager.h"

typedef struct{
    T100EVENT_CALL      CALL            = 0;
    T100EventHandler*   HANDLER         = T100NULL;
}T100EVENT_CALL_DATA;

#define     T100EVENT_WINDOW_HANDLER_HASH           std::unordered_map<HWND, T100EventHandler*>
#define     T100EVENT_HANDLER_HASH                  std::unordered_map<T100UINT, T100EventHandler*>
#define     T100EVENT_CALL_HASH                     std::unordered_map<T100UINT, T100EVENT_CALL_DATA>
#define     T100WINDOW_CLASS_HASH                   std::unordered_map<T100WSTRING, T100BOOL>

class T100EventHandler : public T100Class
{
    public:
        T100EventHandler();
        virtual ~T100EventHandler();

        virtual T100VOID            Connect(T100EVENT_TYPE, T100EVENT_CALL, T100EventHandler* = T100NULL);
        virtual T100VOID            Connect(T100EVENT_TYPE, T100UINT, T100EVENT_CALL, T100EventHandler* = T100NULL);

        T100VOID                    Register(HWND, T100EventHandler*);
        T100VOID                    Register(T100UINT, T100EventHandler*);
        T100BOOL                    RegisterWindowClass(T100WSTRING);

        T100VOID                    ProcessCommand(T100Event&);
        T100VOID                    ProcessEvent(T100Event&);
        T100VOID                    ProcessMenu(T100Event&);

        T100VOID                    DispatchEvent(T100Event&);

        T100VOID                    DispatchMessage(T100MESSAGE_DATA&);

    protected:
        static T100IDManager                        m_idManager;

    private:
        T100EVENT_CALL_HASH                         m_menus;
        T100EVENT_CALL_HASH                         m_events;
        T100EVENT_CALL_HASH                         m_commands;
        static T100EVENT_WINDOW_HANDLER_HASH        m_windows;
        static T100EVENT_HANDLER_HASH               m_handlers;
        static T100WINDOW_CLASS_HASH                m_windowClass;
};

#endif // T100EVENTHANDLER_H
