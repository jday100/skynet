#ifndef T100CUDEVICEINFO_H
#define T100CUDEVICEINFO_H

#include "T100DeviceInfo.h"


class T100CUDeviceInfo : public T100DeviceInfo
{
    public:
        T100CUDeviceInfo();
        virtual ~T100CUDeviceInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100CUDEVICEINFO_H
