#ifndef T100ORDERADD_H
#define T100ORDERADD_H

#include "T100Order.h"


class T100OrderAdd : public T100Order
{
    public:
        T100OrderAdd(T100QU32*, T100Executor32*);
        virtual ~T100OrderAdd();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERADD_H
