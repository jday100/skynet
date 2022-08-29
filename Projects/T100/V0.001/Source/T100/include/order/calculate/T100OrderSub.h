#ifndef T100ORDERSUB_H
#define T100ORDERSUB_H

#include "T100Order.h"


class T100OrderSub : public T100Order
{
    public:
        T100OrderSub(T100QU32*, T100Executor32*);
        virtual ~T100OrderSub();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERSUB_H
