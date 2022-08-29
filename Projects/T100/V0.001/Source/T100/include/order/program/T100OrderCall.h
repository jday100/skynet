#ifndef T100ORDERCALL_H
#define T100ORDERCALL_H

#include "T100Order.h"


class T100OrderCall : public T100Order
{
    public:
        T100OrderCall(T100QU32*, T100Executor32*);
        virtual ~T100OrderCall();

        T100OPERATOR_DOUBLE     target;

    protected:
        T100BOOL                run();
        T100VOID                log();

    private:
};

#endif // T100ORDERCALL_H
