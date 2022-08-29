#include "T100OrderIret.h"

T100OrderIret::T100OrderIret(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderIret::~T100OrderIret()
{
    //dtor
}

T100BOOL T100OrderIret::run()
{
    getHost()->getInterrupt32()->iret();

    return T100TRUE;
}

T100VOID T100OrderIret::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_IRET));
}
