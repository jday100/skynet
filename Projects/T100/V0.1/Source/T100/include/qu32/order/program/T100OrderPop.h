#ifndef T100ORDERPOP_H
#define T100ORDERPOP_H

#include "T100Order.h"

namespace T100QU32{

class T100OrderPop : public T100Order
{
    public:
        T100OrderPop(T100QU32*, T100Executor32*);
        virtual ~T100OrderPop();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERPOP_H
