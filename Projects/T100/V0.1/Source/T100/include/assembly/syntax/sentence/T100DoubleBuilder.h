#ifndef T100DOUBLEBUILDER_H
#define T100DOUBLEBUILDER_H

#include "T100SentenceCommon.h"
#include "T100BuilderBase.h"
#include "T100BuildInfo.h"

namespace T100SentenceBase{

class T100DoubleBuilder : public T100BuilderBase
{
    public:
        T100DoubleBuilder(T100SentenceBase*);
        virtual ~T100DoubleBuilder();

        T100BOOL            build();

    protected:

    private:
};

}

#endif // T100DOUBLEBUILDER_H
