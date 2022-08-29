#include "T100OrderLock.h"

T100OrderLock::T100OrderLock(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderLock::~T100OrderLock()
{
    //dtor
}

T100BOOL T100OrderLock::run()
{
    getHost()->getInterrupt32()->lock();

    return T100TRUE;
}

T100VOID T100OrderLock::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_LOCK));
}
