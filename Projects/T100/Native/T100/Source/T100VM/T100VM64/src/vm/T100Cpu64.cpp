#include "T100Cpu64.h"

T100Cpu64::T100Cpu64(T100Bus64* bus)
    :m_bus(bus)
{
    //ctor
    m_bus->setCpu(this);
}

T100Cpu64::~T100Cpu64()
{
    //dtor
}

T100BOOL T100Cpu64::run()
{
    INT64           order;

    m_bus->read(T100BUS_SELECT_MEMORY, CS.DATA.DATA, order);
    return T100FALSE;
}
