#include "T100OrderCall.h"

T100OrderCall::T100OrderCall(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderCall::~T100OrderCall()
{
    //dtor
}

T100BOOL T100OrderCall::run()
{
    T100BOOL    result      = T100FALSE;

    result = loadMonoTarget(target);

    if(!result){
        return T100FALSE;
    }

    if(target.USED){
        getHost()->getInterrupt()->call(target.BASE.VALUE, target.OPERATOR.VALUE);
    }else{
        getHost()->getInterrupt()->call(target.OPERATOR.VALUE);
    }

    return T100TRUE;
}

T100VOID T100OrderCall::log()
{
    if(T100Log::running()){
        T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_CALL));
    }else{
        T100Log::start();
        T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_CALL));
        T100Log::stop();
    }
}
