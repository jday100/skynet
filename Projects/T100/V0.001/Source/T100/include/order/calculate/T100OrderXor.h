#ifndef T100ORDERXOR_H
#define T100ORDERXOR_H

#include "T100Order.h"


class T100OrderXor : public T100Order
{
    public:
        T100OrderXor(T100QU32*, T100Executor32*);
        virtual ~T100OrderXor();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERXOR_H
