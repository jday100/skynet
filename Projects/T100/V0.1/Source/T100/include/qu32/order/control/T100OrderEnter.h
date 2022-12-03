#ifndef T100ORDERENTER_H
#define T100ORDERENTER_H

#include "T100OrderBase.h"

namespace T100QU32{

class T100OrderEnter : public T100OrderBase
{
    public:
        T100OrderEnter(T100QU32*, T100Executor32*);
        virtual ~T100OrderEnter();

        T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD      target;

    protected:
        T100BOOL            run();

        T100VOID            log();

    private:
};

}

#endif // T100ORDERENTER_H
