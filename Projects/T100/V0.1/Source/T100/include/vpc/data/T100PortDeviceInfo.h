#ifndef T100PORTDEVICEINFO_H
#define T100PORTDEVICEINFO_H

#include "T100DeviceInfo.h"

namespace T100VPC{

class T100PortDeviceInfo : public T100DeviceInfo
{
    public:
        T100PortDeviceInfo();
        virtual ~T100PortDeviceInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100PortDeviceInfo*);
        T100BOOL            remove(T100PortDeviceInfo*);
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

    private:
};

}

#endif // T100PORTDEVICEINFO_H
