#ifndef T100ORDERJZ_H
#define T100ORDERJZ_H

#include "T100Order.h"


class T100OrderJz : public T100Order
{
    public:
        T100OrderJz(T100QU32*, T100Executor32*);
        virtual ~T100OrderJz();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERJZ_H
