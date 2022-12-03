#include "T100OrderOperator.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderOperator::T100OrderOperator(T100QU32* host, T100Executor32* exec)
    :T100OrderOrigin(host, exec)
{
    //ctor
}

T100OrderOperator::~T100OrderOperator()
{
    //dtor
}

T100BOOL T100OrderOperator::parseByteBuild(T100BYTE& value)
{
    T100WORD_BITS       order;

    order.WORD      = m_order;
    value           = order.BYTE3.BYTE;

    return T100TRUE;
}

T100BOOL T100OrderOperator::parseWordBuild(T100WORD& value)
{
    value = getHost()->getCU32()->step();
    return T100TRUE;
}

T100BOOL T100OrderOperator::parseLongWordBuild(T100LONG& value)
{
    return T100FALSE;
}

T100BOOL T100OrderOperator::loadOperatorBuild(T100BYTE type, T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    build.TYPE      = type;

    switch(type){
    case T100SentenceBase::T_NONE:
        {

        }
        break;
    case T100SentenceBase::T_COR:
    case T100SentenceBase::T_CBR:
    case T100SentenceBase::T_CCR:
    case T100SentenceBase::T_SSR:
    case T100SentenceBase::T_SPR:
    case T100SentenceBase::T_AAR:
    case T100SentenceBase::T_ABR:
    case T100SentenceBase::T_ACR:
    case T100SentenceBase::T_ADR:
    case T100SentenceBase::T_ACF:
    case T100SentenceBase::T_AMF:
    case T100SentenceBase::T_AOF:
    case T100SentenceBase::I_COR:
    case T100SentenceBase::I_CBR:
    case T100SentenceBase::I_CCR:
    case T100SentenceBase::I_AAR:
    case T100SentenceBase::I_ABR:
    case T100SentenceBase::I_ACR:
    case T100SentenceBase::I_ADR:
        {
            build.USED      = T100TRUE;
            result          = loadRegister(build);
        }
        break;
    case T100SentenceBase::T_IMM:
    case T100SentenceBase::T_MEM:
    case T100SentenceBase::T_ARR:
    case T100SentenceBase::I_MEM:
    case T100SentenceBase::I_ARR:
    //
    case T100SentenceBase::ST_IMM:
    case T100SentenceBase::ST_MEM:
    case T100SentenceBase::ST_ARR:
    case T100SentenceBase::SI_MEM:
    case T100SentenceBase::SI_ARR:
        {
            build.USED      = T100TRUE;
            result          = loadMemory(build);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::loadRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    build.FLAG      = T100FALSE;
    build.OFFSET    = getHost()->getCU32()->getCurrent() - 1;

    switch(build.TYPE){
    case T100SentenceBase::T_COR:
    case T100SentenceBase::T_CBR:
    case T100SentenceBase::T_CCR:
    case T100SentenceBase::T_SSR:
    case T100SentenceBase::T_SPR:
    case T100SentenceBase::T_AAR:
    case T100SentenceBase::T_ABR:
    case T100SentenceBase::T_ACR:
    case T100SentenceBase::T_ADR:
    case T100SentenceBase::T_ACF:
    case T100SentenceBase::T_AMF:
    case T100SentenceBase::T_AOF:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_IMM;
        }
        break;
    case T100SentenceBase::I_COR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = build.OFFSET;
        }
        break;
    case T100SentenceBase::I_CBR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = getHost()->getCU32()->getCBR();
        }
        break;
    case T100SentenceBase::I_CCR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = getHost()->getCU32()->getCCR();
        }
        break;
    case T100SentenceBase::I_AAR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = getHost()->getAU32()->getAAR();
        }
        break;
    case T100SentenceBase::I_ABR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = getHost()->getAU32()->getABR();
        }
        break;
    case T100SentenceBase::I_ACR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = getHost()->getAU32()->getACR();
        }
        break;
    case T100SentenceBase::I_ADR:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.INTERIM_OFFSET    = getHost()->getAU32()->getADR();
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::loadMemory(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    build.FLAG      = T100TRUE;
    build.OFFSET    = getHost()->getCU32()->getCurrent() - 1;

    switch(build.TYPE){
    case T100SentenceBase::T_IMM:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_IMM;
        }
        break;
    case T100SentenceBase::T_MEM:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.OFFSET            = getHost()->getCU32()->step();
        }
        break;
    case T100SentenceBase::T_ARR:
        {
            build.ARRAY             = T100TRUE;
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.OFFSET            = getHost()->getCU32()->step();
            build.INDEX             = getHost()->getCU32()->step();
        }
        break;
    case T100SentenceBase::I_MEM:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_IND;
            build.INTERIM_OFFSET    = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.OFFSET);
        }
        break;
    case T100SentenceBase::I_ARR:
        {
            build.ARRAY             = T100TRUE;
            build.ADDR_TYPE         = T100SentenceBase::A_IND;
            build.INTERIM_OFFSET    = getHost()->getCU32()->step();
            build.INDEX             = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET + build.INDEX, build.OFFSET);
        }
        break;
    case T100SentenceBase::ST_IMM:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_IMM;
        }
        break;
    case T100SentenceBase::ST_MEM:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.OFFSET            = getHost()->getCU32()->step();
        }
        break;
    case T100SentenceBase::ST_ARR:
        {
            build.ARRAY             = T100TRUE;
            build.ADDR_TYPE         = T100SentenceBase::A_MEM;
            build.OFFSET            = getHost()->getCU32()->step();
            build.INDEX             = getHost()->getCU32()->step();
        }
        break;
    case T100SentenceBase::SI_MEM:
        {
            build.ADDR_TYPE         = T100SentenceBase::A_IND;
            build.INTERIM_OFFSET    = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->raw_read(0, build.INTERIM_OFFSET, build.OFFSET);
        }
        break;
    case T100SentenceBase::SI_ARR:
        {
            build.ARRAY             = T100TRUE;
            build.ADDR_TYPE         = T100SentenceBase::A_IND;
            build.INTERIM_OFFSET    = getHost()->getCU32()->step();
            build.INDEX             = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->raw_read(0, build.INTERIM_OFFSET + build.INDEX, build.OFFSET);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::getOperatorSource(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100SentenceBase::T_NONE:
        {

        }
        break;
    case T100SentenceBase::T_COR:
    case T100SentenceBase::T_CBR:
    case T100SentenceBase::T_CCR:
    case T100SentenceBase::T_SSR:
    case T100SentenceBase::T_SPR:
    case T100SentenceBase::T_AAR:
    case T100SentenceBase::T_ABR:
    case T100SentenceBase::T_ACR:
    case T100SentenceBase::T_ADR:
    case T100SentenceBase::T_ACF:
    case T100SentenceBase::T_AMF:
    case T100SentenceBase::T_AOF:
    case T100SentenceBase::I_COR:
    case T100SentenceBase::I_CBR:
    case T100SentenceBase::I_CCR:
    case T100SentenceBase::I_AAR:
    case T100SentenceBase::I_ABR:
    case T100SentenceBase::I_ACR:
    case T100SentenceBase::I_ADR:
        {
            result          = getRegister(build);
        }
        break;
    case T100SentenceBase::T_IMM:
    case T100SentenceBase::T_MEM:
    case T100SentenceBase::T_ARR:
    case T100SentenceBase::I_MEM:
    case T100SentenceBase::I_ARR:
    //
    case T100SentenceBase::ST_IMM:
    case T100SentenceBase::ST_MEM:
    case T100SentenceBase::ST_ARR:
    case T100SentenceBase::SI_MEM:
    case T100SentenceBase::SI_ARR:
        {
            result          = getMemory(build);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::getRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100SentenceBase::T_COR:
        {
            build.VALUE = build.OFFSET;
        }
        break;
    case T100SentenceBase::T_CBR:
        {
            build.VALUE = getHost()->getCU32()->getCBR();
        }
        break;
    case T100SentenceBase::T_CCR:
        {
            build.VALUE = getHost()->getCU32()->getCCR();
        }
        break;
    case T100SentenceBase::T_SSR:
        {
            build.VALUE = getHost()->getCU32()->getSSR();
        }
        break;
    case T100SentenceBase::T_SPR:
        {
            build.VALUE = getHost()->getCU32()->getSPR();
        }
        break;
    case T100SentenceBase::T_AAR:
        {
            build.VALUE = getHost()->getAU32()->getAAR();
        }
        break;
    case T100SentenceBase::T_ABR:
        {
            build.VALUE = getHost()->getAU32()->getABR();
        }
        break;
    case T100SentenceBase::T_ACR:
        {
            build.VALUE = getHost()->getAU32()->getACR();
        }
        break;
    case T100SentenceBase::T_ADR:
        {
            build.VALUE = getHost()->getAU32()->getADR();
        }
        break;
    case T100SentenceBase::T_ACF:
        {
            build.VALUE = getHost()->getAU32()->getACF();
        }
        break;
    case T100SentenceBase::T_AMF:
        {
            build.VALUE = getHost()->getAU32()->getAMF();
        }
        break;
    case T100SentenceBase::T_AOF:
        {
            build.VALUE = getHost()->getAU32()->getAOF();
        }
        break;
    case T100SentenceBase::I_COR:
    case T100SentenceBase::I_CBR:
    case T100SentenceBase::I_CCR:
    case T100SentenceBase::I_AAR:
    case T100SentenceBase::I_ABR:
    case T100SentenceBase::I_ACR:
    case T100SentenceBase::I_ADR:
        {
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::getMemory(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100SentenceBase::T_IMM:
        {
            build.VALUE         = getHost()->getCU32()->step();
        }
        break;
    case T100SentenceBase::T_MEM:
        {
            result = getHost()->getMemory32()->read(build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::T_ARR:
        {
            result = getHost()->getMemory32()->read(build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100SentenceBase::I_MEM:
        {
            result = getHost()->getMemory32()->read(build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::I_ARR:
        {
            result = getHost()->getMemory32()->read(build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::ST_IMM:
        {
            build.VALUE         = getHost()->getCU32()->step();
        }
        break;
    case T100SentenceBase::ST_MEM:
        {
            result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::ST_ARR:
        {
            result = getHost()->getMemory32()->raw_read(0, build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100SentenceBase::SI_MEM:
        {
            result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::SI_ARR:
        {
            result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::setOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100SentenceBase::T_NONE:
        {
            return T100FALSE;
        }
        break;
    case T100SentenceBase::T_COR:
    case T100SentenceBase::T_CBR:
    case T100SentenceBase::T_CCR:
    case T100SentenceBase::T_SSR:
    case T100SentenceBase::T_SPR:
    case T100SentenceBase::T_AAR:
    case T100SentenceBase::T_ABR:
    case T100SentenceBase::T_ACR:
    case T100SentenceBase::T_ADR:
    case T100SentenceBase::T_ACF:
    case T100SentenceBase::T_AMF:
    case T100SentenceBase::T_AOF:
    case T100SentenceBase::I_COR:
    case T100SentenceBase::I_CBR:
    case T100SentenceBase::I_CCR:
    case T100SentenceBase::I_AAR:
    case T100SentenceBase::I_ABR:
    case T100SentenceBase::I_ACR:
    case T100SentenceBase::I_ADR:
        {
            result  = setRegister(build);
        }
        break;
    case T100SentenceBase::T_IMM:
    case T100SentenceBase::T_MEM:
    case T100SentenceBase::T_ARR:
    case T100SentenceBase::I_MEM:
    case T100SentenceBase::I_ARR:
    //
    case T100SentenceBase::ST_IMM:
    case T100SentenceBase::ST_MEM:
    case T100SentenceBase::ST_ARR:
    case T100SentenceBase::SI_MEM:
    case T100SentenceBase::SI_ARR:
        {
            result  = setMemory(build);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::setRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100SentenceBase::T_COR:
        {
            getHost()->getCU32()->setCOR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_CBR:
        {
            getHost()->getCU32()->setCBR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_CCR:
        {
            getHost()->getCU32()->setCCR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_SSR:
        {
            getHost()->getCU32()->setSSR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_SPR:
        {
            getHost()->getCU32()->setSPR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_AAR:
        {
            getHost()->getAU32()->setAAR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_ABR:
        {
            getHost()->getAU32()->setABR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_ACR:
        {
            getHost()->getAU32()->setACR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_ADR:
        {
            getHost()->getAU32()->setADR(build.VALUE);
        }
        break;
    case T100SentenceBase::T_ACF:
        {
            getHost()->getAU32()->setACF(build.VALUE);
        }
        break;
    case T100SentenceBase::T_AMF:
        {
            getHost()->getAU32()->setAMF(build.VALUE);
        }
        break;
    case T100SentenceBase::T_AOF:
        {
            getHost()->getAU32()->setAOF(build.VALUE);
        }
        break;
    case T100SentenceBase::I_COR:
    case T100SentenceBase::I_CBR:
    case T100SentenceBase::I_CCR:
    case T100SentenceBase::I_AAR:
    case T100SentenceBase::I_ABR:
    case T100SentenceBase::I_ACR:
    case T100SentenceBase::I_ADR:
        {
            result = getHost()->getMemory32()->write(build.OFFSET, build.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderOperator::setMemory(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100SentenceBase::T_MEM:
        {
            result = getHost()->getMemory32()->write(build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::T_ARR:
        {
            result = getHost()->getMemory32()->write(build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100SentenceBase::I_MEM:
        {
            result = getHost()->getMemory32()->write(build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::I_ARR:
        {
            result = getHost()->getMemory32()->write(build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100SentenceBase::ST_IMM:
        {
            return T100FALSE;
        }
        break;
    case T100SentenceBase::ST_MEM:
        {
            result = getHost()->getMemory32()->raw_write(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::ST_ARR:
        {
            result = getHost()->getMemory32()->raw_write(0, build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100SentenceBase::SI_MEM:
        {
            result = getHost()->getMemory32()->raw_write(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100SentenceBase::SI_ARR:
        {
            result = getHost()->getMemory32()->raw_write(0, build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

}
