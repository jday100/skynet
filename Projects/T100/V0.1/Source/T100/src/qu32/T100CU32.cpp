#include "T100CU32.h"

#include "T100QU32.h"
#include "T100QU32Setup.h"
#include "T100OrderTypes.h"

namespace T100QU32{

T100CU32::T100CU32(T100QU32* host)
    :m_host(host)
{
    //ctor
}

T100CU32::~T100CU32()
{
    //dtor
}

T100VOID T100CU32::setCOR(T100WORD value)
{
    m_cor.setValue(value);
    if(T100QU32Setup::DEBUG){
        m_host->getNotifier().notify_register_cor();
    }
}

T100WORD T100CU32::getCOR()
{
    T100WORD    result, value;

    value = m_cor.getValue();
    m_cor.setValue(value + 1);

    if(T100QU32Setup::DEBUG){
        m_host->getNotifier().notify_register_cor();
    }
    return value;
}

T100VOID T100CU32::setCBR(T100WORD value)
{
    m_cbr.setValue(value);
    if(T100QU32Setup::DEBUG){
        m_host->getNotifier().notify_register_cbr();
    }
}

T100WORD T100CU32::getCBR()
{
    return m_cbr.getValue();
}

T100VOID T100CU32::setCCR(T100WORD value)
{
    m_ccr.setValue(value);
    if(T100QU32Setup::DEBUG){
        m_host->getNotifier().notify_register_ccr();
    }
}

T100WORD T100CU32::getCCR()
{
    return m_ccr.getValue();
}

T100VOID T100CU32::setSSR(T100WORD value)
{
    m_ssr.setValue(value);
    if(T100QU32Setup::DEBUG){
        m_host->getNotifier().notify_register_ssr();
    }
}

T100WORD T100CU32::getSSR()
{
    return m_ssr.getValue();
}

T100VOID T100CU32::setSPR(T100WORD value)
{
    m_spr.setValue(value);
    if(T100QU32Setup::DEBUG){
        m_host->getNotifier().notify_register_spr();
    }
}

T100WORD T100CU32::getSPR()
{
    return m_spr.getValue();
}

T100VOID T100CU32::setGDR(T100WORD value)
{
    m_gdr.setValue(value);
}

T100WORD T100CU32::getGDR()
{
    return m_gdr.getValue();
}

T100WORD T100CU32::step()
{
    T100BOOL        result;
    T100WORD        base, offset, value;

    base        = getCBR();
    offset      = getCOR();
    result      = getHost()->getMemory32()->raw_read(base, offset, value);

    return value;
}

T100WORD T100CU32::getCurrent()
{
    return m_cor.getValue();
}

T100QU32* T100CU32::getHost()
{
    return m_host;
}

T100BOOL T100CU32::push(T100WORD value)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        offset;
    T100WORD        ssr;
    T100WORD        spr;

    ssr     = m_ssr.getValue();

    if(0 == ssr){
        return T100FALSE;
    }

    spr     = m_spr.getValue() + 1;
    offset  = ssr + spr;

    result  = getHost()->getMemory32()->raw_write(0, offset, value);

    if(result){
        setSPR(spr);
        result = getHost()->getMemory32()->raw_write(0, ssr, spr);
    }
    return result;
}

T100BOOL T100CU32::pop(T100WORD& value)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        offset;
    T100WORD        ssr;
    T100WORD        spr;

    ssr     = m_ssr.getValue();

    if(0 == ssr){
        return T100FALSE;
    }

    spr     = m_spr.getValue();

    if(0 < spr){
        offset  = ssr + spr;
        result  = getHost()->getMemory32()->raw_read(0, offset, value);
    }else{
        return T100FALSE;
    }

    if(result){
        spr--;
        setSPR(spr);
        result = getHost()->getMemory32()->raw_write(0, ssr, spr);
    }

    return result;
}

}
