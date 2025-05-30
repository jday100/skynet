#ifndef T100WINDOWMESSAGEDISPATCHER_H
#define T100WINDOWMESSAGEDISPATCHER_H

#include <unordered_map>
#include "T100Common.h"
#include "gui/data/T100WindowMessageData.h"

class T100EventHandler;

#define     T100EVENT_CONTROL_HANDLER_HASH          std::unordered_map<T100WORD, T100EventHandler*>
#define     T100EVENT_WINDOW_HANDLER_HASH           std::unordered_map<HWND, T100EventHandler*>

class T100WindowMessageDispatcher
{
    public:
        T100WindowMessageDispatcher();
        virtual ~T100WindowMessageDispatcher();

        T100BOOL                    RegisterControlHandler(T100WORD, T100EventHandler*);
        T100BOOL                    RegisterWindowHandler(HWND, T100EventHandler*);
        T100VOID                    DispatchWindowMessage(T100WindowMessageData&);

        T100EventHandler*           GetControlHandler(T100WORD);

    protected:

    private:
        T100EVENT_CONTROL_HANDLER_HASH          m_controlHandlers;
        T100EVENT_WINDOW_HANDLER_HASH           m_windowHandlers;
};

#endif // T100WINDOWMESSAGEDISPATCHER_H
