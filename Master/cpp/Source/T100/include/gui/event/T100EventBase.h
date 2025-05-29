#ifndef T100EVENTBASE_H
#define T100EVENTBASE_H

#include "base/T100Class.h"
#include "gui/data/T100WindowMessageData.h"

class T100EventBase : public T100Class
{
    public:
        T100EventBase(T100WindowMessageData&);
        virtual ~T100EventBase();

        T100WindowMessageData&          GetMessageData();

    protected:
        T100WindowMessageData           m_messageData;

    private:
};

#endif // T100EVENTBASE_H
