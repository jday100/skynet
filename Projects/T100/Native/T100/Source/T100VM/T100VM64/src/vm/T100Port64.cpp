#include "T100Port64.h"

T100Port64::T100Port64(T100Bus64* bus)
    :m_bus(bus)
{
    //ctor
    m_bus->setPort(this);
}

T100Port64::~T100Port64()
{
    //dtor
}
