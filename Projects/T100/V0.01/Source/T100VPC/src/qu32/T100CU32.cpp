#include "T100CU32.h"

#include "T100QU32.h"
#include "T100QU32Setup.h"
#include "T100OrderTypes.h"


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
        //m_host->getCallback()->notify_register_update(T100COR, value);
        m_host->getNotifier().notify_register_cor();
    }
}

T100WORD T100CU32::getCOR()
{
    T100WORD result, value;

    value = m_cor.getValue();
    m_cor.setValue(value + 1);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100COR, value + 1);
        m_host->getNotifier().notify_register_cor();
    }

    return value;
}

T100VOID T100CU32::setCBR(T100WORD value)
{
    m_cbr.setValue(value);
    if(T100QU32Setup::DEBUG){
        //m_host->getCallback()->notify_register_update(T100CBR, value);
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
        //m_host->getCallback()->notify_register_update(T100CBR, value);
        m_host->getNotifier().notify_register_ccr();
    }
}

T100WORD T100CU32::getCCR()
{
    return m_ccr.getValue();
}

T100WORD T100CU32::step()
{
    T100BOOL        result;
    T100WORD        base, offset, value;

    base        = getCBR();
    offset      = getCOR();
    result      = getHost()->getMemory32()->raw_read(base, offset, value);

    //T100Log::info(T100HintQU32::order_hint(base, "BASE"));
    //T100Log::info(T100HintQU32::order_hint(offset, "OFFSET"));
    //T100Log::info(T100HintQU32::order_hint(value, "VALUE"));

    return value;
}

T100WORD T100CU32::getCurrent()
{
    return m_cor.getValue();
}

T100QU32* T100CU32::getHost()
{
    T100QU32* host      = T100NULL;

    host = dynamic_cast<T100QU32*>(m_host);

    return host;
}
