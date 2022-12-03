#ifndef T100ORDERMONO_H
#define T100ORDERMONO_H

#include "T100OrderComplexus.h"

namespace T100QU32{

class T100OrderMono : public T100OrderComplexus
{
    public:
        T100OrderMono(T100QU32*, T100Executor32*);
        virtual ~T100OrderMono();

        T100BOOL        parseMonoBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD&);

    protected:

    private:
};

}

#endif // T100ORDERMONO_H
