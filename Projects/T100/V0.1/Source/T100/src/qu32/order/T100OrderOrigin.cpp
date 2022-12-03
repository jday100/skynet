#include "T100OrderOrigin.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderOrigin::T100OrderOrigin(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderOrigin::~T100OrderOrigin()
{
    //dtor
}

T100Gdt32* T100OrderOrigin::getGdt()
{
    return getHost()->getGdt32();
}

T100BOOL T100OrderOrigin::push(T100WORD value)
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

T100BOOL T100OrderOrigin::pop(T100WORD& value)
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

T100BOOL T100OrderOrigin::pushAll()
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

T100BOOL T100OrderOrigin::popAll()
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

T100BOOL T100OrderOrigin::getAddrType(T100BYTE value, T100SentenceBase::T100ADDRESSING_TYPE& type)
{
    T100BOOL        result          = T100TRUE;

    switch(value){
    case 1:
        {
            type = T100SentenceBase::A_IMM;
        }
        break;
    case 2:
        {
            type = T100SentenceBase::A_MEM;
        }
        break;
    case 3:
        {
            type = T100SentenceBase::A_IND;
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

}
