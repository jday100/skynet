#ifndef T100VDISKSERVE_H
#define T100VDISKSERVE_H

#include "T100VDiskCommon.h"
#include "T100VDisk.h"


class T100VDiskServe
{
    public:
        T100VDiskServe();
        virtual ~T100VDiskServe();

        T100BOOL            createVDisk(T100String, T100DWORD);
        T100BOOL            openVDisk(T100String);
        T100BOOL            saveVDisk();
        T100BOOL            closeVDisk();

        T100VDisk*          getVDisk();

    protected:
        T100VDisk*          m_vdisk         = T100NULL;

    private:
};

#endif // T100VDISKSERVE_H
