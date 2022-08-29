#ifndef T100ORDEROR_H
#define T100ORDEROR_H

#include "T100Order.h"


class T100OrderOr : public T100Order
{
    public:
        T100OrderOr(T100QU32*, T100Executor32*);
        virtual ~T100OrderOr();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDEROR_H
