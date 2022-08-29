#ifndef T100ORDERINT_H
#define T100ORDERINT_H

#include "T100Order.h"


class T100OrderInt : public T100Order
{
    public:
        T100OrderInt(T100QU32*, T100Executor32*);
        virtual ~T100OrderInt();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERINT_H
