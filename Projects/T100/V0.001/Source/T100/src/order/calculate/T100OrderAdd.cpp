#include "T100OrderAdd.h"
#include "T100QU32.h"


T100OrderAdd::T100OrderAdd(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderAdd::~T100OrderAdd()
{
    //dtor
}

T100BOOL T100OrderAdd::run()
{
    getHost()->getAU32()->Add();

    return T100TRUE;
}

T100VOID T100OrderAdd::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ADD));
}
