#ifndef T100ORDERBINOCULAR_H
#define T100ORDERBINOCULAR_H

#include "T100OrderDouble.h"

namespace T100QU32{

class T100OrderBinocular : public T100OrderDouble
{
    public:
        T100OrderBinocular(T100QU32*, T100Executor32*);
        virtual ~T100OrderBinocular();

        T100BOOL        parseBinocularBuild(T100SentenceBase::T100OPERATOR_BINOCULAR_BUILD&);

        T100BOOL        loadBinocularBuild(T100SentenceBase::T100OPERATOR_BINOCULAR_BUILD&);

    protected:

    private:
};

}

#endif // T100ORDERBINOCULAR_H
