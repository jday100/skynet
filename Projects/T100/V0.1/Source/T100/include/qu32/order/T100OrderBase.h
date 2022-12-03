#ifndef T100ORDERBASE_H
#define T100ORDERBASE_H

#include "T100OrderBinocular.h"

namespace T100QU32{

class T100OrderBase : public T100OrderBinocular
{
    public:
        T100OrderBase(T100QU32*, T100Executor32*);
        virtual ~T100OrderBase();

    protected:

    private:
};

}

#endif // T100ORDERBASE_H
