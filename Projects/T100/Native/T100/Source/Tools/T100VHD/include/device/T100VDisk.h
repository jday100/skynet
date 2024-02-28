#ifndef T100VDISK_H
#define T100VDISK_H

#include "T100Common.h"
#include "T100VDISKCommon.h"

#include "T100WXRunThread.h"
#include "T100VHDBase.h"
#include "T100VDiskCallback.h"


class T100VDisk
{
    public:
        T100VDisk(T100STRING, T100INT64);
        virtual ~T100VDisk();

        T100BOOL                create(T100VDISK_TYPE, T100VDISK_STORAGE_TYPE);
        T100VOID                cancel();

        T100VOID                setValue(T100VOID*);
        T100VOID                setCallback(T100VDiskCallback*);

    protected:
        T100VOID*               m_value             = T100NULL;
        T100VDiskCallback*      m_callback          = T100NULL;
    private:
        T100STRING              m_filename;
        T100INT64               m_length;
        T100VHDBase*            m_base              = T100NULL;
};

#endif // T100VDISK_H
