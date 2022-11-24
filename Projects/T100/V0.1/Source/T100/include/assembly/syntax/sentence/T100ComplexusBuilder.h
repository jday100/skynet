#ifndef T100COMPLEXUSBUILDER_H
#define T100COMPLEXUSBUILDER_H

#include "T100SentenceCommon.h"
#include "T100BuilderBase.h"
#include "T100BuildInfo.h"

namespace T100SentenceBase{

class T100ComplexusBuilder : public T100BuilderBase
{
    public:
        T100ComplexusBuilder(T100SentenceBase*);
        virtual ~T100ComplexusBuilder();

        T100BOOL            build();

    protected:

    private:
};

}

#endif // T100COMPLEXUSBUILDER_H
