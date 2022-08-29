#include "T100OrderMul.h"

T100OrderMul::T100OrderMul(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderMul::~T100OrderMul()
{
    //dtor
}

T100BOOL T100OrderMul::run()
{
    getHost()->getAU32()->Mul();

    return T100TRUE;
}

T100VOID T100OrderMul::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_MUL));
}
