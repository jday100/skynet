#include "T100OrderBase.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderBase::T100OrderBase(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderBase::~T100OrderBase()
{
    //dtor
}

T100Gdt32* T100OrderBase::getGdt()
{
    return getHost()->getGdt32();
}

T100BOOL T100OrderBase::parseByteBuild(T100BYTE& value)
{
    T100WORD_BITS       order;

    order.WORD      = m_order;
    value           = order.BYTE3.BYTE;

    return T100TRUE;
}

T100BOOL T100OrderBase::parseWordBuild(T100WORD& value)
{
    value = getHost()->getCU32()->step();
    return T100TRUE;
}

T100BOOL T100OrderBase::parseLongWordBuild(T100LONG& value)
{
    return T100FALSE;
}

T100BOOL T100OrderBase::parseOperatorBuild(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    result = loadOperatorBuild(build);

    if(result){
        result = getOperatorValue(build);
    }

    if(result){
        result = setOperatorTarget(build);
    }

    return result;
}


T100BOOL T100OrderBase::loadOperatorBuild(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL            result          = T100FALSE;
    T100WORD_BITS       order;

    order.WORD      = m_order;
    build.TYPE      = order.BYTE3.BYTE;

    switch(build.TYPE){
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
            build.USED      = T100TRUE;
            result          = loadRegister(build);
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
            build.USED      = T100TRUE;
            result          = loadMemory(build);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::loadOperatorAllBuild(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL            result          = T100FALSE;
    T100WORD_BITS       order;

    order.WORD      = m_order;
    build.TYPE      = order.BYTE3.BYTE;

    switch(build.TYPE){
    case T100Component::T_ALL:
        {
            build.FLAG      = T100FALSE;
            result          = T100TRUE;
        }
        break;
    default:
        return loadOperatorBuild(build);
    }
    return result;
}

T100BOOL T100OrderBase::getOperatorValue(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
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
            result  = getRegister(build);
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
            result  = getMemory(build);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::setOperatorTarget(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
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
            result  = setRegister(build);
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
            result  = setMemory(build);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::loadRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    build.FLAG      = T100FALSE;
    build.OFFSET    = getHost()->getCU32()->getCurrent() - 1;

    switch(build.TYPE){
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
        {

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

        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::loadMemory(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    build.FLAG      = T100TRUE;
    build.OFFSET    = getHost()->getCU32()->getCurrent() - 1;

    switch(build.TYPE){
    case T100Component::T_IMM:
        {

        }
        break;
    case T100Component::T_MEM:
        {

        }
        break;
    case T100Component::T_ARR:
        {

        }
        break;
    case T100Component::I_MEM:
        {

        }
        break;
    case T100Component::I_ARR:
        {

        }
        break;
    case T100Component::ST_IMM:
        {

        }
        break;
    case T100Component::ST_MEM:
        {

        }
        break;
    case T100Component::ST_ARR:
        {

        }
        break;
    case T100Component::SI_MEM:
        {

        }
        break;
    case T100Component::SI_ARR:
        {

        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::getRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100Component::T_NONE:
        {
            return T100FALSE;
        }
        break;
    case T100Component::T_COR:
        {
            build.VALUE     = build.OFFSET;
        }
        break;
    case T100Component::T_CBR:
        {
            build.VALUE     = getHost()->getCU32()->getCBR();
        }
        break;
    case T100Component::T_CCR:
        {
            build.VALUE     = getHost()->getCU32()->getCCR();
        }
        break;
    case T100Component::T_SSR:
        {
            build.VALUE     = getHost()->getCU32()->getSSR();
        }
        break;
    case T100Component::T_SPR:
        {
            build.VALUE     = getHost()->getCU32()->getSPR();
        }
        break;
    case T100Component::T_AAR:
        {
            build.VALUE     = getHost()->getAU32()->getAAR();
        }
        break;
    case T100Component::T_ABR:
        {
            build.VALUE     = getHost()->getAU32()->getABR();
        }
        break;
    case T100Component::T_ACR:
        {
            build.VALUE     = getHost()->getAU32()->getACR();
        }
        break;
    case T100Component::T_ADR:
        {
            build.VALUE     = getHost()->getAU32()->getADR();
        }
        break;
    case T100Component::T_ACF:
        {
            build.VALUE     = getHost()->getAU32()->getACF();
        }
        break;
    case T100Component::T_AMF:
        {
            build.VALUE     = getHost()->getAU32()->getAMF();
        }
        break;
    case T100Component::T_AOF:
        {
            build.VALUE     = getHost()->getAU32()->getAOF();
        }
        break;
    case T100Component::I_COR:
        {
            build.INTERIM_OFFSET    = build.OFFSET;
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_CBR:
        {
            build.INTERIM_OFFSET    = getHost()->getCU32()->getCBR();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_CCR:
        {
            build.INTERIM_OFFSET    = getHost()->getCU32()->getCCR();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_AAR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getAAR();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_ABR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_ACR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getACR();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_ADR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getADR();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::getMemory(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100Component::T_IMM:
        {
            build.VALUE     = getHost()->getCU32()->step();
        }
        break;
    case T100Component::T_MEM:
        {
            result = getHost()->getMemory32()->read(build.OFFSET, build.VALUE);
        }
        break;
    case T100Component::T_ARR:
        {
           result = getHost()->getMemory32()->read(build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100Component::I_MEM:
        {
            build.INTERIM_OFFSET    = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->read(build.OFFSET, build.VALUE);
            }
        }
        break;
    case T100Component::I_AAR:
        {
            build.INTERIM_OFFSET    = getHost()->getCU32()->step();
            build.INDEX             = getHost()->getCU32()->step();
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->read(build.OFFSET, build.VALUE);
            }
        }
        break;
    case T100Component::ST_IMM:
        {
            build.VALUE     = getHost()->getCU32()->step();
        }
        break;
    case T100Component::ST_MEM:
        {
            result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100Component::ST_ARR:
        {
            result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100Component::SI_MEM:
        {
            result = getHost()->getMemory32()->raw_read(0, build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
            }
        }
        break;
    case T100Component::SI_ARR:
        {
            result = getHost()->getMemory32()->raw_read(0, build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->raw_read(0, build.OFFSET, build.VALUE);
            }
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}


T100BOOL T100OrderBase::setRegister(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100Component::T_NONE:
        {
            return T100FALSE;
        }
        break;
    case T100Component::T_COR:
        {
            return T100FALSE;
        }
        break;
    case T100Component::T_CBR:
        {
            getHost()->getCU32()->setCBR(build.VALUE);
        }
        break;
    case T100Component::T_CCR:
        {
            getHost()->getCU32()->setCCR(build.VALUE);
        }
        break;
    case T100Component::T_SSR:
        {
            getHost()->getCU32()->setSSR(build.VALUE);
        }
        break;
    case T100Component::T_SPR:
        {
            getHost()->getCU32()->setSPR(build.VALUE);
        }
        break;
    case T100Component::T_AAR:
        {
            getHost()->getAU32()->setAAR(build.VALUE);
        }
        break;
    case T100Component::T_ABR:
        {
            getHost()->getAU32()->setABR(build.VALUE);
        }
        break;
    case T100Component::T_ACR:
        {
            getHost()->getAU32()->setACR(build.VALUE);
        }
        break;
    case T100Component::T_ADR:
        {
            getHost()->getAU32()->setADR(build.VALUE);
        }
        break;
    case T100Component::T_ACF:
        {
            getHost()->getAU32()->setACF(build.VALUE);
        }
        break;
    case T100Component::T_AMF:
        {
            getHost()->getAU32()->setAMF(build.VALUE);
        }
        break;
    case T100Component::T_AOF:
        {
            getHost()->getAU32()->setAOF(build.VALUE);
        }
        break;
    case T100Component::I_COR:
        {
            build.INTERIM_OFFSET    = build.OFFSET;
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_CBR:
        {
            build.INTERIM_OFFSET    = getHost()->getCU32()->getCBR();
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_CCR:
        {
            build.INTERIM_OFFSET    = getHost()->getCU32()->getCCR();
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_AAR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getAAR();
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_ABR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getABR();
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_ACR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getACR();
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    case T100Component::I_ADR:
        {
            build.INTERIM_OFFSET    = getHost()->getAU32()->getADR();
            result = getHost()->getMemory32()->write(build.INTERIM_OFFSET, build.VALUE);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::setMemory(T100SentenceBase::T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    switch(build.TYPE){
    case T100Component::T_IMM:
        {
            return T100FALSE;
        }
        break;
    case T100Component::T_MEM:
        {
            result = getHost()->getMemory32()->write(build.OFFSET, build.VALUE);
        }
        break;
    case T100Component::T_ARR:
        {
           result = getHost()->getMemory32()->write(build.OFFSET + build.INDEX, build.VALUE);
        }
        break;
    case T100Component::I_MEM:
        {
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->write(build.OFFSET, build.VALUE);
            }
        }
        break;
    case T100Component::I_AAR:
        {
            result = getHost()->getMemory32()->read(build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->write(build.OFFSET, build.VALUE);
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
            result = getHost()->getMemory32()->raw_write(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100Component::ST_ARR:
        {
            result = getHost()->getMemory32()->raw_write(0, build.OFFSET, build.VALUE);
        }
        break;
    case T100Component::SI_MEM:
        {
            result = getHost()->getMemory32()->raw_read(0, build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->raw_write(0, build.OFFSET, build.VALUE);
            }
        }
        break;
    case T100Component::SI_ARR:
        {
            result = getHost()->getMemory32()->raw_read(0, build.INTERIM_OFFSET, build.OFFSET);
            if(result){
                result = getHost()->getMemory32()->raw_write(0, build.OFFSET, build.VALUE);
            }
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100OrderBase::push(T100WORD value)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        base;
    T100WORD        ssr;
    T100WORD        spr;
    T100WORD        offset;

    base    = getHost()->getCU32()->getCBR();
    ssr     = getHost()->getCU32()->getSSR();
    spr     = getHost()->getCU32()->getSPR();

    offset  = ssr + spr;

    result = getHost()->getMemory32()->write(offset, value);
    if(result){
        spr++;
        getHost()->getCU32()->setSPR(spr);
    }
    return result;
}

T100BOOL T100OrderBase::pop(T100WORD& value)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        base;
    T100WORD        ssr;
    T100WORD        spr;
    T100WORD        offset;

    base    = getHost()->getCU32()->getCBR();
    ssr     = getHost()->getCU32()->getSSR();
    spr     = getHost()->getCU32()->getSPR();

    if(0 < spr){
        spr--;
    }else{
        return T100FALSE;
    }

    offset  = ssr + spr;
    result  = getHost()->getMemory32()->read(offset, value);
    if(result){
        getHost()->getCU32()->setSPR(spr);
    }
    return result;
}

T100BOOL T100OrderBase::pushAll()
{
    T100BOOL        result          = T100TRUE;
    T100WORD        value;

    value   = getHost()->getCU32()->getCBR();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getCU32()->getCCR();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getAAR();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getABR();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getACR();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getADR();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getACF();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getAMF();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getAOF();
    result  = push(value);
    if(!result){
        return T100FALSE;
    }

    return result;
}

T100BOOL T100OrderBase::popAll()
{
    T100BOOL        result          = T100TRUE;
    T100WORD        value;

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setAOF(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setAMF(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setACF(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setADR(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setACR(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setABR(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setAAR(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getCU32()->setCCR(value);

    result  = pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getCU32()->setCBR(value);

    return result;
}

}
