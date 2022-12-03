#ifndef T100ORDERPORT_H
#define T100ORDERPORT_H

#include "T100OrderAll.h"

namespace T100QU32{

class T100OrderPort : public T100OrderAll
{
    public:
        T100OrderPort(T100QU32*, T100Executor32*);
        virtual ~T100OrderPort();

    protected:
        T100BOOL        inputOperatorSource(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL        outputOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD&);

    private:
};

}

#endif // T100ORDERPORT_H
