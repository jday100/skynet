#include "T100OrderInt.h"

T100OrderInt::T100OrderInt(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderInt::~T100OrderInt()
{
    //dtor
}

T100BOOL T100OrderInt::run()
{
    T100BYTE            id;
    T100WORD_BITS       order;

    order.WORD          = m_order;
    id                  = order.BYTE3.BYTE;

    getHost()->getInterrupt32()->icall(id);

    return T100TRUE;
}

T100VOID T100OrderInt::log()
{

}
