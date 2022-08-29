#include "T100Memory32.h"

#include "T100String.h"
#include "T100QU32Setup.h"
#include "T100QU32.h"


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
    m_rom.resize(T100QU32Setup::m_rom_size);
    m_ram.resize(T100QU32Setup::m_ram_size);
}

T100VOID T100Memory32::destroy()
{
    m_rom.clear();
    m_ram.clear();
}

T100BOOL T100Memory32::read(T100WORD offset, T100WORD& value)
{
    T100WORD    base   = 0;

    if(m_host){
        base = m_host->getCU32()->getCBR();
    }

    return raw_read(base, offset, value);
}

T100BOOL T100Memory32::write(T100WORD offset, T100WORD value)
{
    T100WORD    base    = 0;

    if(m_host){
        base = m_host->getCU32()->getCBR();
    }

    return raw_write(base, offset, value);
}

T100BOOL T100Memory32::raw_read(T100WORD base, T100WORD offset, T100WORD& value)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            os;

    if(offset >= m_ram_limit){
        result = T100FALSE;
    }else if(offset >= m_rom_limit){
        if(offset < m_ram_base){
            result = T100FALSE;
        }else{
            os = offset = m_ram_base;
            if(os >= m_ram_length){
                result = T100FALSE;
            }else{
                value = m_ram[os];
            }
        }
    }else{
        if(offset < m_rom_base){
            result = T100FALSE;
        }else{
            os = offset - m_rom_base;
            if(os >= m_rom_length){
                result = T100FALSE;
            }else{
                value = m_rom[os];
            }
        }
    }

    return result;
}

T100BOOL T100Memory32::raw_write(T100WORD base, T100WORD offset, T100WORD value)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            os;

    if(offset >= m_ram_limit){
        result = T100FALSE;
    }else if(offset >= m_rom_limit){
        if(offset < m_ram_base){
            result = T100FALSE;
        }else{
            os = offset - m_ram_base;
            if(os >= m_ram_length){
                result = T100FALSE;
            }else{
                m_ram[os] = value;
            }
        }
    }else{
        /*ROM OR FLASH?*/
        if(offset < m_rom_base){
            result = T100FALSE;
        }else{
            os = offset - m_rom_base;
            if(os >= m_rom_length){
                result = T100FALSE;
            }else{
                m_rom[os] = value;
            }
        }
    }

    return result;
}

T100BOOL T100Memory32::load(T100STRING file, T100WORD location, T100WORD length)
{

}
