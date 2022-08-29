#ifndef T100ORDERJUMP_H
#define T100ORDERJUMP_H

#include "T100Order.h"


class T100OrderJump : public T100Order
{
    public:
        T100OrderJump(T100QU32*, T100Executor32*);
        virtual ~T100OrderJump();

        T100OPERATOR_DOUBLE     target;

    protected:
        T100BOOL                run();
        T100VOID                log();

    private:
};

#endif // T100ORDERJUMP_H
