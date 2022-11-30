#include "T100MemoryVirtaul.h"

#include "T100QU32.h"
#include "T100Gdt32.h"

namespace T100QU32{

T100MemoryVirtaul::T100MemoryVirtaul(T100QU32* host)
    :T100MemoryBase(host)
{
    //ctor
    create();
}

T100MemoryVirtaul::~T100MemoryVirtaul()
{
    //dtor
    destroy();
}

T100VOID T100MemoryVirtaul::create()
{
    m_memory    = getHost()->getMemory32()->getMemory();
    m_gdt       = getHost()->getGdt32();
}

T100VOID T100MemoryVirtaul::destroy()
{

}

T100BOOL T100MemoryVirtaul::read(T100WORD offset, T100WORD& value)
{
    return m_memory->read(offset, value);
}

T100BOOL T100MemoryVirtaul::write(T100WORD offset, T100WORD value)
{
    return m_memory->write(offset, value);
}

T100BOOL T100MemoryVirtaul::raw_read(T100WORD base, T100WORD offset, T100WORD& value)
{
    T100BOOL        result          = T100FALSE;

    T100WORD        index;
    T100WORD        os;
    T100WORD        total;

    //test
    index   = 1;

    m_gdt->getEntry(index, os);

    total = os + offset;

    return m_memory->raw_read(0, total, value);
}

T100BOOL T100MemoryVirtaul::raw_write(T100WORD base, T100WORD offset, T100WORD value)
{
    return m_memory->raw_write(base, offset, value);
}

}
