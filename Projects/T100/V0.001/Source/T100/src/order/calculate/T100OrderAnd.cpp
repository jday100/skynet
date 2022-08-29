#include "T100OrderAnd.h"

T100OrderAnd::T100OrderAnd(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderAnd::~T100OrderAnd()
{
    //dtor
}

T100BOOL T100OrderAnd::run()
{
    getHost()->getAU32()->And();

    return T100TRUE;
}

T100VOID T100OrderAnd::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_AND));
}
