#ifndef T100NOTIFYEVENT_H
#define T100NOTIFYEVENT_H

#include "gui/event/T100Event.h"

namespace T100WINDOWS{

class T100NotifyEvent : public T100Event
{
    public:
        T100NotifyEvent(const T100WindowMessageData&);
        virtual ~T100NotifyEvent();

        T100VOID            SetID(T100UINT);
        T100UINT            GetID();

    protected:
        T100UINT            m_id        = 0;

    private:
};

}

#endif // T100NOTIFYEVENT_H
