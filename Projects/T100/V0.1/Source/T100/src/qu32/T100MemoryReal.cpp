#include "T100MemoryReal.h"

#include "T100QU32Setup.h"
#include "T100QU32.h"
#include "T100FileTools.h"


namespace T100QU32{

T100MemoryReal::T100MemoryReal(T100QU32* host)
    :T100MemoryBase(host)
{
    //ctor
    create();
}

T100MemoryReal::~T100MemoryReal()
{
    //dtor
    destroy();
}

T100VOID T100MemoryReal::create()
{
    m_rom_base      = T100QU32Setup::getRomBase();
    m_rom_length    = T100QU32Setup::getRomSize();
    m_rom_limit     = m_rom_base + m_rom_length;

    m_ram_base      = T100QU32Setup::getRamBase();
    m_ram_length    = T100QU32Setup::getRamSize();
    m_ram_limit     = m_ram_base + m_ram_length;

    m_rom.resize(m_rom_length);
    m_ram.resize(m_ram_length);
}

T100VOID T100MemoryReal::destroy()
{
    m_rom.clear();
    m_ram.clear();
}

T100BOOL T100MemoryReal::read(T100WORD offset, T100WORD& value)
{
    T100WORD    base    = 0;

    if(getHost()){
        base    = getHost()->getCU32()->getCBR();
    }else{
        return T100FALSE;
    }
    return raw_read(base, offset, value);
}

T100BOOL T100MemoryReal::write(T100WORD offset, T100WORD value)
{
    T100WORD    base    = 0;

    if(getHost()){
        base    = getHost()->getCU32()->getCBR();
    }else{
        return T100FALSE;
    }
    return raw_write(base, offset, value);
}

T100BOOL T100MemoryReal::raw_read(T100WORD base, T100WORD offset, T100WORD& value)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        index;
    T100WORD        os;

    index = base + offset;

    if(index >= m_ram_limit){
        result = T100FALSE;
    }else if(index >= m_rom_limit){
        if(index < m_ram_base){
            result = T100FALSE;
        }else{
            os = index - m_ram_base;
            if(os >= m_ram_length){
                result = T100FALSE;
            }else{
                value = m_ram[os];
            }
        }
    }else{
        if(index < m_rom_base){
            result = T100FALSE;
        }else{
            os = index - m_rom_base;
            if(os >= m_rom_length){
                result = T100FALSE;
            }else{
                value = m_rom[os];
            }
        }
    }
    return result;
}

T100BOOL T100MemoryReal::raw_write(T100WORD base, T100WORD offset, T100WORD value)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        index;
    T100WORD        os;

    index = base + offset;

    if(index >= m_ram_limit){
        result = T100FALSE;
    }else if(index >= m_rom_limit){
        if(index < m_ram_base){
            result = T100FALSE;
        }else{
            os = index - m_ram_base;
            if(os >= m_ram_length){
                result = T100FALSE;
            }else{
                m_ram[os] = value;
                notify(index, value);
            }
        }
    }else{
        /*ROM OR FLASH?*/
        if(index < m_rom_base){
            result = T100FALSE;
        }else{
            os = index - m_rom_base;
            if(os >= m_rom_length){
                result = T100FALSE;
            }else{
                m_rom[os] = value;
                notify(index, value);
            }
        }
    }
    return result;
}

T100BOOL T100MemoryReal::load(T100STRING file, T100WORD location)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        value;

    if(location >= m_ram_base){
        value   = location - m_ram_base;
        result  = T100Library::T100FileTools::load(file.to_wstring(), m_ram, value);
    }else if(location >= m_rom_base){
        value   = location - m_rom_base;
        result  = T100Library::T100FileTools::load(file.to_wstring(), m_rom, value);
    }else{
        return T100FALSE;
    }
    return result;
}

T100BOOL T100MemoryReal::notify(T100WORD offset, T100WORD value)
{
    T100BOOL        result          = T100TRUE;

    if(T100QU32Setup::DEBUG){
        if(offset >= T100QU32Setup::MEMORY_WINDOW_BEGIN
           && offset <= T100QU32Setup::MEMORY_WINDOW_END){
            getHost()->getNotifier().notify_memory_update(offset, value);
        }
    }
    return result;
}

}
