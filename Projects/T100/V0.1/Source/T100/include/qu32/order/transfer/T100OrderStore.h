#ifndef T100ORDERSTORE_H
#define T100ORDERSTORE_H

#include "T100Order.h"

namespace T100QU32{

class T100OrderStore : public T100Order
{
    public:
        T100OrderStore(T100QU32*, T100Executor32*);
        virtual ~T100OrderStore();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERSTORE_H
