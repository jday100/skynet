#ifndef T100ORDERIN_H
#define T100ORDERIN_H

#include "T100Order.h"


class T100OrderIn : public T100Order
{
    public:
        T100OrderIn(T100QU32*, T100Executor32*);
        virtual ~T100OrderIn();

        T100OPERATOR_DOUBLE     target;
        T100OPERATOR_DOUBLE     source;

    protected:
        T100BOOL                run();
        T100VOID                log();

    private:
};

#endif // T100ORDERIN_H
