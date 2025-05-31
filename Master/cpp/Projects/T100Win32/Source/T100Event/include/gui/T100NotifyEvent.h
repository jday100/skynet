#ifndef T100NOTIFYEVENT_H
#define T100NOTIFYEVENT_H

#include "gui/event/T100Event.h"

class T100NotifyEvent : public T100Event
{
    public:
        T100NotifyEvent(T100WindowMessageData&);
        virtual ~T100NotifyEvent();

        T100VOID            SetID(T100WORD);
        T100WORD&           GetID();

    protected:
        T100WORD            m_id        = 0;

    private:
};

#endif // T100NOTIFYEVENT_H
