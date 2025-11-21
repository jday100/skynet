#include "T100VMIntel64.h"

T100VMIntel64::T100VMIntel64() :
    T100VM(),
    m_host()
{
    //ctor
}

T100VMIntel64::~T100VMIntel64()
{
    //dtor
}

T100BOOL T100VMIntel64::Start()
{
    m_running   = T100TRUE;

    while(m_running){
        m_running   = m_host.Pulse();
    }
    return m_running;
}

T100BOOL T100VMIntel64::Stop()
{

}

T100VOID T100VMIntel64::Debug()
{
    m_running   = T100TRUE;

    m_running   = m_host.Pulse();
}

T100VOID T100VMIntel64::Step()
{
    if(m_running){
        m_running   = m_host.Pulse();
    }
}

T100VOID T100VMIntel64::Info(T100DebugFrame* frame)
{
    m_host.Info(frame);
}
