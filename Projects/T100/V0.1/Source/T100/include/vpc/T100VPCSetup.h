#ifndef T100VPCSETUP_H
#define T100VPCSETUP_H

#include "T100VPCCommon.h"
#include "T100QU32Setup.h"
#include "T100DeviceInfo.h"

namespace T100VPC{

class T100VPCSetup : public T100QU32::T100QU32Setup
{
    friend class T100MemoryInfo;
    public:
        T100VPCSetup();
        virtual ~T100VPCSetup();

        static T100BOOL                     initDevices();
        static T100BOOL                     appendDevice(T100DeviceInfo*);
        static T100BOOL                     removeDevice(T100DeviceInfo*);
        static T100DEVICE_INFO_VECTOR&      getDevices();

        static T100STRING                   getVDiskFile();
        static T100STRING                   getFontFile();

        static T100STRING                   getRomFile();

        static T100WORD                     getRamBase();
        static T100WORD                     getRamSize();
        static T100WORD                     getRomBase();
        static T100WORD                     getRomSize();

    protected:
        static T100VOID                     setVDiskFile(T100STRING);
        static T100VOID                     setFontFile(T100STRING);

        static T100VOID                     setRomFile(T100STRING);

        static T100VOID                     setRamBase(T100WORD);
        static T100VOID                     setRamSize(T100WORD);
        static T100VOID                     setRomBase(T100WORD);
        static T100VOID                     setRomSize(T100WORD);

    private:
        static T100STRING                   m_vdisk_file;
        static T100STRING                   m_font_file;

        static T100STRING                   m_rom_file;

        static T100WORD                     m_ram_base;
        static T100WORD                     m_ram_size;
        static T100WORD                     m_rom_base;
        static T100WORD                     m_rom_size;

        static T100DEVICE_INFO_VECTOR       m_devices;

};

}

#endif // T100VPCSETUP_H
