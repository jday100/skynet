#ifndef T100CLOCK_H
#define T100CLOCK_H

#include "T100Common.h"


class T100Clock
{
    public:
        T100Clock();
        virtual ~T100Clock();

        T100WORD            seconds();

        T100DWORD           milliseconds();

        T100DWORD           microseconds();

        T100DWORD           nanoseconds();

    protected:

    private:
};

#endif // T100CLOCK_H
