#ifndef T100COMMANDEVENT_H
#define T100COMMANDEVENT_H

#include "gui/event/T100Event.h"

namespace T100WINDOWS{

class T100CommandEvent : public T100Event
{
    public:
        T100CommandEvent(const T100WindowMessageData&);
        virtual ~T100CommandEvent();

    protected:

    private:
};

}

#endif // T100COMMANDEVENT_H
