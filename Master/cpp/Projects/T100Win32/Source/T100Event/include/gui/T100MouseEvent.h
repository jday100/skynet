#ifndef T100MOUSEEVENT_H
#define T100MOUSEEVENT_H

#include "gui/event/T100Event.h"

class T100MouseEvent : public T100Event
{
    public:
        T100MouseEvent(T100WindowMessageData&);
        virtual ~T100MouseEvent();

    protected:

    private:
};

#endif // T100MOUSEEVENT_H
