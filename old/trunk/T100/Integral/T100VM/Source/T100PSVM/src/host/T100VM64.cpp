#include "T100VM64.h"

T100VM64::T100VM64() :
    m_host()
{
    //ctor
}

T100VM64::~T100VM64()
{
    //dtor
}

T100BOOL T100VM64::Start()
{
    m_host.Start();
}

T100BOOL T100VM64::Stop()
{
    m_host.Stop();
}

T100VOID T100VM64::Debug()
{
    m_host.Debug();
}

T100VOID T100VM64::Step()
{
    m_host.Step();
}

T100VOID T100VM64::Info(T100DebugFrame* frame)
{
    m_host.Info(frame);
}
