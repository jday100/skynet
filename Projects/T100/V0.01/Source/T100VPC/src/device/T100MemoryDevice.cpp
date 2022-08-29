#include "T100MemoryDevice.h"
#include "T100QU32.h"


T100MemoryDevice::T100MemoryDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100MemoryDevice::~T100MemoryDevice()
{
    //dtor
    destroy();
}

T100VOID T100MemoryDevice::create()
{
    m_port = m_host->getPort32();
    m_port->appendDevice(m_id, this);
}

T100VOID T100MemoryDevice::destroy()
{
    m_port->removeDevice(m_id);
}

T100BOOL T100MemoryDevice::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100MemoryDevice::unload()
{
    return T100TRUE;
}

T100BOOL T100MemoryDevice::in(T100WORD offset, T100WORD& value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    value = m_data[offset];

    return T100TRUE;
}

T100BOOL T100MemoryDevice::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    switch(offset){
    case 0:
        {
            m_data[0] = value;

            switch(value){
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_MEMORY;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100MEMORYMODE_ROM:
                {
                    m_data[1] = m_host->getMemory32()->m_rom_base;
                    m_data[2] = m_host->getMemory32()->m_rom_length;
                    m_data[3] = 32;
                }
                break;
            case T100MEMORYMODE_RAM:
                {
                    m_data[1] = m_host->getMemory32()->m_ram_base;
                    m_data[2] = m_host->getMemory32()->m_ram_length;
                    m_data[3] = 32;
                }
                break;
            }
        }
        break;
    default:
        m_data[offset] = value;
    }

    return T100TRUE;
}
