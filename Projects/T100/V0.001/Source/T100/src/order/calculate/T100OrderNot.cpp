#include "T100OrderNot.h"

T100OrderNot::T100OrderNot(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderNot::~T100OrderNot()
{
    //dtor
}

T100BOOL T100OrderNot::run()
{
    getHost()->getAU32()->Not();

    return T100TRUE;
}

T100VOID T100OrderNot::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_NOT));
}
