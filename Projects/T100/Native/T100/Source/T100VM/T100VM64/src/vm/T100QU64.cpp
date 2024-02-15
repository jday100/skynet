#include "T100QU64.h"

T100QU64::T100QU64()
{
    //ctor
}

T100QU64::~T100QU64()
{
    //dtor
}

T100BOOL T100QU64::start(INT64 length)
{
    m_bus       = T100NEW T100Bus64();
    m_port      = T100NEW T100Port64(m_bus);
    m_memory    = T100NEW T100Memory64(m_bus, length);
    m_cpu       = T100NEW T100Cpu64(m_bus);

    m_cpu->run();

    return T100FALSE;
}

T100BOOL T100QU64::stop()
{
    return T100FALSE;
}
