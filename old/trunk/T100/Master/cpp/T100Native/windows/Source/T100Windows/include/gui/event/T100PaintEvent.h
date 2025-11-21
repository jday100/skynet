#ifndef T100PAINTEVENT_H
#define T100PAINTEVENT_H

#include "gui/event/T100Event.h"

namespace T100WINDOWS{

class T100PaintEvent : public T100Event
{
    public:
        T100PaintEvent(const T100WindowMessageData&);
        virtual ~T100PaintEvent();

    protected:

    private:
};

}

#endif // T100PAINTEVENT_H
