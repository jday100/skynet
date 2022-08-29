#ifndef T100ORDERLOCK_H
#define T100ORDERLOCK_H

#include "T100Order.h"


class T100OrderLock : public T100Order
{
    public:
        T100OrderLock(T100QU32*, T100Executor32*);
        virtual ~T100OrderLock();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERLOCK_H
