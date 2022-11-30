#ifndef T100BINOCULARBUILDER_H
#define T100BINOCULARBUILDER_H

#include "T100SentenceCommon.h"
#include "T100BuilderBase.h"
#include "T100BuildInfo.h"

namespace T100SentenceBase{

class T100BinocularBuilder : public T100BuilderBase
{
    public:
        T100BinocularBuilder(T100SentenceBase*);
        virtual ~T100BinocularBuilder();

        T100BOOL            build(T100Assembly::T100BuildInfo*, T100OPERATOR_BINOCULAR&, T100OPERATOR_BINOCULAR_BUILD&);

    protected:

    private:
};

}

#endif // T100BINOCULARBUILDER_H
