#include "T100Device.h"

T100Device::T100Device()
{
    //ctor
}

T100Device::~T100Device()
{
    //dtor
}

T100VOID T100Device::SetBus(T100Bus* bus)
{
    m_bus       = bus;
}

T100Bus* T100Device::GetBus()
{
    return m_bus;
}
