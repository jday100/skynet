#ifndef T100ORDERALL_H
#define T100ORDERALL_H

#include "T100OrderOperator.h"

namespace T100QU32{

class T100OrderAll : public T100OrderOperator
{
    public:
        T100OrderAll(T100QU32*, T100Executor32*);
        virtual ~T100OrderAll();

        T100BOOL        parseOperatorAllBuild(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL        loadOperatorAllBuild(T100BYTE, T100SentenceBase::T100OPERATOR_BUILD&);

        //
        T100BOOL        parsePushAllBuild();
        T100BOOL        parsePopAllBuild();

    protected:
        T100BOOL        loadAllRegister(T100SentenceBase::T100OPERATOR_BUILD&);

    private:
};

}

#endif // T100ORDERALL_H
