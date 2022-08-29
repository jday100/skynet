#include "T100OrderLoop.h"

T100OrderLoop::T100OrderLoop(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderLoop::~T100OrderLoop()
{
    //dtor
}

T100BOOL T100OrderLoop::run()
{
    T100WORD        offset;
    T100WORD        value;

    offset      = getHost()->getCU32()->step();
    value       = getHost()->getCU32()->getCCR();

    if(0 == value){

    }else{
        getHost()->getCU32()->setCCR(value - 1);
        getHost()->getCU32()->setCOR(offset);
    }

    return T100TRUE;
}

T100VOID T100OrderLoop::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_LOOP));
}
