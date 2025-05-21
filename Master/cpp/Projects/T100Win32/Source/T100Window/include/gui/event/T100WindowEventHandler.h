#ifndef T100WINDOWEVENTHANDLER_H
#define T100WINDOWEVENTHANDLER_H

#include "gui/event/T100EventHandler.h"

class T100ApplicationEventHandler;

class T100WindowEventHandler : public T100EventHandler
{
    public:
        T100WindowEventHandler();
        virtual ~T100WindowEventHandler();

        T100ApplicationEventHandler*        GetApplicationPtr();

    protected:

    private:
};

#endif // T100WINDOWEVENTHANDLER_H
