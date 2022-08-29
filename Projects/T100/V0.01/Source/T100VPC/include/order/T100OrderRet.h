#ifndef T100ORDERRET_H
#define T100ORDERRET_H

#include "T100Order.h"


class T100OrderRet : public T100Order
{
    public:
        T100OrderRet(T100QU32*, T100Executor32*);
        virtual ~T100OrderRet();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERRET_H
