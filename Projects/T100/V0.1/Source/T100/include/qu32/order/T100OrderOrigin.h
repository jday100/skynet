#ifndef T100ORDERORIGIN_H
#define T100ORDERORIGIN_H

#include "T100SentenceCommon.h"
#include "T100Order.h"
#include "T100Gdt32.h"

namespace T100QU32{

class T100OrderOrigin : public T100Order
{
    public:
        T100OrderOrigin(T100QU32*, T100Executor32*);
        virtual ~T100OrderOrigin();

    protected:
        T100Gdt32*          getGdt();

        T100BOOL            push(T100WORD);
        T100BOOL            pop(T100WORD&);

        T100BOOL            pushAll();
        T100BOOL            popAll();

        T100BOOL            getAddrType(T100BYTE, T100SentenceBase::T100ADDRESSING_TYPE&);

    private:
};

}

#endif // T100ORDERORIGIN_H
