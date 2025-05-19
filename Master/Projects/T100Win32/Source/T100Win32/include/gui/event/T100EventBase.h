#ifndef T100EVENTBASE_H
#define T100EVENTBASE_H

#include "gui/T100Win32Common.h"
#include "gui/data/T100WindowMessageData.h"

class T100EventBase
{
    public:
        T100EventBase(T100WindowMessageData&);
        virtual ~T100EventBase();

    protected:

    private:
};

#endif // T100EVENTBASE_H
