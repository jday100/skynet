#ifndef T100ORDERDOUBLE_H
#define T100ORDERDOUBLE_H

#include "T100OrderMono.h"

namespace T100QU32{

class T100OrderDouble : public T100OrderMono
{
    public:
        T100OrderDouble(T100QU32*, T100Executor32*);
        virtual ~T100OrderDouble();

        T100BOOL        parseDoubleBuild(T100SentenceBase::T100OPERATOR_DOUBLE_BUILD&);

    protected:

    private:
};

}

#endif // T100ORDERDOUBLE_H
