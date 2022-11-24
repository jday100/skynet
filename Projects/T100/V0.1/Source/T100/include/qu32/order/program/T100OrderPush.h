#ifndef T100ORDERPUSH_H
#define T100ORDERPUSH_H

#include "T100Order.h"

namespace T100QU32{

class T100OrderPush : public T100Order
{
    public:
        T100OrderPush(T100QU32*, T100Executor32*);
        virtual ~T100OrderPush();



    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERPUSH_H
