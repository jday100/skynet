#ifndef T100ORDERBASE_H
#define T100ORDERBASE_H

#include "T100SentenceCommon.h"
#include "T100Order.h"
#include "T100Gdt32.h"

namespace T100QU32{

class T100OrderBase : public T100Order
{
    public:
        T100OrderBase(T100QU32*, T100Executor32*);
        virtual ~T100OrderBase();

    protected:
        T100Gdt32*      getGdt();

        T100BOOL        parseByteBuild(T100BYTE&);
        T100BOOL        parseWordBuild(T100WORD&);
        T100BOOL        parseLongWordBuild(T100LONG&);


        T100BOOL        parseOperatorBuild(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        parseComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);
        T100BOOL        parseBinocularBuild(T100SentenceBase::T100OPERATOR_BINOCULAR_BUILD&);

        ////

        T100BOOL        loadOperatorBuild(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        loadComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        loadOperatorAllBuild(T100SentenceBase::T100OPERATOR_BUILD&);

        ////

        T100BOOL        getOperatorValue(T100SentenceBase::T100OPERATOR_BUILD&);

        ////

        T100BOOL        loadRegister(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        loadMemory(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL        getRegister(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        getMemory(T100SentenceBase::T100OPERATOR_BUILD&);

        T100BOOL        setRegister(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        setMemory(T100SentenceBase::T100OPERATOR_BUILD&);

        ////

        T100BOOL        loadOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        loadComplexusTarget(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        loadOperatorSource(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        loadComplexusSource(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        setOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        setComplexusTarget(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        inputOperatorSource(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        inputComplexusSource(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        outputOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD&);
        T100BOOL        outputComplexusTarget(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        push(T100WORD);
        T100BOOL        pop(T100WORD&);

        T100BOOL        pushAll();
        T100BOOL        popAll();

    private:
};

}

#endif // T100ORDERBASE_H
