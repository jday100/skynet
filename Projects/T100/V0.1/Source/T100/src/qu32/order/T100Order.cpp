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

T100BOOL T100Order::execute(T100WORD value)
{
    T100BOOL        result;

    m_order         = value;
    m_base          = getHost()->getCU32()->getCBR();
    m_offset        = getHost()->getCU32()->getCurrent() - 1;

    result = run();
    log();

    return result;
}

T100BOOL T100Order::load(T100Component::T100OPERATOR_DOUBLE& target, T100Component::T100OPERATOR_DOUBLE& source)
{
    T100WORD_BITS       order;

    order.WORD      = m_order;

    switch(order.BYTE1.BYTE){
    case T100Component::T100OPERATOR_NONE:
        {
            m_type      = T100Component::T100OPERATOR_NONE;
            return T100FALSE;
        }
        break;
    case T100Component::T100OPERATOR_ONE_ONE:
        {
            m_type      = T100Component::T100OPERATOR_ONE_ONE;

            target.TYPE = T100Component::T_NONE;
            source.TYPE = T100Component::T_NONE;

            target.BASE.TYPE        = T100Component::T_NONE;
            target.OPERATOR.TYPE    = order.BYTE2.BYTE;

            source.BASE.TYPE        = T100Component::T_NONE;
            source.OPERATOR.TYPE    = order.BYTE3.BYTE;
        }
        break;
    case T100Component::T100OPERATOR_THREE_THREE:
        {
            m_type      = T100Component::T100OPERATOR_THREE_THREE;

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

T100BOOL T100Order::loadTarget(T100Component::T100OPERATOR_DOUBLE& op)
{
    T100BOOL        result          = T100FALSE;

    result = loadOperator(op.BASE);
    if(!result){
        return T100FALSE;
    }
    result = loadOperator(op.OPERATOR);

    return result;
}

T100BOOL T100Order::loadMonoTarget(T100Component::T100OPERATOR_DOUBLE& op)
{
    T100BOOL            result;
    T100WORD_BITS       order;

    order.WORD      = m_order;
    op.BASE.TYPE    = order.BYTE1.BYTE;

    switch(order.BYTE1.BYTE){
    case T100Component::T_NONE:
        {

        }
        break;
    case T100Component::T_IMM:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100TRUE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getCU32()->step();
        }
        break;
    case T100Component::T_COR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = op.BASE.OFFSET;
        }
        break;
    case T100Component::T_CBR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getCU32()->getCBR();
        }
        break;
    case T100Component::T_CCR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getCU32()->getCCR();
        }
        break;
    case T100Component::T_AAR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getAAR();
        }
        break;
    case T100Component::T_ABR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getABR();
        }
        break;
    case T100Component::T_ACR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getACR();
        }
        break;
    case T100Component::T_ADR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_IMM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.BASE.VALUE       = getHost()->getAU32()->getADR();
        }
        break;
    case T100Component::T_MEM:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100TRUE;
            op.BASE.OFFSET      = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_COR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_CBR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCBR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_CCR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCCR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_AAR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getAAR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_ABR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_ACR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getACR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_ADR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = T100Component::A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getADR();
            result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case T100Component::I_MEM:
        {
            op.USED                     = T100TRUE;
            op.BASE.ADDR_TYPE           = T100Component::A_IND;
            op.BASE.FLAG                = T100TRUE;
            op.BASE.INTERIM_OFFSET      = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.BASE.INTERIM_OFFSET, op.BASE.OFFSET);
            if(result){
                result = getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
            }
        }
        break;
    default:
        return T100FALSE;
    }

    op.OPERATOR.TYPE        = order.BYTE2.BYTE;

    switch(order.BYTE2.BYTE){
    case T100Component::T_IMM:
        {
            op.OPERATOR.FLAG        = T100TRUE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getCU32()->step();
        }
        break;
    case T100Component::T_COR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = op.OPERATOR.OFFSET;
        }
        break;
    case T100Component::T_CBR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getCU32()->getCBR();
        }
        break;
    case T100Component::T_CCR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getCU32()->getCCR();
        }
        break;
    case T100Component::T_AAR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getAAR();
        }
        break;
    case T100Component::T_ABR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getABR();
        }
        break;
    case T100Component::T_ACR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getACR();
        }
        break;
    case T100Component::T_ADR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getADR();
        }
        break;
    case T100Component::T_MEM:
        {
            op.OPERATOR.FLAG        = T100TRUE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_COR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_CBR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_CCR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCCR();
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_AAR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getAAR();
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_ABR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_ACR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_ADR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = T100Component::A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getADR();
            result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case T100Component::I_MEM:
        {
            op.OPERATOR.FLAG                = T100TRUE;
            op.OPERATOR.ADDR_TYPE           = T100Component::A_IND;
            op.OPERATOR.INTERIM_OFFSET      = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.OPERATOR.INTERIM_OFFSET, op.OPERATOR.OFFSET);
            if(result){
                result = getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100Order::loadSource(T100Component::T100OPERATOR_DOUBLE& op)
{
    T100BOOL        result          = T100FALSE;

    result = loadOperator(op.BASE);
    if(!result){
        return T100FALSE;
    }

    result = loadOperator(op.OPERATOR);

    return result;
}

T100BOOL T100Order::loadOperator(T100Component::T100OPERATOR_SINGLE& op)
{
    T100BOOL        result          = T100TRUE;

    op.USED = T100FALSE;

    switch(op.TYPE){
    case T100Component::T_NONE:
        {

        }
        break;
    case T100Component::T_COR:
    case T100Component::T_CBR:
    case T100Component::T_CCR:
    case T100Component::T_SSR:
    case T100Component::T_SPR:
    case T100Component::T_AAR:
    case T100Component::T_ABR:
    case T100Component::T_ACR:
    case T100Component::T_ADR:
    case T100Component::T_ACF:
    case T100Component::T_AMF:
    case T100Component::T_AOF:
    case T100Component::I_COR:
    case T100Component::I_CBR:
    case T100Component::I_CCR:
    case T100Component::I_AAR:
    case T100Component::I_ABR:
    case T100Component::I_ACR:
    case T100Component::I_ADR:
        {
            op.USED     = T100TRUE;
            result      = loadRegister(op);
        }
        break;
    case T100Component::T_IMM:
    case T100Component::T_MEM:
    case T100Component::T_ARR:
    case T100Component::I_MEM:
    case T100Component::I_ARR:
    //
    case T100Component::ST_IMM:
    case T100Component::ST_MEM:
    case T100Component::ST_ARR:
    case T100Component::SI_MEM:
    case T100Component::SI_ARR:
        {
            op.USED     = T100TRUE;
            result      = loadMemory(op);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100Order::getSource(T100Component::T100OPERATOR_DOUBLE& op, T100WORD& value)
{
    T100BOOL        result          = T100TRUE;

    switch(m_type){
    case T100Component::T100OPERATOR_NONE:
        {
            result = T100FALSE;
        }
        break;
    case T100Component::T100OPERATOR_ONE_ONE:
        {
            value = op.OPERATOR.VALUE;
        }
        break;
    case T100Component::T100OPERATOR_THREE_THREE:
        {
            result = getComplexusSource(op, value);
        }
        break;
    default:
        result = T100FALSE;
    }

    op.VALUE = value;
    return result;
}

T100BOOL T100Order::getComplexusSource(T100Component::T100OPERATOR_DOUBLE& op, T100WORD& value)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;
    T100WORD        interim;

    if(op.BASE.USED){
        switch(op.TYPE){
        case T100Component::T_NONE:
            {
                offset  = op.BASE.VALUE + op.OPERATOR.VALUE;
                result  = getHost()->getMemory32()->raw_read(0, offset, value);
            }
            break;
        case T100Component::T_IMM:
            {
                value = op.BASE.VALUE + op.OPERATOR.VALUE;
            }
            break;
        case T100Component::I_MEM:
            {
                offset  = op.BASE.VALUE + op.OPERATOR.VALUE;
                result  = getHost()->getMemory32()->raw_read(0, offset, interim);
                if(result){
                    result  = getHost()->getMemory32()->raw_read(0, interim, value);
                }
            }
            break;
        default:
            result = T100FALSE;
        }
    }else{
        value = op.OPERATOR.VALUE;
    }

    return result;
}

T100BOOL T100Order::getIOSource(T100Component::T100OPERATOR_DOUBLE& op, T100WORD& value)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;

    switch(m_type){
    case T100Component::T100OPERATOR_NONE:
        {
            result = T100FALSE;
        }
        break;
    case T100Component::T100OPERATOR_ONE_ONE:
        {
            offset  = op.OPERATOR.VALUE;
            result  = getHost()->getPort32()->in(offset, value);
        }
        break;
    case T100Component::T100OPERATOR_THREE_THREE:
        {
            result  = getComplexusSource(op, offset);
            if(result){
                result = getHost()->getPort32()->in(offset, value);
            }
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Order::setTarget(T100Component::T100OPERATOR_DOUBLE& op, T100WORD value)
{
    T100BOOL        result          = T100TRUE;

    switch(op.TYPE){
    case T100Component::T_NONE:
        {
            if(op.BASE.USED){
                result = getHost()->getMemory32()->raw_write(op.BASE.VALUE, op.OPERATOR.VALUE, value);
            }else{
                result = setOperator(op.OPERATOR, value);
            }
        }
        break;
    case T100Component::T_IMM:
        {
            return T100FALSE;
        }
        break;
    case T100Component::I_MEM:
        {
            if(op.BASE.USED){
                T100WORD        offset;
                result = getHost()->getMemory32()->raw_read(op.BASE.VALUE, op.OPERATOR.VALUE, offset);
                if(result){
                    result = getHost()->getMemory32()->raw_write(0, offset, value);
                }
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Order::setIOTarget(T100Component::T100OPERATOR_DOUBLE& op, T100WORD value)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;

    switch(op.TYPE){
    case T100Component::T_NONE:
        {
            if(op.USED){
                offset  = op.BASE.VALUE + op.OPERATOR.VALUE;
            }else{
                offset  = op.OPERATOR.VALUE;
            }
            result = getHost()->getPort32()->out(offset, value);
        }
        break;
    case T100Component::T_IMM:
        {
            return T100FALSE;
        }
        break;
    case T100Component::I_MEM:
        {
            if(op.USED){
                result = getHost()->getMemory32()->raw_read(op.BASE.VALUE, op.OPERATOR.VALUE, offset);
                if(result){
                    result = getHost()->getMemory32()->raw_read(0, offset, value);
                }
            }else{
                /*
                //Test
                return T100FALSE;
                */
                result = getHost()->getMemory32()->read(op.OPERATOR.VALUE, offset);
            }
            if(result){
                result = getHost()->getPort32()->out(offset, value);
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Order::setOperator(T100Component::T100OPERATOR_SINGLE& op, T100WORD value)
{
    T100BOOL        result          = T100TRUE;

    switch(op.TYPE){
    case T100Component::T_NONE:
        {
            return T100FALSE;
        }
        break;
    case T100Component::T_COR:
    case T100Component::T_CBR:
    case T100Component::T_CCR:
    case T100Component::T_SSR:
    case T100Component::T_SPR:
    case T100Component::T_AAR:
    case T100Component::T_ABR:
    case T100Component::T_ACR:
    case T100Component::T_ADR:
    case T100Component::T_ACF:
    case T100Component::T_AMF:
    case T100Component::T_AOF:
    case T100Component::I_COR:
    case T100Component::I_CBR:
    case T100Component::I_CCR:
    case T100Component::I_AAR:
    case T100Component::I_ABR:
    case T100Component::I_ACR:
    case T100Component::I_ADR:
        {
            result  = setRegister(op, value);
        }
        break;
    case T100Component::T_IMM:
    case T100Component::T_MEM:
    case T100Component::T_ARR:
    case T100Component::I_MEM:
    case T100Component::I_ARR:
    //
    case T100Component::ST_IMM:
    case T100Component::ST_MEM:
    case T100Component::ST_ARR:
    case T100Component::SI_MEM:
    case T100Component::SI_ARR:
        {
            result  = setMemory(op, value);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100Order::setRegister(T100Component::T100OPERATOR_SINGLE& op, T100WORD value)
{
    T100BOOL        result          = T100TRUE;

    switch(op.TYPE){
    case T100Component::T_COR:
        {
            getHost()->getCU32()->setCOR(value);
        }
        break;
    case T100Component::T_CBR:
        {
            getHost()->getCU32()->setCBR(value);
        }
        break;
    case T100Component::T_CCR:
        {
            getHost()->getCU32()->setCCR(value);
        }
        break;
    case T100Component::T_SSR:
        {
            getHost()->getCU32()->setSSR(value);
        }
        break;
    case T100Component::T_SPR:
        {
            getHost()->getCU32()->setSPR(value);
        }
        break;
    case T100Component::T_AAR:
        {
            getHost()->getAU32()->setAAR(value);
        }
        break;
    case T100Component::T_ABR:
        {
            getHost()->getAU32()->setABR(value);
        }
        break;
    case T100Component::T_ACR:
        {
            getHost()->getAU32()->setACR(value);
        }
        break;
    case T100Component::T_ADR:
        {
            getHost()->getAU32()->setADR(value);
        }
        break;
    case T100Component::T_ACF:
        {
            getHost()->getAU32()->setACF(value);
        }
        break;
    case T100Component::T_AMF:
        {
            getHost()->getAU32()->setAMF(value);
        }
        break;
    case T100Component::T_AOF:
        {
            getHost()->getAU32()->setAOF(value);
        }
        break;
    case T100Component::I_COR:
    case T100Component::I_CBR:
    case T100Component::I_CCR:
    case T100Component::I_AAR:
    case T100Component::I_ABR:
    case T100Component::I_ACR:
    case T100Component::I_ADR:
        {
            result = getHost()->getMemory32()->write(op.VALUE, op.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100Order::setMemory(T100Component::T100OPERATOR_SINGLE& op, T100WORD value)
{
    T100BOOL        result          = T100TRUE;

    switch(op.TYPE){
    case T100Component::T_MEM:
        {
            result = getHost()->getMemory32()->write(op.OFFSET, value);
        }
        break;
    case T100Component::T_ARR:
        {
            result = getHost()->getMemory32()->write(op.OFFSET + op.INDEX, value);
        }
        break;
    case T100Component::I_MEM:
        {
            result = getHost()->getMemory32()->write(op.OFFSET, value);
        }
        break;
    case T100Component::I_ARR:
        {
            T100WORD        offset;

            result = getHost()->getMemory32()->read(op.OFFSET + op.INDEX, offset);
            if(result){
                result = getHost()->getMemory32()->write(offset, value);
            }
        }
        break;
    case T100Component::ST_IMM:
        {
            return T100FALSE;
        }
        break;
    case T100Component::ST_MEM:
        {
            result = getHost()->getMemory32()->raw_write(0, op.OFFSET, value);
        }
        break;
    case T100Component::ST_ARR:
        {
            result = getHost()->getMemory32()->raw_write(0, op.OFFSET + op.INDEX, value);
        }
        break;
    case T100Component::SI_MEM:
        {
            result = getHost()->getMemory32()->raw_write(0, op.OFFSET, value);
        }
        break;
    case T100Component::SI_ARR:
        {
            T100WORD        offset;

            result = getHost()->getMemory32()->raw_read(0, op.OFFSET + op.INDEX, offset);
            if(result){
                result = getHost()->getMemory32()->raw_write(0, offset, value);
            }
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100Order::parse(T100Component::T100OPERATOR_DOUBLE& target, T100Component::T100OPERATOR_DOUBLE& source)
{
    T100BOOL        result          = T100TRUE;

    result = load(target, source);
    if(!result){
        return T100FALSE;
    }

    result = loadTarget(target);
    if(!result){
        return T100FALSE;
    }

    result = loadSource(source);
    if(!result){
        return T100FALSE;
    }

    T100WORD        value;

    result = getSource(source, value);
    if(!result){
        return T100FALSE;
    }

    result = setTarget(target, value);

    return result;
}

T100BOOL T100Order::loadRegister(T100Component::T100OPERATOR_SINGLE& op)
{
    T100BOOL        result          = T100TRUE;

    op.FLAG         = T100FALSE;
    op.OFFSET       = getHost()->getCU32()->getCurrent() - 1;

    switch(op.TYPE){
    case T100Component::T_COR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = op.OFFSET;
        }
        break;
    case T100Component::T_CBR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getCU32()->getCBR();
        }
        break;
    case T100Component::T_SSR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getCU32()->getSSR();
        }
        break;
    case T100Component::T_SPR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getCU32()->getSPR();
        }
        break;
    case T100Component::T_CCR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getCU32()->getCCR();
        }
        break;
    case T100Component::T_AAR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getAAR();
        }
        break;
    case T100Component::T_ABR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getABR();
        }
        break;
    case T100Component::T_ACR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getACR();
        }
        break;
    case T100Component::T_ADR:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getADR();
        }
        break;
    case T100Component::T_ACF:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getACF();
        }
        break;
    case T100Component::T_AMF:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getAMF();
        }
        break;
    case T100Component::T_AOF:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getAU32()->getAOF();
        }
        break;
    case T100Component::I_COR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = op.OFFSET;
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case T100Component::I_CBR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getCU32()->getCBR();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case T100Component::I_CCR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getCU32()->getCCR();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case T100Component::I_AAR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getAAR();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case T100Component::I_ABR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case T100Component::I_ACR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getACR();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case T100Component::I_ADR:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getADR();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    /*
    case T100Component::I_ACF:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getACF();
            op.VALUE            = getHost()->getMemory32()->read(op.INTERIM_OFFSET);
        }
        break;
    case T100Component::I_AMF:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getAMF();
            op.VALUE            = getHost()->getMemory32()->read(op.INTERIM_OFFSET);
        }
        break;
    case T100Component::I_AOF:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getAOF();
            op.VALUE            = getHost()->getMemory32()->read(op.INTERIM_OFFSET);
        }
        break;
    */
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100Order::loadMemory(T100Component::T100OPERATOR_SINGLE& op)
{
    T100BOOL        result          = T100TRUE;

    op.FLAG         = T100TRUE;
    op.OFFSET       = getHost()->getCU32()->getCurrent() - 1;

    switch(op.TYPE){
    case T100Component::T_IMM:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getCU32()->step();
        }
        break;
    case T100Component::T_MEM:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.OFFSET, op.VALUE);
        }
        break;
    case T100Component::T_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.OFFSET + op.INDEX, op.VALUE);
        }
        break;
    case T100Component::I_MEM:
        {
            op.ADDR_TYPE        = T100Component::A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.OFFSET);
            if(result){
                result = getHost()->getMemory32()->read(op.OFFSET, op.VALUE);
            }
        }
        break;
    case T100Component::I_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = T100Component::A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(op.INTERIM_OFFSET + op.INDEX, op.OFFSET);
            if(result){
                result = getHost()->getMemory32()->read(op.OFFSET, op.VALUE);
            }
        }
        break;
    case T100Component::ST_IMM:
        {
            op.ADDR_TYPE        = T100Component::A_IMM;
            op.VALUE            = getHost()->getCU32()->step();
        }
        break;
    case T100Component::ST_MEM:
        {
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->raw_read(0, op.OFFSET, op.VALUE);
        }
        break;
    case T100Component::ST_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = T100Component::A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->raw_read(0, op.OFFSET + op.INDEX, op.VALUE);
        }
        break;
    case T100Component::SI_MEM:
        {
            op.ADDR_TYPE        = T100Component::A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->raw_read(0, op.INTERIM_OFFSET, op.OFFSET);
            if(result){
                result = getHost()->getMemory32()->raw_read(0, op.OFFSET, op.VALUE);
            }
        }
        break;
    case T100Component::SI_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = T100Component::A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->raw_read(0, op.INTERIM_OFFSET + op.INDEX, op.OFFSET);
            if(result){
                result = getHost()->getMemory32()->raw_read(0, op.OFFSET, op.VALUE);
            }
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

}
