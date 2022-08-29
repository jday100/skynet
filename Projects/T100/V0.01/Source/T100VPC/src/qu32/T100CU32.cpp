#include "T100CU32.h"

#include "T100QU32.h"


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
}

T100WORD T100CU32::getCOR()
{
    T100WORD result, value;

    value = m_cor.getValue();
    m_cor.setValue(value + 1);

    return value;
}

T100VOID T100CU32::setCBR(T100WORD value)
{
    m_cbr.setValue(value);
}

T100WORD T100CU32::getCBR()
{
    return m_cbr.getValue();
}

T100VOID T100CU32::setCCR(T100WORD value)
{
    m_ccr.setValue(value);
}

T100WORD T100CU32::getCCR()
{
    return m_ccr.getValue();
}

T100WORD T100CU32::step()
{
    T100WORD base, offset, value;

    base        = getCBR();
    offset      = getCOR();
    //value       = getHost()->getMemory32()->read(base, offset);

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
