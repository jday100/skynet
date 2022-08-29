#include "T100VPCSetup.h"


T100DEVICE_INFO_VECTOR      T100VPCSetup::m_devices;
T100WSTRING                 T100VPCSetup::m_vdisk_file          = L"vdisk.vdk";
T100WSTRING                 T100VPCSetup::m_font_file           = L"font.fnt";
T100WSTRING                 T100VPCSetup::m_rom_file            = L"rom.bin";
T100WORD                    T100VPCSetup::m_ram_base            = 1024 * 1024 * 1024;
T100WORD                    T100VPCSetup::m_ram_size            = 1024 * 1024;
T100WORD                    T100VPCSetup::m_rom_base            = 0;
T100WORD                    T100VPCSetup::m_rom_size            = 1024 * 1024;


T100VPCSetup::T100VPCSetup()
{
    //ctor
}

T100VPCSetup::~T100VPCSetup()
{
    //dtor
}

T100BOOL T100VPCSetup::appendDevice(T100DeviceInfo* dev)
{
    for(T100DeviceInfo* item : m_devices){
        if(item){
            if(dev == item){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    m_devices.push_back(dev);
    return T100TRUE;
}

T100BOOL T100VPCSetup::removeDevice(T100DeviceInfo* dev)
{
    T100DEVICE_INFO_VECTOR::iterator     it;

    for(it = m_devices.begin();it != m_devices.end();it++){
        if(dev == (*it)){
            m_devices.erase(it);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100DEVICE_INFO_VECTOR& T100VPCSetup::getDevices()
{
    return m_devices;
}

T100VOID T100VPCSetup::setVDiskFile(T100WSTRING file)
{
    m_vdisk_file = file;
}

T100WSTRING T100VPCSetup::getVDiskFile()
{
    return m_vdisk_file;
}

T100VOID T100VPCSetup::setFontFile(T100WSTRING file)
{
    m_font_file = file;
}

T100WSTRING T100VPCSetup::getFontFile()
{
    return m_font_file;
}

T100VOID T100VPCSetup::setRomFile(T100WSTRING file)
{
    m_rom_file = file;
}

T100WSTRING T100VPCSetup::getRomFile()
{
    return m_rom_file;
}

T100VOID T100VPCSetup::setRamBase(T100WORD value)
{
    //m_ram_base = value;
}

T100WORD T100VPCSetup::getRamBase()
{
    return m_ram_base;
}

T100VOID T100VPCSetup::setRamSize(T100WORD value)
{
    m_ram_size = value;
}

T100WORD T100VPCSetup::getRamSize()
{
    return m_ram_size;
}

T100VOID T100VPCSetup::setRomBase(T100WORD value)
{
    m_rom_base = value;
}

T100WORD T100VPCSetup::getRomBase()
{
    return m_rom_base;
}

T100VOID T100VPCSetup::setRomSize(T100WORD value)
{
    m_rom_size = value;
}

T100WORD T100VPCSetup::getRomSize()
{
    return m_rom_size;
}


