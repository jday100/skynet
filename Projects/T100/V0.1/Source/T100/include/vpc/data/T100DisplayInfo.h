#ifndef T100DISPLAYINFO_H
#define T100DISPLAYINFO_H

#include "T100DeviceInfo.h"

namespace T100VPC{

class T100DisplayInfo : public T100DeviceInfo
{
    public:
        T100DisplayInfo();
        virtual ~T100DisplayInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100DisplayInfo*);
        T100BOOL            remove(T100DisplayInfo*);
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

#endif // T100DISPLAYINFO_H
