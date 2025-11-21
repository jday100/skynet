#include "T100Generator64.h"

#include <profileapi.h>
#include "T100Host64.h"

T100Generator64::T100Generator64(T100Host64* host) :
    m_host(host)
{
    //ctor
    m_previous  = 0;
}

T100Generator64::~T100Generator64()
{
    //dtor
}

T100VOID T100Generator64::SetFrequency(T100UINT value)
{
    m_frequency     = value;
    m_delay         = 1000 * 1000 * 1000 / m_frequency;

    if(QueryPerformanceFrequency(&m_hardFrequency)){

    }
}

T100VOID T100Generator64::Start()
{

}

T100VOID T100Generator64::Stop()
{

}

T100VOID T100Generator64::Pulse()
{
    LARGE_INTEGER       current;
    T100UINT64          value;

    if(QueryPerformanceCounter(&current)){
        value       = (current.QuadPart - m_before.QuadPart) * 1000000 / m_hardFrequency.QuadPart;

        m_before    = current;
    }
    m_host->Pulse();
}
