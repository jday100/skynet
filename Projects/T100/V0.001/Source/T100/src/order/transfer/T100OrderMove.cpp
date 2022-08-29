#include "T100OrderMove.h"


T100OrderMove::T100OrderMove(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderMove::~T100OrderMove()
{
    //dtor
}

T100BOOL T100OrderMove::run()
{
    T100BOOL        result;

    result = parse(target, source);

    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    /*
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

    T100WORD    value;

    result = getSource(source, value);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }

    result = setTarget(target, value);
    if(!result){
        T100VPCError::error(T100VPCHint::order_hint(m_base, m_offset, T100VPC_ORDER_EXECUTE_ERROR));
        return T100FALSE;
    }
    */

    return result;
}

T100VOID T100OrderMove::log()
{
    T100Log::info(T100VPCHint::order_hint(m_base, m_offset, target, source, T100VPC_ORDER_EXECUTE_MOVE));
}
