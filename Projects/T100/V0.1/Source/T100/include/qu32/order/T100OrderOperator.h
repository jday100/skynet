#ifndef T100ORDEROPERATOR_H
#define T100ORDEROPERATOR_H

#include "T100OrderOrigin.h"

namespace T100QU32{

class T100OrderOperator : public T100OrderOrigin
{
    public:
        T100OrderOperator(T100QU32*, T100Executor32*);
        virtual ~T100OrderOperator();

    protected:
        T100BOOL            parseByteBuild(T100BYTE&);
        T100BOOL            parseWordBuild(T100WORD&);
        T100BOOL            parseLongWordBuild(T100LONG&);

        T100BOOL            loadOperatorBuild(T100BYTE, T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL            loadRegister(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL            loadMemory(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL            getOperatorSource(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL            getRegister(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL            getMemory(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL            setOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL            setRegister(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL            setMemory(T100SentenceBase::T100OPERATOR_BUILD&);

    private:
};

}

#endif // T100ORDEROPERATOR_H
