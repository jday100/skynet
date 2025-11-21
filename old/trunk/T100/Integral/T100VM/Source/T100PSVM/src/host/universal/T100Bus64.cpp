#include "T100Bus64.h"

#include "T100Memory64.h"

T100Bus64::T100Bus64(T100Host64* host) :
    T100Bus(),
    m_host(host)
{
    //ctor
    m_busy      = T100FALSE;
    m_ready     = T100FALSE;
}

T100Bus64::~T100Bus64()
{
    //dtor
}

T100VOID T100Bus64::Pulse()
{

}

T100VOID T100Bus64::Plug(T100Device* device)
{

}

T100VOID T100Bus64::Unplug(T100Device* device)
{

}

T100VOID T100Bus64::PlugMemory(T100Memory64* memory)
{
    m_memory    = memory;
}

T100VOID T100Bus64::Ready()
{
    m_ready     = T100TRUE;
}

T100BOOL T100Bus64::IsBusy()
{
    return m_busy;
}

T100VOID T100Bus64::Acquire()
{
    m_memory->Acquire();
    m_busy  = T100TRUE;
}

T100BOOL T100Bus64::IsReady()
{
    return m_ready;
}

T100BOOL T100Bus64::Read(T100UINT64 offset, T100BYTE* data)
{
    T100BOOL    result;

    result  = m_memory->Read(offset, data);
    m_busy  = T100FALSE;

    return result;
}
