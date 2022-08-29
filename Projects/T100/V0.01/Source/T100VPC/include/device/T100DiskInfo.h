#ifndef T100DISKINFO_H
#define T100DISKINFO_H

#include "T100DeviceInfo.h"


class T100DiskInfo : public T100DeviceInfo
{
    public:
        T100DiskInfo();
        virtual ~T100DiskInfo();

        T100DWORD           length          = 0;

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100DISKINFO_H
