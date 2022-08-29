#include "T100Executor32.h"
#include "T100HintQU32.h"
#include "T100QU32.h"
#include "T100AllOrders.h"
#include "T100QU32Callback.h"


T100Executor32::T100Executor32(T100QU32* host)
    :IExecutor(host), m_host(host),
    m_running(T100FALSE)
{
    //ctor
}

T100Executor32::~T100Executor32()
{
    //dtor
}

T100VOID T100Executor32::start()
{
    if(m_running)return;

    m_running   = T100TRUE;

    m_thread    = new std::thread(&T100Executor32::run, this);
}

T100VOID T100Executor32::stop()
{
    if(!m_running)return;

    m_running   = T100FALSE;

    if(m_thread){
        m_condition.notify_all();

        m_thread->join();

        T100QU32Callback::callStop();
    }
}

T100VOID T100Executor32::done()
{
    if(!m_running)return;

    m_running   = T100FALSE;

    if(m_thread){
        m_condition.notify_all();

        T100QU32Callback::callDone();
    }
}

T100VOID T100Executor32::debug()
{
    switch(m_mode){
    case EXECUTOR_MODE_STEP:
        {
            pause();
            T100QU32Callback::callDebug();
        }
        break;
    case EXECUTOR_MODE_NEXT:
        {
            pause();
            T100QU32Callback::callDebug();
        }
        break;
    case EXECUTOR_MODE_RUN:
        {

        }
        break;
    }
}

T100VOID T100Executor32::pause()
{
    if(m_thread){
        m_state     = EXECUTOR_STATE_PAUSE;
        T100QU32Callback::callHangup();
    }
}

T100VOID T100Executor32::step()
{
    if(m_thread){
        m_state     = EXECUTOR_STATE_PAUSE;
        m_mode      = EXECUTOR_MODE_STEP;
        m_condition.notify_all();

        T100QU32Callback::callStep();
    }
}

T100VOID T100Executor32::next()
{
    if(m_thread){
        m_state     = EXECUTOR_STATE_RUN;
        m_mode      = EXECUTOR_MODE_NEXT;
        m_condition.notify_all();

        T100QU32Callback::callStep();
    }
}

T100VOID T100Executor32::resume()
{
    if(m_thread){
        m_state     = EXECUTOR_STATE_RUN;
        m_mode      = EXECUTOR_MODE_RUN;

        m_condition.notify_all();

        T100QU32Callback::callAwaken();
    }
}

T100VOID T100Executor32::wait()
{
    if(m_thread){
        m_thread->join();
    }
}

T100VOID T100Executor32::run()
{
    do{
        execute();

        if(!m_running)return;

        if(EXECUTOR_STATE_PAUSE == m_state){
            std::unique_lock<std::mutex> locker(m_mutex);

            m_condition.wait(locker);
            locker.unlock();
        }

        m_running   = T100TRUE;

        T100Log::info("running...");

    }while(m_running);

}

T100VOID T100Executor32::run_step()
{
    do{
        execute();

        if(!m_running)return;

        T100QU32Callback::callStep();

        std::unique_lock<std::mutex> locker(m_mutex);

        m_condition.wait(locker);
        locker.unlock();

        m_running   = T100TRUE;

        T100Log::info("running...");

    }while(m_running);
}

T100VOID T100Executor32::run_next()
{
    do{
        execute();

        if(!m_running)return;

        T100Log::info("running...");

    }while(m_running);
}

T100VOID T100Executor32::run_run()
{
    do{
        execute();

        if(!m_running)return;

        m_running   = T100TRUE;

        T100Log::info("running...");

    }while(m_running);
}

T100VOID T100Executor32::execute()
{
    T100Log::info("test...");
    if(!m_host->getCU32())return;

    T100WORD value = m_host->getCU32()->step();
    T100Log::info(T100HintQU32::order_hint(value, T100VPC_ORDER_EXECUTE));

    T100BOOL        result;
    T100WORD_BITS   order;

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
        done();
    };

    if(!result){
        done();
    }
}

