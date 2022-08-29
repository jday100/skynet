#ifndef T100ORDERDEBUG_H
#define T100ORDERDEBUG_H

#include "T100Order.h"


class T100OrderDebug : public T100Order
{
    public:
        T100OrderDebug(T100QU32*, T100Executor32*);
        virtual ~T100OrderDebug();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

#endif // T100ORDERDEBUG_H
