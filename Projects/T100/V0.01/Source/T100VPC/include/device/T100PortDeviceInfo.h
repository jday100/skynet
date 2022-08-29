#ifndef T100PORTDEVICEINFO_H
#define T100PORTDEVICEINFO_H

#include "T100DeviceInfo.h"


class T100PortDeviceInfo : public T100DeviceInfo
{
    public:
        T100PortDeviceInfo();
        virtual ~T100PortDeviceInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100PORTDEVICEINFO_H
