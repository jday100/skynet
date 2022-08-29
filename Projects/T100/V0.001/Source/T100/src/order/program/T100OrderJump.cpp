#include "T100OrderJump.h"

T100OrderJump::T100OrderJump(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderJump::~T100OrderJump()
{
    //dtor
}

T100BOOL T100OrderJump::run()
{
    T100BOOL        result;

    result = loadMonoTarget(target);

    if(result){
        if(target.USED){
            getHost()->getCU32()->setCBR(target.BASE.VALUE);
        }
        getHost()->getCU32()->setCOR(target.OPERATOR.VALUE);
    }

    return result;
}

T100VOID T100OrderJump::log()
{
    if(T100Log::running()){
        T100Log::info(T100VPCHint::order_hint(m_base, m_offset, target, T100VPC_ORDER_EXECUTE_JUMP));
    }else{
        T100Log::start();
        T100Log::info(T100VPCHint::order_hint(m_base, m_offset, target, T100VPC_ORDER_EXECUTE_JUMP));
        T100Log::stop();
    }
}
