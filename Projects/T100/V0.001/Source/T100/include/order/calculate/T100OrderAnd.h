#ifndef T100ORDERAND_H
#define T100ORDERAND_H

#include "T100Order.h"


class T100OrderAnd : public T100Order
{
    public:
        T100OrderAnd(T100QU32*, T100Executor32*);
        virtual ~T100OrderAnd();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERAND_H
