#include "T100OrderUnlock.h"

T100OrderUnlock::T100OrderUnlock(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderUnlock::~T100OrderUnlock()
{
    //dtor
}

T100BOOL T100OrderUnlock::run()
{
    getHost()->getInterrupt32()->unlock();

    return T100TRUE;
}

T100VOID T100OrderUnlock::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_UNLOCK));
}
