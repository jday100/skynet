#ifndef T100KEYEVENT_H
#define T100KEYEVENT_H

#include "gui/event/T100Event.h"

namespace T100WINDOWS{

class T100KeyEvent : public T100Event
{
    public:
        T100KeyEvent(const T100WindowMessageData&);
        virtual ~T100KeyEvent();

    protected:

    private:
};

}

#endif // T100KEYEVENT_H
