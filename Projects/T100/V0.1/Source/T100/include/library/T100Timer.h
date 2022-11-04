#ifndef T100TIMER_H
#define T100TIMER_H

#include "T100Common.h"
#include "T100Thread.h"

namespace T100Library{

class T100Timer : public T100Thread
{
    public:
        T100Timer();
        virtual ~T100Timer();

    protected:
        virtual T100BOOL            OnTimer() = 0;

    private:
};

}

#endif // T100TIMER_H
