#include "T100OrderDiv.h"

T100OrderDiv::T100OrderDiv(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderDiv::~T100OrderDiv()
{
    //dtor
}

T100BOOL T100OrderDiv::run()
{
    getHost()->getAU32()->Div();

    return T100TRUE;
}

T100VOID T100OrderDiv::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_DIV));
}
