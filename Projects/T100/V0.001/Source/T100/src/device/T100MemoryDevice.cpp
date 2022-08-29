#include "T100MemoryDevice.h"

#include "T100HintQU32.h"
#include "T100QU32.h"


T100MemoryDevice::T100MemoryDevice(IComputer* host)
    :m_host(host)
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
    T100Log::trace(T100DEVICE_HINT_MEMORY_DEVICE_LOAD);

    m_manager = m_host->getManager();
    m_manager->addDevice(m_id, this);
}

T100VOID T100MemoryDevice::destroy()
{
    m_manager->removeDevice(m_id);

    T100Log::trace(T100DEVICE_HINT_MEMORY_DEVICE_UNLOAD);
}

T100WORD T100MemoryDevice::in(T100WORD offset)
{
    T100WORD result = 0;

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

T100VOID T100MemoryDevice::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return;

    switch(offset){
    case 0:
        {
            switch(value)
            {
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_MEMORY;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100MEMORYMODE_ROM:
                {
                    m_data[1] = m_host->getMemory()->m_rom_base;
                    m_data[2] = m_host->getMemory()->m_rom_size;
                    m_data[3] = 32;
                }
                break;
            case T100MEMORYMODE_RAM:
                {
                    m_data[1] = m_host->getMemory()->m_ram_base;
                    m_data[2] = m_host->getMemory()->m_ram_size;
                    m_data[3] = 32;
                }
                break;
            };
        }
        break;
    default:
        m_data[offset] = value;
    };
}
