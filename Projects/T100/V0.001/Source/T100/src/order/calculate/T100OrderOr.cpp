#include "T100OrderOr.h"

T100OrderOr::T100OrderOr(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderOr::~T100OrderOr()
{
    //dtor
}

T100BOOL T100OrderOr::run()
{
    getHost()->getAU32()->Or();

    return T100TRUE;
}

T100VOID T100OrderOr::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_OR));
}
