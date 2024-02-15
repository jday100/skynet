#include "T100Memory64.h"

T100Memory64::T100Memory64(T100Bus64* bus, INT64 length)
    :m_bus(bus), m_length(length)
{
    //ctor
    m_bus->setMemory(this);

    m_buffer[m_length];
}

T100Memory64::~T100Memory64()
{
    //dtor
}

T100VOID T100Memory64::read(INT64 offset, INT64& data)
{

}

T100VOID T100Memory64::write(INT64 offset, INT64 data)
{

}
