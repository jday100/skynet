#include "T100BusIntel64.h"

#include "T100MemoryIntel64.h"

T100BusIntel64::T100BusIntel64() :
    T100Bus()
{
    //ctor
}

T100BusIntel64::~T100BusIntel64()
{
    //dtor
}

T100VOID T100BusIntel64::Plug(T100Device* device)
{
    device->SetBus(this);
}

T100VOID T100BusIntel64::Unplug(T100Device* device)
{

}

T100VOID T100BusIntel64::PlugMemory(T100MemoryIntel64* memory)
{
    m_memory    = memory;
}

T100BOOL T100BusIntel64::Read(T100UINT64 offset, T100BYTE* data)
{
    return m_memory->Read(offset, data);
}

T100BOOL T100BusIntel64::Read(T100UINT64 offset, T100UINT16* data)
{
    return m_memory->Read(offset, data);
}

T100BOOL T100BusIntel64::Read(T100UINT64 offset, T100UINT32* data)
{
    return m_memory->Read(offset, data);
}
