#ifndef T100ORDERPOP_H
#define T100ORDERPOP_H

#include "T100OrderBase.h"

namespace T100QU32{

class T100OrderPop : public T100OrderBase
{
    public:
        T100OrderPop(T100QU32*, T100Executor32*);
        virtual ~T100OrderPop();

        T100SentenceBase::T100OPERATOR_BUILD        target;

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERPOP_H
