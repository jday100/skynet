#ifndef T100COMMANDEVENT_H
#define T100COMMANDEVENT_H

#include "T100Event.h"

class T100CommandEvent : public T100Event
{
    public:
        T100CommandEvent();
        T100CommandEvent(T100MESSAGE_DATA&);
        virtual ~T100CommandEvent();

    protected:

    private:
};

#endif // T100COMMANDEVENT_H
