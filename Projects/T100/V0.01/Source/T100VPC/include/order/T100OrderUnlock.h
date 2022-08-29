#ifndef T100ORDERUNLOCK_H
#define T100ORDERUNLOCK_H

#include "T100Order.h"


class T100OrderUnlock : public T100Order
{
    public:
        T100OrderUnlock(T100QU32*, T100Executor32*);
        virtual ~T100OrderUnlock();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERUNLOCK_H
