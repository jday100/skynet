#include "T100OrderAll.h"

#include "T100BitTypes.h"


namespace T100QU32{

T100OrderAll::T100OrderAll(T100QU32* host, T100Executor32* exec)
    :T100OrderOperator(host, exec)
{
    //ctor
}

T100OrderAll::~T100OrderAll()
{
    //dtor
}

T100BOOL T100OrderAll::parseOperatorAllBuild(T100SentenceBase::T100OPERATOR_BUILD& build)
{

}

T100BOOL T100OrderAll::loadOperatorAllBuild(T100BYTE type, T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    build.TYPE      = type;

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
            build.USED      = T100TRUE;
            result          = loadAllRegister(build);
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

T100BOOL T100OrderAll::loadAllRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
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

T100BOOL T100OrderAll::parsePushAllBuild()
{
    T100BOOL            result          = T100FALSE;
    T100WORD_BITS       order;
    T100SentenceBase::T100OPERATOR_BUILD        build;

    order.WORD  = m_order;

    result = loadOperatorAllBuild(order.BYTE3.BYTE, build);

    if(result){
        result = getOperatorSource(build);
    }

    if(result){
        result = getHost()->getCU32()->push(build.VALUE);
    }
    return result;
}

T100BOOL T100OrderAll::parsePopAllBuild()
{
    T100BOOL            result          = T100FALSE;
    T100WORD_BITS       order;
    T100SentenceBase::T100OPERATOR_BUILD        build;

    order.WORD  = m_order;

    result = loadOperatorAllBuild(order.BYTE3.BYTE, build);

    if(result){
        result = getHost()->getCU32()->pop(build.VALUE);
    }

    if(result){
        result = setOperatorTarget(build);
    }

    return result;
}


}
