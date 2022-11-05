#include "T100Order.h"
#include "T100BitTypes.h"

namespace T100QU32{

T100Order::T100Order(T100QU32* host, T100Executor32* exec)
    :m_host(host), m_exec(exec)
{
    //ctor
}

T100Order::~T100Order()
{
    //dtor
}

T100QU32* T100Order::getHost()
{
    return m_host;
}

T100Executor32* T100Order::getExecutor()
{
    return m_exec;
}

T100BOOL T100Order::executor(T100WORD value)
{
    T100BOOL        result;

    m_order         = value;
    m_base          = getHost()->getCU32()->getCBR();
    m_offset        = getHost()->getCU32()->getCurrent() - 1;

    result = run();
    log();

    return result;
}

T100BOOL T100Order::load(T100OPERATOR_DOUBLE& target, T100OPERATOR_DOUBLE& source)
{
    T100WORD_BITS       order;

    order.WORD      = m_order;

    switch(order.BYTE1.BYTE){
    case T100OPERATOR_NONE:
        {
            m_type      = T100OPERATOR_NONE;
            return T100FALSE;
        }
        break;
    case T100OPERATOR_ONE_ONE:
        {
            m_type      = T100OPERATOR_ONE_ONE;

            target.TYPE = T_NONE;
            source.TYPE = T_NONE;

            target.BASE.TYPE        = T_NONE;
            target.OPERATOR.TYPE    = order.BYTE2.BYTE;

            source.BASE.TYPE        = T_NONE;
            source.OPERATOR.TYPE    = order.BYTE3.BYTE;
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            m_type      = T100OPERATOR_THREE_THREE;

            target.TYPE = order.BYTE2.BYTE;
            source.TYPE = order.BYTE3.BYTE;

            order.WORD  = getHost()->getCU32()->step();

            target.BASE.TYPE        = order.BYTE0.BYTE;
            target.OPERATOR.TYPE    = order.BYTE1.BYTE;

            source.BASE.TYPE        = order.BYTE2.BYTE;
            source.OPERATOR.TYPE    = order.BYTE3.BYTE;
        }
        break;
    default:
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100Order::loadTarget(T100OPERATOR_DOUBLE& op)
{
    T100BOOL        result          = T100FALSE;

    result = loadOperator(op.BASE);
    if(!result){
        return T100FALSE;
    }
    result = loadOperator(op.OPERATOR);

    return result;
}

T100BOOL T100Order::loadMonoTarget(T100OPERATOR_DOUBLE& op)
{
    T100BOOL            result;
    T100WORD_BITS       order;

    order.WORD      = m_order;
    op.BASE.TYPE    = order.BYTE1.BYTE;

    switch(order.BYTE1.BYTE){
    case T_NONE:
        {

        }
        break;
    case T_IMM:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100TRUE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getCU32()->step();
        }
        break;
    case T_COR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE_FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = op.BASE.OFFSET;
        }
        break;
    case T_CBR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getCU32()->getCBR();
        }
        break;
    case T_CCR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getCU32()->getCCR();
        }
        break;
    case T_AAR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getAAR();
        }
        break;
    case T_ABR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getABR();
        }
        break;
    case T_ACR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getACR();
        }
        break;
    case T_ADR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getADR();
        }
        break;
    case T_MEM:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100TRUE;
            op.BASE.OFFSET      = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_COR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_CBR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCBR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_CCR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCCR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_AAR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getAAR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_ABR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_ACR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost->getAU32()->getACR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_ADR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getADR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_MEM:
        {
            op.USED                     = T100TRUE;
            op.BASE.ADDR_TYPE           = A_IND;
            op.BASE.FLAG                = T100TRUE;
            op.BASE.INTERIM_OFFSET      = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.BASE.INTERIM_OFFSET, op.BASE.OFFSET);
            if(!result){
                return T100FALSE;
            }
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }

    op.OPERATOR.TYPE        = order.BYTE2.BYTE;

    switch(order.BYTE2.BYTE){
    case T_IMM:
        {
            op.OPERATOR.FLAG        = T100TRUE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getCU32()->step();
        }
        break;
    case T_COR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = op.OPERATOR.OFFSET;
        }
        break;
    case T_CBR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getCU32()->getCBR();
        }
        break;
    case T_CCR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getCU32()->getCCR();
        }
        break;

    }

    return result;
}

}
