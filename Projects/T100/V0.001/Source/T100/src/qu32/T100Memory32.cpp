#include "T100Memory32.h"

#include "T100FileTools.h"
#include "T100QU32Callback.h"
#include "T100QU32.h"


T100Memory32::T100Memory32(T100QU32* host, T100WORD rom_length, T100WORD ram_length)
    :m_host(host), m_rom_length(rom_length), m_ram_length(ram_length),
    IMemory((IComputer*)host, rom_length, ram_length)
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
    m_rom.resize(m_rom_length);
    m_ram.resize(m_ram_length);
}

T100VOID T100Memory32::destroy()
{
    m_rom.clear();
    m_ram.clear();
}

T100VOID T100Memory32::write(T100WORD offset, T100WORD value)
{
    T100WORD    base    = 0;

    if(m_host){
        base = m_host->getCU()->getCBR();
    }
    raw_write(base + offset, value);
}

T100WORD T100Memory32::read(T100WORD offset)
{
    T100WORD    base    = 0;

    if(m_host){
        base = m_host->getCU()->getCBR();
    }
    return raw_read(base + offset);
}

T100VOID T100Memory32::write(T100WORD base, T100WORD offset, T100WORD value)
{
    T100WORD    result;

    result = base + offset;

    raw_write(result, value);
}

T100WORD T100Memory32::read(T100WORD base, T100WORD offset)
{
    T100WORD    result;

    result = base + offset;

    return raw_read(result);
}

T100VOID T100Memory32::raw_write(T100WORD offset, T100WORD value)
{
    T100WORD os;

    if(offset >= m_ram_limit){
        //error
    }else if(offset >= m_rom_limit){
        if(offset < m_ram_base){
            //error
        }else{
            os = offset - m_ram_base;
            if(os >= m_ram_length){
                //error
            }else{
                m_ram[os] = value;

                if(T100QU32Setup::DEBUG
                   && EXECUTOR_MODE_STEP == m_host->getExecutor32()->m_mode){
                    T100QU32Callback::callDebugRam();
                }

                if(m_ram_window){
                    if(offset >= m_ram_window_begin && offset <= m_ram_window_end){
                        if(T100QU32Setup::DEBUG
                           && EXECUTOR_MODE_STEP == m_host->getExecutor32()->m_mode){
                            T100QU32Callback::callDebugRam();
                        }
                    }
                }
            }
        }
    }else{
        /*ROM OR FLASH?*/
        if(offset < m_rom_base){
            //error
        }else{
            os = offset - m_rom_base;
            if(os >= m_rom_length){
                //error
            }else{
                m_rom[os] = value;
            }
        }
    }
}

T100WORD T100Memory32::raw_read(T100WORD offset)
{
    T100WORD    os;

    if(offset >= m_ram_limit){
        //error
    }else if(offset >= m_rom_limit){
        if(offset < m_ram_base){
            //error
        }else{
            os = offset - m_ram_base;
            if(os >= m_ram_length){
                //error
            }else{
                return m_ram[os];
            }
        }
    }else{
        if(offset < m_rom_base){
            //error
        }else{
            os = offset - m_rom_base;
            if(os >= m_rom_length){
                //error
            }else{
                return m_rom[os];
            }
        }
    }
    return 0;
}

T100BOOL T100Memory32::load(T100String file, T100WORD offset)
{
    T100BOOL    result      = T100FALSE;
    T100WORD    value;

    if(offset >= m_ram_base){
        value = offset - m_ram_base;
        result = T100FileTools::load(file, m_ram, value);
    }else if(offset >= m_rom_base){
        value = offset - m_rom_base;
        result = T100FileTools::load(file, m_rom, value);
    }else{
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Memory32::load(T100WORD_VECTOR& app, T100WORD offset)
{
    for(auto value : app){
        raw_write(offset++, value);
    }

    return T100TRUE;
}

T100BOOL T100Memory32::open(T100WORD begin, T100WORD end)
{
    T100BOOL    result      = T100FALSE;

    if(begin < m_ram_base || begin > (m_ram_base + m_ram_length)){
        return T100FALSE;
    }

    if(end < begin || end < m_ram_base || end > (m_ram_base + m_ram_length)){
        return T100FALSE;
    }
    m_ram_window_begin  = begin;
    m_ram_window_end    = end;
    m_ram_window        = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Memory32::close()
{
    if(!m_ram_window){
        return T100FALSE;
    }

    m_ram_window_begin  = 0;
    m_ram_window_end    = 0;

    m_ram_window        = T100FALSE;

    return T100TRUE;
}
