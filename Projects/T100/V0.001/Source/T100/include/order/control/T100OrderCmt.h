#ifndef T100ORDERCMT_H
#define T100ORDERCMT_H

#include "T100Order.h"


class T100OrderCmt : public T100Order
{
    public:
        T100OrderCmt(T100QU32*, T100Executor32*);
        virtual ~T100OrderCmt();

        T100WORD        id;

    protected:
        T100BOOL        run();
        T100VOID        log();

    private:
};

#endif // T100ORDERCMT_H
