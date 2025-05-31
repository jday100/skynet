#ifndef T100MENUEVENT_H
#define T100MENUEVENT_H

#include "gui/event/T100Event.h"

class T100MenuEvent : public T100Event
{
    public:
        T100MenuEvent(T100WindowMessageData&);
        virtual ~T100MenuEvent();

    protected:

    private:
};

#endif // T100MENUEVENT_H
