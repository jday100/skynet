#include "T100OrderDebug.h"

T100OrderDebug::T100OrderDebug(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderDebug::~T100OrderDebug()
{
    //dtor
}

T100BOOL T100OrderDebug::run()
{
    getExecutor()->debug();

    return T100TRUE;
}

T100VOID T100OrderDebug::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_DEBUG));
}
