#include "T100Memory32.h"

#include "T100String.h"
#include "T100QU32Setup.h"
#include "T100QU32.h"
#include "T100FileTools.h"


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
    m_rom_base      = T100QU32Setup::getRomBase();
    m_rom_length    = T100QU32Setup::getRomSize();
    m_rom_limit     = m_rom_base + m_rom_length;

    m_ram_base      = T100QU32Setup::getRamBase();
    m_ram_length    = T100QU32Setup::getRamSize();
    m_ram_limit     = m_ram_base + m_ram_length;

    m_rom.resize(m_rom_length);
    m_ram.resize(m_ram_length);
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

T100BOOL T100Memory32::raw_read(T100WORD base, T100WORD temp, T100WORD& value)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            offset;
    T100WORD            os;

    offset = base + temp;

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

T100BOOL T100Memory32::raw_write(T100WORD base, T100WORD temp, T100WORD value)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            offset;
    T100WORD            os;

    offset = base + temp;

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
                notify(offset, value);
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
                notify(offset, value);
            }
        }
    }

    return result;
}

T100BOOL T100Memory32::load(T100STRING file, T100WORD location)
{
    T100BOOL        result      = T100FALSE;
    T100WORD        value;

    if(location >= m_ram_base){
        value = location - m_ram_base;
        result = T100FileTools::load(file.to_wstring(), m_ram, value);
    }else if(location >= m_rom_base){
        value = location - m_rom_base;
        result = T100FileTools::load(file.to_wstring(), m_rom, value);
    }else{
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Memory32::notify(T100WORD offset, T100WORD value)
{
    T100BOOL            result          = T100TRUE;

    if(T100QU32Setup::DEBUG){
        if(offset >= T100QU32Setup::MEMORY_WINDOW_BEGIN && offset <= T100QU32Setup::MEMORY_WINDOW_END){
            //m_host->getCallback()->notify_memory_update(offset, value);
            m_host->getNotifier().notify_memory_update(offset, value);
        }
        //if(offset >= T100QU32Setup::PORT_WINDOW_BEGIN && offset <= T100QU32Setup::PORT_WINDOW_END){
            //m_host->getCallback()->notify_port_update(offset, value);
        //}
    }

    return result;
}
