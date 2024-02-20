#ifndef T100VDISK_H
#define T100VDISK_H

#include "T100Common.h"
#include "T100VDISKCommon.h"


class T100VDisk
{
    public:
        T100VDisk(T100STRING, T100INT64);
        virtual ~T100VDisk();

        T100BOOL            create(T100VDISK_TYPE, T100VDISK_STORAGE_TYPE);

    protected:

    private:
        T100STRING          m_filename;
        T100INT64           m_length;
};

#endif // T100VDISK_H
