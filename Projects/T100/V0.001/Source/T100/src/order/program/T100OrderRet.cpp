#include "T100OrderRet.h"

T100OrderRet::T100OrderRet(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderRet::~T100OrderRet()
{
    //dtor
}

T100BOOL T100OrderRet::run()
{
    getHost()->getInterrupt()->ret();

    return T100TRUE;
}

T100VOID T100OrderRet::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_RET));
}
