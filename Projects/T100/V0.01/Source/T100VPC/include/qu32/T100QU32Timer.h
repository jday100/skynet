#ifndef T100QU32TIMER_H
#define T100QU32TIMER_H

#include "T100Timer.h"
class T100QU32;


class T100QU32Timer : public T100Timer
{
    public:
        T100QU32Timer();
        virtual ~T100QU32Timer();

        T100VOID            setHost(T100QU32*);
        T100QU32*           getHost();

    protected:
        T100VOID            run();

        T100BOOL            OnTimer();

    private:
        T100QU32*           m_host          = T100NULL;

};

#endif // T100QU32TIMER_H
