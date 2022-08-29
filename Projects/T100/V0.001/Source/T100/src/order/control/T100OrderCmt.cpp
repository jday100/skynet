#include "T100OrderCmt.h"

T100OrderCmt::T100OrderCmt(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderCmt::~T100OrderCmt()
{
    //dtor
}

T100BOOL T100OrderCmt::run()
{
    id = getHost()->getCU32()->step();

    return T100TRUE;
}

T100VOID T100OrderCmt::log()
{
    //T100Log::info(T100VPCHint::cmt_hint(m_base, m_offset, id, T100VPC_ORDER_EXECUTE_CMT));


    if(T100Log::running()){
        T100Log::info(T100VPCHint::cmt_hint(m_base, m_offset, id, T100VPC_ORDER_EXECUTE_CMT));
    }else{
        T100Log::start();
        T100Log::info(T100VPCHint::cmt_hint(m_base, m_offset, id, T100VPC_ORDER_EXECUTE_CMT));
        T100Log::stop();
    }
}
