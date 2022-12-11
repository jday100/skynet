#ifndef T100CUDEVICEINFO_H
#define T100CUDEVICEINFO_H

#include "T100DeviceInfo.h"

namespace T100VPC{

class T100CUDeviceInfo : public T100DeviceInfo
{
    public:
        T100CUDeviceInfo();
        virtual ~T100CUDeviceInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100CUDeviceInfo*);
        T100BOOL            remove(T100CUDeviceInfo*);
        T100BOOL            getDeviceInfos(T100DEVICE_INFO_VECTOR&);

        T100BOOL            setup();

    protected:
        T100BOOL            append(T100DeviceInfo*);
        T100BOOL            remove(T100DeviceInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100CUDEVICEINFO_H
