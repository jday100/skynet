#ifndef T100MEMORYINFO_H
#define T100MEMORYINFO_H

#include "T100DeviceInfo.h"


class T100MemoryInfo : public T100DeviceInfo
{
    public:
        T100MemoryInfo();
        virtual ~T100MemoryInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100MEMORYINFO_H
