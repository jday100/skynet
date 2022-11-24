#ifndef T100OPERATORBUILDER_H
#define T100OPERATORBUILDER_H

#include "T100SentenceCommon.h"
#include "T100BuilderBase.h"
#include "T100BuildInfo.h"

namespace T100SentenceBase{

class T100OperatorBuilder : public T100BuilderBase
{
    public:
        T100OperatorBuilder(T100SentenceBase*);
        virtual ~T100OperatorBuilder();

        T100BOOL            build(T100Assembly::T100BuildInfo*, T100OPERATOR&, T100OPERATOR_BUILD&);

    protected:

    private:
};

}

#endif // T100OPERATORBUILDER_H
