#include "T100OrderOut.h"

#include "T100VPCError.h"


T100OrderOut::T100OrderOut(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderOut::~T100OrderOut()
{
    //dtor
}

T100BOOL T100OrderOut::run()
{
    T100BOOL        result          = T100TRUE;

    result = load(target, source);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    result = loadTarget(target);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    result = loadSource(source);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    T100WORD        value;

    result = getSource(source, value);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    result = setIOTarget(target, value);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    return result;
}

T100VOID T100OrderOut::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_OUT));
}
