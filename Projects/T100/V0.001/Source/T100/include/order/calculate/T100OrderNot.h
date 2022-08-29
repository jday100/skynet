#ifndef T100ORDERNOT_H
#define T100ORDERNOT_H

#include "T100Order.h"


class T100OrderNot : public T100Order
{
    public:
        T100OrderNot(T100QU32*, T100Executor32*);
        virtual ~T100OrderNot();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERNOT_H
