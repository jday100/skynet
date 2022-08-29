#ifndef T100AUDEVICEINFO_H
#define T100AUDEVICEINFO_H

#include "T100DeviceInfo.h"


class T100AUDeviceInfo : public T100DeviceInfo
{
    public:
        T100AUDeviceInfo();
        virtual ~T100AUDeviceInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100AUDEVICEINFO_H
