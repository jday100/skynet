#include "T100Memory32.h"

#include "T100String.h"
#include "T100QU32Setup.h"
#include "T100QU32.h"
#include "T100FileTools.h"

namespace T100QU32{

T100Memory32::T100Memory32(T100QU32* host)
    :m_host(host)
{
    //ctor
    create();
}

T100Memory32::~T100Memory32()
{
    //dtor
    destroy();
}

T100VOID T100Memory32::create()
{
    m_real      = T100NEW T100MemoryReal(m_host);
    m_memory    = m_real;
}

T100VOID T100Memory32::destroy()
{
    T100SAFE_DELETE(m_virtual);
    T100SAFE_DELETE(m_real);
}

T100MemoryReal* T100Memory32::getMemory()
{
    return m_real;
}

T100BOOL T100Memory32::read(T100WORD offset, T100WORD& value)
{
    return m_memory->read(offset, value);
}

T100BOOL T100Memory32::write(T100WORD offset, T100WORD value)
{
    return m_memory->write(offset, value);
}

T100BOOL T100Memory32::raw_read(T100WORD base, T100WORD offset, T100WORD& value)
{
    return m_memory->raw_read(base, offset, value);
}

T100BOOL T100Memory32::raw_write(T100WORD base, T100WORD offset, T100WORD value)
{
    return m_memory->raw_write(base, offset, value);
}

T100BOOL T100Memory32::load(T100STRING file, T100WORD location)
{
    return m_real->load(file, location);
}

T100WORD T100Memory32::getRomBase()
{
    return m_real->m_rom_base;
}

T100WORD T100Memory32::getRomLength()
{
    return m_real->m_rom_length;
}

T100WORD T100Memory32::getRamBase()
{
    return m_real->m_ram_base;
}

T100WORD T100Memory32::getRamLength()
{
    return m_real->m_ram_length;
}

T100BOOL T100Memory32::enter()
{
    if(!m_virtual){
        m_virtual = T100NEW T100MemoryVirtaul(m_host);
    }

    m_memory = m_virtual;
    return T100TRUE;
}

T100BOOL T100Memory32::quit()
{
    m_memory = m_real;
    return T100TRUE;
}

}
