#ifndef T100DISKINFO_H
#define T100DISKINFO_H

#include "T100DeviceInfo.h"
#include "T100VPCDiskSetupDialog.h"

namespace T100VPC{

class T100DiskInfo : public T100DeviceInfo
{
    public:
        T100DiskInfo();
        virtual ~T100DiskInfo();

        T100DWORD           length          = 0;

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100DiskInfo*);
        T100BOOL            remove(T100DiskInfo*);
        T100BOOL            getDeviceInfos(T100DEVICE_INFO_VECTOR&);

        T100BOOL            setup();

    protected:
        T100BOOL            append(T100DeviceInfo*);
        T100BOOL            remove(T100DeviceInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100VPCDiskSetupDialog*         m_setup         = T100NULL;

};

}

#endif // T100DISKINFO_H
