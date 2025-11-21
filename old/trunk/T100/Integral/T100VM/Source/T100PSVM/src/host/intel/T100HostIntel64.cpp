#include "T100HostIntel64.h"



T100HostIntel64::T100HostIntel64() :
    T100Host()
{
    //ctor
    init();
}

T100HostIntel64::~T100HostIntel64()
{
    //dtor
    uninit();
}

T100VOID T100HostIntel64::init()
{
    m_bus       = T100NEW T100BusIntel64();
    m_cpu       = T100NEW T100CPUIntel64();
    m_memory    = T100NEW T100MemoryIntel64();
    m_port      = T100NEW T100Port(this);

    m_bus->Plug(m_cpu);
    m_bus->PlugMemory(m_memory);

    T100Host::m_bus     = m_bus;
    T100Host::m_cpu     = m_cpu;
    T100Host::m_memory  = m_memory;
}

T100VOID T100HostIntel64::uninit()
{
    T100SAFE_DELETE(m_cpu)
    T100SAFE_DELETE(m_bus)
    T100SAFE_DELETE(m_memory)
    T100SAFE_DELETE(m_port)
}

T100BOOL T100HostIntel64::Pulse()
{
    return m_cpu->Pulse();
}

T100VOID T100HostIntel64::Info(T100DebugFrame* frame)
{
    m_cpu->Info(frame);
}
