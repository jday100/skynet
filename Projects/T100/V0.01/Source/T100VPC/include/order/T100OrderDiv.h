#ifndef T100ORDERDIV_H
#define T100ORDERDIV_H

#include "T100Order.h"


class T100OrderDiv : public T100Order
{
    public:
        T100OrderDiv(T100QU32*, T100Executor32*);
        virtual ~T100OrderDiv();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERDIV_H
