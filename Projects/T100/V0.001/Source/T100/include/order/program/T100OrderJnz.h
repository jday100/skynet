#ifndef T100ORDERJNZ_H
#define T100ORDERJNZ_H

#include "T100Order.h"


class T100OrderJnz : public T100Order
{
    public:
        T100OrderJnz(T100QU32*, T100Executor32*);
        virtual ~T100OrderJnz();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERJNZ_H
