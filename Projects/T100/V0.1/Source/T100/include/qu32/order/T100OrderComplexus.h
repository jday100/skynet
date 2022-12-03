#ifndef T100ORDERCOMPLEXUS_H
#define T100ORDERCOMPLEXUS_H

#include "T100OrderAll.h"

namespace T100QU32{

class T100OrderComplexus : public T100OrderAll
{
    public:
        T100OrderComplexus(T100QU32*, T100Executor32*);
        virtual ~T100OrderComplexus();

        T100BOOL        parseComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

        T100BOOL        loadComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);
        T100BOOL        getComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

    protected:

    private:
};

}

#endif // T100ORDERCOMPLEXUS_H
