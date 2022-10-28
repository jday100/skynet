#ifndef T100CLOCK_H
#define T100CLOCK_H

#include "T100Common.h"
#include "T100Class.h"

namespace T100Library{

class T100Clock : public T100Class
{
    public:
        T100Clock();
        virtual ~T100Clock();

        static T100WORD         seconds();

        static T100DWORD        milliseconds();

        static T100DWORD        microseconds();

        static T100DWORD        nanoseconds();

    protected:

    private:
};

}

#endif // T100CLOCK_H
