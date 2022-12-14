#ifndef T100ORDEROUT_H
#define T100ORDEROUT_H

#include "T100Order.h"

namespace T100QU32{

class T100OrderOut : public T100Order
{
    public:
        T100OrderOut(T100QU32*, T100Executor32*);
        virtual ~T100OrderOut();

        T100Component::T100OPERATOR_DOUBLE         target;
        T100Component::T100OPERATOR_DOUBLE         source;

    protected:
        T100BOOL                    run();
        T100VOID                    log();

    private:
};

}

#endif // T100ORDEROUT_H
