#ifndef T100EVENT_H
#define T100EVENT_H

#include "gui/event/T100EventBase.h"

class T100Event : public T100EventBase
{
    public:
        T100Event(T100WindowMessageData&);
        virtual ~T100Event();

    protected:

    private:
};

#endif // T100EVENT_H
