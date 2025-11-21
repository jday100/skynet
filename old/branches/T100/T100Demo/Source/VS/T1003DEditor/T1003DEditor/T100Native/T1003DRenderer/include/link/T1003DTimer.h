#ifndef T1003DTIMER_H
#define T1003DTIMER_H

#include "T100Common.h"

class T1003DTimer
{
    public:
        T1003DTimer();
        virtual ~T1003DTimer();

        virtual T100UINT32          GetFramesPerSecond() const = 0;

    protected:

    private:
};

#endif // T1003DTIMER_H
