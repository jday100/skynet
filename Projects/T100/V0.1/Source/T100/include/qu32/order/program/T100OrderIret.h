#ifndef T100ORDERIRET_H
#define T100ORDERIRET_H

#include "T100Order.h"

namespace T100QU32{

class T100OrderIret : public T100Order
{
    public:
        T100OrderIret(T100QU32*, T100Executor32*);
        virtual ~T100OrderIret();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERIRET_H
