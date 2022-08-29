#ifndef T100ORDERMOVE_H
#define T100ORDERMOVE_H

#include "T100Order.h"


class T100OrderMove : public T100Order
{
    public:
        T100OrderMove(T100QU32*, T100Executor32*);
        virtual ~T100OrderMove();

        T100OPERATOR_DOUBLE     target;
        T100OPERATOR_DOUBLE     source;

    protected:
        T100BOOL                run();
        T100VOID                log();

    private:
};

#endif // T100ORDERMOVE_H
