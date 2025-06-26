#ifndef T100MENUEVENT_H
#define T100MENUEVENT_H

#include "gui/event/T100Event.h"

namespace T100WINDOWS{

class T100MenuEvent : public T100Event
{
    public:
        T100MenuEvent(const T100WindowMessageData&);
        virtual ~T100MenuEvent();

        T100VOID            SetID(T100UINT);
        T100UINT            GetID();

    protected:
        T100UINT            m_id;

    private:
};

}

#endif // T100MENUEVENT_H