T100VOID T100Executor32::execute_none()
{
    if(!m_host->getCU32())return;

    T100WORD        value;
    T100BOOL        result;
    T100WORD_BITS   order;

    value       = m_host->getCU32()->step();
    order.WORD  = value;

    switch(order.BYTE0.BYTE){
    //
    case T100ORDER_ADD:
        {
            T100OrderAdd add(m_host, this);
            result = add.execute_none(value);
            break;
        }
    case T100ORDER_SUB:
        {
            T100OrderSub sub(m_host, this);
            result = sub.execute_none(value);
            break;
        }
    case T100ORDER_MUL:
        {
            T100OrderMul mul(m_host, this);
            result = mul.execute_none(value);
            break;
        }
    case T100ORDER_DIV:
        {
            T100OrderDiv div(m_host, this);
            result = div.execute_none(value);
            break;
        }
    //
    case T100ORDER_AND:
        {
            T100OrderAnd AND(m_host, this);
            result = AND.execute_none(value);
            break;
        }
    case T100ORDER_OR:
        {
            T100OrderOr OR(m_host, this);
            result = OR.execute_none(value);
            break;
        }
    case T100ORDER_NOT:
        {
            T100OrderNot NOT(m_host, this);
            result = NOT.execute_none(value);
            break;
        }
    case T100ORDER_XOR:
        {
            T100OrderXor XOR(m_host, this);
            result = XOR.execute_none(value);
            break;
        }
    //
    case T100ORDER_LOCK:
        {
            T100OrderLock lock(m_host, this);
            result = lock.execute_none(value);
            break;
        }
    case T100ORDER_UNLOCK:
        {
            T100OrderUnlock unlock(m_host, this);
            result = unlock.execute_none(value);
            break;
        }
    case T100ORDER_HALT:
        {
            T100OrderHalt halt(m_host, this);
            result = halt.execute_none(value);
            break;
        }
    //
    case T100ORDER_NOP:
        {
            T100OrderNop nop(m_host, this);
            result = nop.execute_none(value);
            break;
        }
    case T100ORDER_CMT:
        {
            T100OrderCmt cmt(m_host, this);
            result = cmt.execute_none(value);
            break;
        }
    case T100ORDER_DBG:
        {
            T100OrderDebug debug(m_host, this);
            result = debug.execute_none(value);
            break;
        }
    //
    case T100ORDER_CALL:
        {
            T100OrderCall call(m_host, this);
            result = call.execute_none(value);
            break;
        }
    case T100ORDER_RETURN:
        {
            T100OrderRet ret(m_host, this);
            result = ret.execute_none(value);
            break;
        }
    case T100ORDER_INT:
        {
            T100OrderInt icall(m_host, this);
            result = icall.execute_none(value);
            break;
        }
    case T100ORDER_IRET:
        {
            T100OrderIret iret(m_host, this);
            result = iret.execute_none(value);
            break;
        }
    //
    case T100ORDER_JUMP:
        {
            T100OrderJump jump(m_host, this);
            result = jump.execute_none(value);
            break;
        }
    case T100ORDER_JZ:
        {
            T100OrderJz jz(m_host, this);
            result = jz.execute_none(value);
            break;
        }
    case T100ORDER_JNZ:
        {
            T100OrderJnz jnz(m_host, this);
            result = jnz.execute_none(value);
            break;
        }
    case T100ORDER_LOOP:
        {
            T100OrderLoop loop(m_host, this);
            result = loop.execute_none(value);
            break;
        }
    //
    case T100ORDER_IN:
        {
            T100OrderIn in(m_host, this);
            result = in.execute_none(value);
            break;
        }
    case T100ORDER_OUT:
        {
            T100OrderOut out(m_host, this);
            result = out.execute_none(value);
            break;
        }
    case T100ORDER_MOVE:
        {
            T100OrderMove move(m_host, this);
            result = move.execute_none(value);
            break;
        }
    //
    default:
        done();
    };

    if(!result){
        done();
    }
}


