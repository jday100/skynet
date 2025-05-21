#ifndef T100WINDOWEVENT_H
#define T100WINDOWEVENT_H

#include "gui/event/T100Event.h"

class T100WindowEvent : public T100Event
{
    public:
        T100WindowEvent(T100WindowMessageData&);
        virtual ~T100WindowEvent();

    protected:

    private:
};

#endif // T100WINDOWEVENT_H
