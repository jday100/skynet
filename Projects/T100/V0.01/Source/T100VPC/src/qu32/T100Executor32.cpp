#include "T100Executor32.h"

#include "T100QU32.h"
#include "T100AllOrders.h"


T100Executor32::T100Executor32(T100QU32* host)
    :m_host(host)
{
    //ctor
}

T100Executor32::~T100Executor32()
{
    //dtor
}

T100BOOL T100Executor32::start()
{
    return T100Thread::start();
}

T100BOOL T100Executor32::stop()
{
    return T100Thread::stop();
}

T100VOID T100Executor32::run()
{
    do{
        execute();

        if(!running())return;

    }while(running());
}

T100VOID T100Executor32::debug()
{

}

T100VOID T100Executor32::execute()
{
    T100BOOL            result;
    T100WORD            value;
    T100WORD_BITS       order;

    value = m_host->getCU32()->step();

    order.WORD = value;

    switch(order.BYTE0.BYTE){
    //
    case T100ORDER_ADD:
        {
            T100OrderAdd add(m_host, this);
            result = add.execute(value);
            break;
        }
    case T100ORDER_SUB:
        {
            T100OrderSub sub(m_host, this);
            result = sub.execute(value);
            break;
        }
    case T100ORDER_MUL:
        {
            T100OrderMul mul(m_host, this);
            result = mul.execute(value);
            break;
        }
    case T100ORDER_DIV:
        {
            T100OrderDiv div(m_host, this);
            result = div.execute(value);
            break;
        }
    //
    case T100ORDER_AND:
        {
            T100OrderAnd AND(m_host, this);
            result = AND.execute(value);
            break;
        }
    case T100ORDER_OR:
        {
            T100OrderOr OR(m_host, this);
            result = OR.execute(value);
            break;
        }
    case T100ORDER_NOT:
        {
            T100OrderNot NOT(m_host, this);
            result = NOT.execute(value);
            break;
        }
    case T100ORDER_XOR:
        {
            T100OrderXor XOR(m_host, this);
            result = XOR.execute(value);
            break;
        }
    //
    case T100ORDER_LOCK:
        {
            T100OrderLock lock(m_host, this);
            result = lock.execute(value);
            break;
        }
    case T100ORDER_UNLOCK:
        {
            T100OrderUnlock unlock(m_host, this);
            result = unlock.execute(value);
            break;
        }
    case T100ORDER_HALT:
        {
            T100OrderHalt halt(m_host, this);
            result = halt.execute(value);
            break;
        }
    //
    case T100ORDER_NOP:
        {
            T100OrderNop nop(m_host, this);
            result = nop.execute(value);
            break;
        }
    case T100ORDER_CMT:
        {
            T100OrderCmt cmt(m_host, this);
            result = cmt.execute(value);
            break;
        }
    case T100ORDER_DBG:
        {
            T100OrderDebug debug(m_host, this);
            result = debug.execute(value);
            break;
        }
    //
    case T100ORDER_CALL:
        {
            T100OrderCall call(m_host, this);
            result = call.execute(value);
            break;
        }
    case T100ORDER_RETURN:
        {
            T100OrderRet ret(m_host, this);
            result = ret.execute(value);
            break;
        }
    case T100ORDER_INT:
        {
            T100OrderInt icall(m_host, this);
            result = icall.execute(value);
            break;
        }
    case T100ORDER_IRET:
        {
            T100OrderIret iret(m_host, this);
            result = iret.execute(value);
            break;
        }
    //
    case T100ORDER_JUMP:
        {
            T100OrderJump jump(m_host, this);
            result = jump.execute(value);
            break;
        }
    case T100ORDER_JZ:
        {
            T100OrderJz jz(m_host, this);
            result = jz.execute(value);
            break;
        }
    case T100ORDER_JNZ:
        {
            T100OrderJnz jnz(m_host, this);
            result = jnz.execute(value);
            break;
        }
    case T100ORDER_LOOP:
        {
            T100OrderLoop loop(m_host, this);
            result = loop.execute(value);
            break;
        }
    //
    case T100ORDER_IN:
        {
            T100OrderIn in(m_host, this);
            result = in.execute(value);
            break;
        }
    case T100ORDER_OUT:
        {
            T100OrderOut out(m_host, this);
            result = out.execute(value);
            break;
        }
    case T100ORDER_MOVE:
        {
            T100OrderMove move(m_host, this);
            result = move.execute(value);
            break;
        }
    //
    default:
        break;
    }

}
