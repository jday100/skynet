#ifndef T100ORDERLOOP_H
#define T100ORDERLOOP_H

#include "T100Order.h"


class T100OrderLoop : public T100Order
{
    public:
        T100OrderLoop(T100QU32*, T100Executor32*);
        virtual ~T100OrderLoop();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERLOOP_H
