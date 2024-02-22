#ifndef T100VDISK_H
#define T100VDISK_H

#include "T100Common.h"
#include "T100VDISKCommon.h"

#include "T100WXRunThread.h"


class T100VDisk
{
    public:
        T100VDisk(T100STRING, T100INT64);
        virtual ~T100VDisk();

        T100BOOL                create(T100VDISK_TYPE, T100VDISK_STORAGE_TYPE);

        T100VOID                setValue(T100VOID*);
        T100VOID                setCreateCallback(T100THREAD_CALLBACK);

    protected:
        T100VOID*               m_value             = T100NULL;
        T100THREAD_CALLBACK     m_callback          = T100NULL;
    private:
        T100STRING              m_filename;
        T100INT64               m_length;
};

#endif // T100VDISK_H
