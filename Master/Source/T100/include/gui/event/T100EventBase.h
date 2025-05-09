#ifndef T100EVENTBASE_H
#define T100EVENTBASE_H

#include "T100Common.h"
#include "T100Win32Common.h"
#include "T100Class.h"

class T100EventHandler;

typedef         T100VOID(T100EventHandler::*T100EVENT_CALL)(...);

class T100EventBase : public T100Class
{
    public:
        T100EventBase();
        T100EventBase(T100MESSAGE_DATA&);
        virtual ~T100EventBase();

        HWND                WINDOW_HWND;

        T100UINT            ID;
        T100UINT            FLAGS;

        T100UINT            MessageID;

    protected:

    private:
};

#endif // T100EVENTBASE_H
