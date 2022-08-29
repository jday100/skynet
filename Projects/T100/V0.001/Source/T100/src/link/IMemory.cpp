#include "IMemory.h"

IMemory::IMemory(IComputer* host, T100WORD rom_size, T100WORD ram_size)
    :m_host(host)
{
    //ctor
}

IMemory::~IMemory()
{
    //dtor
}
