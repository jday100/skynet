#ifndef T100EVENT_H
#define T100EVENT_H

#include "base/T100Class.h"
#include "gui/data/T100WindowMessageData.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Event : public T100Class
{
    public:
        T100Event(const T100WindowMessageData&);
        virtual ~T100Event();

    protected:
        T100WindowMessageData           m_message;

    private:
};

}

#endif // T100EVENT_H
