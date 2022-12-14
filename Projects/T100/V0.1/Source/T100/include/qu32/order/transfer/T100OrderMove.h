#ifndef T100ORDERMOVE_H
#define T100ORDERMOVE_H

#include "T100Order.h"

namespace T100QU32{

class T100OrderMove : public T100Order
{
    public:
        T100OrderMove(T100QU32*, T100Executor32*);
        virtual ~T100OrderMove();

        T100Component::T100OPERATOR_DOUBLE         target;
        T100Component::T100OPERATOR_DOUBLE         source;

    protected:
        T100BOOL                    run();
        T100VOID                    log();

    private:
};

}

#endif // T100ORDERMOVE_H
