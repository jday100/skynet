#ifndef T100MEMORYINFO_H
#define T100MEMORYINFO_H

#include "T100DeviceInfo.h"
#include "T100VPCMemorySetupDialog.h"


namespace T100VPC{

class T100MemoryInfo : public T100DeviceInfo
{
    friend class T100VPCMemorySetupDialog;
    public:
        T100MemoryInfo();
        virtual ~T100MemoryInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100MemoryInfo*);
        T100BOOL            remove(T100MemoryInfo*);
        T100BOOL            getDeviceInfos(T100DEVICE_INFO_VECTOR&);

        T100BOOL            setup();

        T100BOOL            insert(wxListView*);

    protected:
        T100VOID            init();

        T100BOOL            append(T100DeviceInfo*);
        T100BOOL            remove(T100DeviceInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100VPCMemorySetupDialog*       m_setup         = T100NULL;

    private:
        T100WORD            m_ram_base;
        T100WORD            m_ram_size;
        T100WORD            m_rom_base;
        T100WORD            m_rom_size;

};

}

#endif // T100MEMORYINFO_H
