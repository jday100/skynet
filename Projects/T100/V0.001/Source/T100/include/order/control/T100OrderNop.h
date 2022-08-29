#ifndef T100ORDERNOP_H
#define T100ORDERNOP_H

#include "T100Order.h"


class T100OrderNop : public T100Order
{
    public:
        T100OrderNop(T100QU32*, T100Executor32*);
        virtual ~T100OrderNop();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERNOP_H
