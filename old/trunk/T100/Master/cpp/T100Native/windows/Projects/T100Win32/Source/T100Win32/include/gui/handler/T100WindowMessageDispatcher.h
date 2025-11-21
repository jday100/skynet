#ifndef T100WINDOWMESSAGEDISPATCHER_H
#define T100WINDOWMESSAGEDISPATCHER_H

#include <unordered_map>
#include "base/T100Class.h"
#include "gui/data/T100WindowMessageData.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100EventHandler;

#define     T100EVENT_CONTROL_HANDLER_HASH                  std::unordered_map<T100UINT, T100EventHandler*>
#define     T100EVENT_WINDOW_HANDLER_HASH                   std::unordered_map<HWND, T100EventHandler*>

class T100WindowMessageDispatcher : public T100Class
{
    public:
        T100WindowMessageDispatcher();
        virtual ~T100WindowMessageDispatcher();

        T100BOOL                    RegisterControlHandler(T100UINT, T100EventHandler*);
        T100BOOL                    RegisterWindowHandler(HWND, T100EventHandler*);
        T100VOID                    DispatchWindowMessage(const T100WindowMessageData&);

        T100EventHandler*           GetControlHandler(T100UINT);

    protected:
        T100EVENT_CONTROL_HANDLER_HASH          m_controlHandlers;
        T100EVENT_WINDOW_HANDLER_HASH           m_windowHandlers;

    private:
};

}

#endif // T100WINDOWMESSAGEDISPATCHER_H
