#include "T100Interrupt32.h"

#include "T100OrderTypes.h"
#include "T100QU32.h"
#include "T100QU32Setup.h"


namespace T100QU32{

T100Interrupt32::T100Interrupt32(T100QU32* host)
    :m_host(host)
{
    //ctor
    create();
}

T100Interrupt32::~T100Interrupt32()
{
    //dtor
    destroy();
}

T100VOID T100Interrupt32::create()
{

}

T100VOID T100Interrupt32::destroy()
{

}

T100QU32* T100Interrupt32::getHost()
{
    return m_host;
}

T100VOID T100Interrupt32::interrupt(T100BYTE id)
{
    icall(id);
}

T100VOID T100Interrupt32::call(T100WORD base, T100WORD offset)
{
    pushAll();

    m_host->getCU32()->setCBR(base);
    m_host->getCU32()->setCOR(offset);
}

T100VOID T100Interrupt32::call(T100WORD offset)
{
    pushAll();

    m_host->getCU32()->setCOR(offset);
}

T100VOID T100Interrupt32::ret()
{
    popAll();
}

T100VOID T100Interrupt32::icall(T100BYTE id)
{
    if(m_locked)return;
    m_locked = T100TRUE;

    pushAll();

    T100BOOL        result;
    T100WORD        base;
    T100WORD        offset;
    T100WORD        root;
    T100WORD        value;

    T100WORD        ssr;
    T100WORD        spr;

    ssr     = m_host->getCU32()->getSSR();
    spr     = m_host->getCU32()->getSPR();

    root    = T100QU32Setup::getRamBase();
    value   = root + id * 4;

    m_host->getCU32()->setCBR(0);

    result  = m_host->getMemory32()->raw_read(0, value, base);
    if(!result)return;

    result  = m_host->getMemory32()->raw_read(0, value + 1, offset);
    if(!result)return;

    result  = getStack(value);
    if(!result)return;

    result  = m_host->getCU32()->push(ssr);
    if(!result)return;

    result  = m_host->getCU32()->push(spr);
    if(!result)return;

    m_host->getCU32()->setCBR(base);
    m_host->getCU32()->setCOR(offset);
}

T100VOID T100Interrupt32::iret()
{
    T100BOOL    result;
    T100WORD    ssr;
    T100WORD    spr;

    result = m_host->getCU32()->pop(spr);
    if(!result)return;

    result = m_host->getCU32()->pop(ssr);
    if(!result)return;

    m_host->getCU32()->setSSR(ssr);
    m_host->getCU32()->setSPR(spr);

    popAll();

    m_locked = T100FALSE;
}

T100VOID T100Interrupt32::lock()
{
    m_locked = T100TRUE;
}

T100VOID T100Interrupt32::unlock()
{
    m_locked = T100FALSE;
}

T100VOID T100Interrupt32::push()
{
    T100WORD_VECTOR*    data = T100NEW T100WORD_VECTOR(8);

    (*data)[T100Component::T100COR] = m_host->getCU32()->getCurrent();
    (*data)[T100Component::T100CBR] = m_host->getCU32()->getCBR();
    (*data)[T100Component::T100CCR] = m_host->getCU32()->getCCR();
    (*data)[T100Component::T100AAR] = m_host->getAU32()->getAAR();
    (*data)[T100Component::T100ABR] = m_host->getAU32()->getABR();
    (*data)[T100Component::T100ACR] = m_host->getAU32()->getACR();
    (*data)[T100Component::T100ADR] = m_host->getAU32()->getADR();

    m_stack.push(data);
}

T100VOID T100Interrupt32::pop()
{
    T100WORD_VECTOR*    data = T100NULL;

    data = m_stack.top();
    m_stack.pop();

    m_host->getCU32()->setCOR((*data)[T100Component::T100COR]);
    m_host->getCU32()->setCBR((*data)[T100Component::T100CBR]);
    m_host->getCU32()->setCCR((*data)[T100Component::T100CCR]);
    m_host->getAU32()->setAAR((*data)[T100Component::T100AAR]);
    m_host->getAU32()->setABR((*data)[T100Component::T100ABR]);
    m_host->getAU32()->setACR((*data)[T100Component::T100ACR]);
    m_host->getAU32()->setADR((*data)[T100Component::T100ADR]);

    data->clear();
    T100SAFE_DELETE(data);
}

T100BOOL T100Interrupt32::pushAll()
{
    T100BOOL        result          = T100TRUE;
    T100WORD        value;

    value   = getHost()->getCU32()->getCurrent();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getCU32()->getCBR();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getCU32()->getCCR();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getAAR();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getABR();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getACR();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getADR();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getACF();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getAMF();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    value   = getHost()->getAU32()->getAOF();
    result  = getHost()->getCU32()->push(value);
    if(!result){
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Interrupt32::popAll()
{
    T100BOOL        result          = T100TRUE;
    T100WORD        value;

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setAOF(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setAMF(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setACF(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setADR(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setACR(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setABR(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getAU32()->setAAR(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getCU32()->setCCR(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getCU32()->setCBR(value);

    result  = getHost()->getCU32()->pop(value);
    if(!result){
        return T100FALSE;
    }
    getHost()->getCU32()->m_cor.setValue(value);

    return result;
}

T100BOOL T100Interrupt32::getStack(T100WORD base)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        offset;
    T100WORD        ssr;
    T100WORD        spr;

    offset  = base + 2;

    result  = getHost()->getMemory32()->raw_read(0, offset, ssr);
    if(!result){
        return T100FALSE;
    }

    result  = getHost()->getMemory32()->raw_read(0, ssr, spr);
    if(!result){
        return T100FALSE;
    }

    m_host->getCU32()->setSSR(ssr);
    m_host->getCU32()->setSPR(spr);

    return T100TRUE;
}


}
