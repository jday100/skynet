#ifndef T100MEMORYINFO_H
#define T100MEMORYINFO_H

#include "T100DeviceInfo.h"

namespace T100VPC{

class T100MemoryInfo : public T100DeviceInfo
{
    public:
        T100MemoryInfo();
        virtual ~T100MemoryInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100MemoryInfo*);
        T100BOOL            remove(T100MemoryInfo*);
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

#endif // T100MEMORYINFO_H
