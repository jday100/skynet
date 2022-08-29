#ifndef T100ORDERMUL_H
#define T100ORDERMUL_H

#include "T100Order.h"


class T100OrderMul : public T100Order
{
    public:
        T100OrderMul(T100QU32*, T100Executor32*);
        virtual ~T100OrderMul();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERMUL_H
