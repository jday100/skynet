#include "T100Counter64.h"

T100Counter64::T100Counter64(T100Host64* host) :
    m_host(host)
{
    //ctor
    m_count     = 0;
}

T100Counter64::~T100Counter64()
{
    //dtor
}

T100VOID T100Counter64::Pulse()
{
    m_count++;
}
