#include "T100Order.h"

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
    T100BOOL            result;

    m_order             = value;
    m_base              = getHost()->getCU32()->getCBR();
    m_offset            = getHost()->getCU32()->getCurrent() - 1;

    result = run();
    log();

    return result;
}

T100BOOL T100Order::load(T100OPERATOR_DOUBLE& target, T100OPERATOR_DOUBLE& source)
{
    T100WORD_BITS   order;

    order.WORD      = m_order;

    switch(order.BYTE1.BYTE){
    case T100OPERATOR_NONE:
        {
            m_type = T100OPERATOR_NONE;
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
    T100BOOL    result      = T100FALSE;

    result = loadOperator(op.BASE);
    if(!result){
        return T100FALSE;
    }

    result = loadOperator(op.OPERATOR);

    return result;
}

T100BOOL T100Order::loadMonoTarget(T100OPERATOR_DOUBLE& op)
{
    T100WORD_BITS   order;

    order.WORD      = m_order;
    op.BASE.TYPE    = order.BYTE1.BYTE;

    switch(order.BYTE1.BYTE)
    {
    case T_NONE:
        {
            //op.USED     = T100FALSE;
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
            op.BASE.FLAG        = T100FALSE;
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
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_COR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_CBR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCBR();
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_CCR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getCU32()->getCCR();
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_AAR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getAAR();
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_ABR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getABR();
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_ACR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getACR();
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_ADR:
        {
            op.USED             = T100TRUE;
            op.BASE.ADDR_TYPE   = A_MEM;
            op.BASE.FLAG        = T100FALSE;
            op.BASE.OFFSET      = getHost()->getAU32()->getADR();
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    case I_MEM:
        {
            op.USED                     = T100TRUE;
            op.BASE.ADDR_TYPE           = A_IND;
            op.BASE.FLAG                = T100TRUE;
            op.BASE.INTERIM_OFFSET      = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.BASE.INTERIM_OFFSET, op.BASE.OFFSET);
            getHost()->getMemory32()->read(op.BASE.OFFSET, op.BASE.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }

    op.OPERATOR.TYPE        = order.BYTE2.BYTE;

    switch(order.BYTE2.BYTE)
    {
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
    case T_AAR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getAAR();
        }
        break;
    case T_ABR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getABR();
        }
        break;
    case T_ACR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getACR();
        }
        break;
    case T_ADR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_IMM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            op.OPERATOR.VALUE       = getHost()->getAU32()->getADR();
        }
        break;
    case T_MEM:
        {
            op.OPERATOR.FLAG        = T100TRUE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_COR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCurrent() - 1;
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_CBR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCBR();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_CCR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getCU32()->getCCR();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_AAR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getAAR();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_ABR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getABR();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_ACR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getACR();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_ADR:
        {
            op.OPERATOR.FLAG        = T100FALSE;
            op.OPERATOR.ADDR_TYPE   = A_MEM;
            op.OPERATOR.OFFSET      = getHost()->getAU32()->getADR();
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    case I_MEM:
        {
            op.OPERATOR.FLAG                = T100TRUE;
            op.OPERATOR.ADDR_TYPE           = A_IND;
            op.OPERATOR.INTERIM_OFFSET      = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.OPERATOR.INTERIM_OFFSET, op.OPERATOR.OFFSET);
            getHost()->getMemory32()->read(op.OPERATOR.OFFSET, op.OPERATOR.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100Order::loadSource(T100OPERATOR_DOUBLE& op)
{
    T100BOOL    result      = T100FALSE;

    result = loadOperator(op.BASE);
    if(!result){
        return T100FALSE;
    }

    result = loadOperator(op.OPERATOR);

    return result;
}

T100BOOL T100Order::loadOperator(T100OPERATOR_SINGLE& op)
{
    T100BOOL    result      = T100TRUE;

    op.USED = T100FALSE;

    switch(op.TYPE){
    case T_NONE:
        {
        }
        break;
    case T_COR:
    case T_CBR:
    case T_CCR:
    case T_AAR:
    case T_ABR:
    case T_ACR:
    case T_ADR:
    case T_ACF:
    case T_AMF:
    case T_AOF:
    case I_COR:
    case I_CBR:
    case I_CCR:
    case I_AAR:
    case I_ABR:
    case I_ACR:
    case I_ADR:
        {
            op.USED     = T100TRUE;
            result      = loadRegister(op);
        }
        break;
    case T_IMM:
    case T_MEM:
    case T_ARR:
    case I_MEM:
    case I_ARR:
    //
    case ST_IMM:
    case ST_MEM:
    case ST_ARR:
    case SI_MEM:
    case SI_ARR:
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

T100BOOL T100Order::getSource(T100OPERATOR_DOUBLE& op, T100WORD& value)
{
    T100BOOL    result      = T100TRUE;

    switch(m_type){
    case T100OPERATOR_NONE:
        {
            result = T100FALSE;
        }
        break;
    case T100OPERATOR_ONE_ONE:
        {
            value = op.OPERATOR.VALUE;
        }
        break;
    case T100OPERATOR_THREE_THREE:
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

T100BOOL T100Order::getComplexusSource(T100OPERATOR_DOUBLE& op, T100WORD& value)
{
    T100BOOL    result      = T100TRUE;
    T100WORD    offset;
    T100WORD    interim;

    if(op.BASE.USED){
        switch(op.TYPE){
        case T_NONE:
            {
                offset  = op.BASE.VALUE + op.OPERATOR.VALUE;
                value   = getHost()->getMemory32()->read(0, offset);
            }
            break;
        case T_IMM:
            {
                value = op.BASE.VALUE + op.OPERATOR.VALUE;
            }
            break;
        case I_MEM:
            {
                offset  = op.BASE.VALUE + op.OPERATOR.VALUE;
                interim = getHost()->getMemory32()->read(0, offset);
                value   = getHost()->getMemory32()->read(0, interim);

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

T100BOOL T100Order::getIOSource(T100OPERATOR_DOUBLE& op, T100WORD& value)
{
    T100BOOL    result      = T100TRUE;
    T100WORD    offset;

    switch(m_type){
    case T100OPERATOR_NONE:
        {
            result = T100FALSE;
        }
        break;
    case T100OPERATOR_ONE_ONE:
        {
            offset  = op.OPERATOR.VALUE;
            getHost()->getPort32()->in(offset, value);
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            result = getComplexusSource(op, offset);
            if(result){
                getHost()->getPort32()->in(offset, value);
            }
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Order::setTarget(T100OPERATOR_DOUBLE& op, T100WORD value)
{
    T100BOOL    result      = T100TRUE;

    switch(op.TYPE){
    case T_NONE:
        {
            if(op.BASE.USED){
                getHost()->getMemory32()->raw_write(op.BASE.VALUE, op.OPERATOR.VALUE, value);
            }else{
                result = setOperator(op.OPERATOR, value);
            }
        }
        break;
    case T_IMM:
        {
            return T100FALSE;
        }
        break;
    case I_MEM:
        {
            if(op.BASE.USED){
                T100WORD offset;
                getHost()->getMemory32()->raw_read(op.BASE.VALUE, op.OPERATOR.VALUE, offset);
                getHost()->getMemory32()->raw_write(0, offset, value);
            }else{
                return T100FALSE;
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Order::setIOTarget(T100OPERATOR_DOUBLE& op, T100WORD value)
{
    T100BOOL    result      = T100TRUE;
    T100WORD    offset;

    switch(op.TYPE){
    case T_NONE:
        {
            if(op.USED){
                offset = op.BASE.VALUE + op.OPERATOR.VALUE;
            }else{
                offset = op.OPERATOR.VALUE;
            }

            getHost()->getPort32()->out(offset, value);
        }
        break;
    case T_IMM:
        {
            return T100FALSE;
        }
        break;
    case I_MEM:
        {
            if(op.USED){
                offset = getHost()->getMemory32()->read(op.BASE.VALUE, op.OPERATOR.VALUE);
                offset = getHost()->getMemory32()->read(0, offset);
            }else{
                return T100FALSE;
            }

            getHost()->getPort32()->out(offset, value);
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Order::setOperator(T100OPERATOR_SINGLE& op, T100WORD value)
{
    T100BOOL    result      = T100TRUE;

    switch(op.TYPE){
    case T_NONE:
        {
            return T100FALSE;
        }
        break;
    case T_COR:
    case T_CBR:
    case T_CCR:
    case T_AAR:
    case T_ABR:
    case T_ACR:
    case T_ADR:
    case T_ACF:
    case T_AMF:
    case T_AOF:
    case I_COR:
    case I_CBR:
    case I_CCR:
    case I_AAR:
    case I_ABR:
    case I_ACR:
    case I_ADR:
        {
            result      = setRegister(op, value);
        }
        break;
    case T_IMM:
    case T_MEM:
    case T_ARR:
    case I_MEM:
    case I_ARR:
    //
    case ST_IMM:
    case ST_MEM:
    case ST_ARR:
    case SI_MEM:
    case SI_ARR:
        {
            result      = setMemory(op, value);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}


T100BOOL T100Order::setRegister(T100OPERATOR_SINGLE& op, T100WORD value)
{
    T100BOOL    result      = T100TRUE;

    switch(op.TYPE){
    case T_COR:
        {
            getHost()->getCU32()->setCOR(value);
        }
        break;
    case T_CBR:
        {
            getHost()->getCU32()->setCBR(value);
        }
        break;
    case T_CCR:
        {
            getHost()->getCU32()->setCCR(value);
        }
        break;
    case T_AAR:
        {
            getHost()->getAU32()->setAAR(value);
        }
        break;
    case T_ABR:
        {
            getHost()->getAU32()->setABR(value);
        }
        break;
    case T_ACR:
        {
            getHost()->getAU32()->setACR(value);
        }
        break;
    case T_ADR:
        {
            getHost()->getAU32()->setADR(value);
        }
        break;
    case T_ACF:
        {
            getHost()->getAU32()->setACF(value);
        }
        break;
    case T_AMF:
        {
            getHost()->getAU32()->setAMF(value);
        }
        break;
    case T_AOF:
        {
            getHost()->getAU32()->setAOF(value);
        }
        break;
    case I_COR:
    case I_CBR:
    case I_CCR:
    case I_AAR:
    case I_ABR:
    case I_ACR:
    case I_ADR:
        {
            getHost()->getMemory32()->write(op.VALUE, op.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100Order::setMemory(T100OPERATOR_SINGLE& op, T100WORD value)
{
    switch(op.TYPE){
    case T_MEM:
        {
            getHost()->getMemory32()->write(op.OFFSET, value);
        }
        break;
    case T_ARR:
        {
            getHost()->getMemory32()->write(op.OFFSET + op.INDEX, value);
        }
        break;
    case I_MEM:
        {
            getHost()->getMemory32()->write(op.OFFSET, value);
        }
        break;
    case I_ARR:
        {
            T100WORD    offset;

            getHost()->getMemory32()->read(op.OFFSET + op.INDEX, offset);
            getHost()->getMemory32()->write(offset, value);
        }
        break;
    case ST_IMM:
        {
            return T100FALSE;
        }
        break;
    case ST_MEM:
        {
            getHost()->getMemory32()->raw_write(0, op.OFFSET, value);
        }
        break;
    case ST_ARR:
        {
            getHost()->getMemory32()->raw_write(0, op.OFFSET + op.INDEX, value);
        }
        break;
    case SI_MEM:
        {
            getHost()->getMemory32()->raw_write(0, op.OFFSET, value);
        }
        break;
    case SI_ARR:
        {
            T100WORD    offset;

            getHost()->getMemory32()->raw_read(0, op.OFFSET + op.INDEX, offset);
            getHost()->getMemory32()->raw_write(0, offset, value);
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100Order::parse(T100OPERATOR_DOUBLE& target, T100OPERATOR_DOUBLE& source)
{
    T100BOOL    result      = T100TRUE;

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

    T100WORD    value;

    result = getSource(source, value);
    if(!result){
        return T100FALSE;
    }

    result = setTarget(target, value);

    return result;
}

T100BOOL T100Order::loadRegister(T100OPERATOR_SINGLE& op)
{
    op.FLAG             = T100FALSE;
    op.OFFSET           = getHost()->getCU32()->getCurrent() - 1;

    switch(op.TYPE){
    case T_COR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = op.OFFSET;
        }
        break;
    case T_CBR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getCU32()->getCBR();
        }
        break;
    case T_CCR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getCU32()->getCCR();
        }
        break;
    case T_AAR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getAAR();
        }
        break;
    case T_ABR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getABR();
        }
        break;
    case T_ACR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getACR();
        }
        break;
    case T_ADR:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getADR();
        }
        break;
    case T_ACF:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getACF();
        }
        break;
    case T_AMF:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getAMF();
        }
        break;
    case T_AOF:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getAU32()->getAOF();
        }
        break;
    case I_COR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = op.OFFSET;
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case I_CBR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getCU32()->getCBR();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case I_CCR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getCU32()->getCCR();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case I_AAR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getAAR();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case I_ABR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getABR();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case I_ACR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getACR();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    case I_ADR:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getADR();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.VALUE);
        }
        break;
    /*
    case I_ACF:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getACF();
            op.VALUE            = getHost()->getMemory32()->read(op.INTERIM_OFFSET);
        }
        break;
    case I_AMF:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getAMF();
            op.VALUE            = getHost()->getMemory32()->read(op.INTERIM_OFFSET);
        }
        break;
    case I_AOF:
        {
            op.ADDR_TYPE        = A_MEM;
            op.INTERIM_OFFSET   = getHost()->getAU32()->getAOF();
            op.VALUE            = getHost()->getMemory32()->read(op.INTERIM_OFFSET);
        }
        break;
    */
    default:
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100Order::loadMemory(T100OPERATOR_SINGLE& op)
{
    op.FLAG             = T100TRUE;
    op.OFFSET           = getHost()->getCU32()->getCurrent() - 1;

    switch(op.TYPE){
    case T_IMM:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getCU32()->step();
        }
        break;
    case T_MEM:
        {
            op.ADDR_TYPE        = A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.OFFSET, op.VALUE);
        }
        break;
    case T_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.OFFSET + op.INDEX, op.VALUE);
        }
        break;
    case I_MEM:
        {
            op.ADDR_TYPE        = A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET, op.OFFSET);
            getHost()->getMemory32()->read(op.OFFSET, op.VALUE);
        }
        break;
    case I_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            getHost()->getMemory32()->read(op.INTERIM_OFFSET + op.INDEX, op.OFFSET);
            getHost()->getMemory32()->read(op.OFFSET, op.VALUE);
        }
        break;
    case ST_IMM:
        {
            op.ADDR_TYPE        = A_IMM;
            op.VALUE            = getHost()->getCU32()->step();
        }
        break;
    case ST_MEM:
        {
            op.ADDR_TYPE        = A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            getHost()->getMemory32()->raw_read(0, op.OFFSET, op.VALUE);
        }
        break;
    case ST_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = A_MEM;
            op.OFFSET           = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            getHost()->getMemory32()->raw_read(0, op.OFFSET + op.INDEX, op.VALUE);
        }
        break;
    case SI_MEM:
        {
            op.ADDR_TYPE        = A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            getHost()->getMemory32()->raw_read(0, op.INTERIM_OFFSET, op.OFFSET);
            getHost()->getMemory32()->raw_read(0, op.OFFSET, op.VALUE);
        }
        break;
    case SI_ARR:
        {
            op.ARRAY            = T100TRUE;
            op.ADDR_TYPE        = A_IND;
            op.INTERIM_OFFSET   = getHost()->getCU32()->step();
            op.INDEX            = getHost()->getCU32()->step();
            getHost()->getMemory32()->raw_read(0, op.INTERIM_OFFSET + op.INDEX, op.OFFSET);
            getHost()->getMemory32()->raw_read(0, op.OFFSET, op.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}
