#ifndef T100ORDERHALT_H
#define T100ORDERHALT_H

#include "T100Order.h"


class T100OrderHalt : public T100Order
{
    public:
        T100OrderHalt(T100QU32*, T100Executor32*);
        virtual ~T100OrderHalt();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERHALT_H
