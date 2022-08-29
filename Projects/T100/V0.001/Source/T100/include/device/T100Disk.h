#ifndef T100DISK_H
#define T100DISK_H

#include "T100Common.h"
#include "T100BlockDevice.h"
#include "T100VDisk.h"


enum T100DISK_MODE{
    T100DISKMODE_NONE           = T100DEVICEMODE_MAX,
    T100DISKMODE_TYPE,
    T100DISKMODE_SET,
    T100DISKMODE_GET,
    T100DISKMODE_BLOCK,
    T100DISKMODE_FORMAT,
    T100DISKMODE_CLEAR,
    T100DISKMODE_READ,
    T100DISKMODE_WRITE,
    T100DISKMODE_MAX
};


class T100Disk : public T100BlockDevice
{
    public:
        T100Disk(T100String);
        virtual ~T100Disk();

        virtual T100BOOL        load(IManager*);
        T100BOOL                isInited();

        T100BOOL                load(T100Manager32*);
        T100BYTE*               getData();

        T100WORD                in(T100WORD);
        T100VOID                out(T100WORD, T100WORD);

        T100WORD                in(T100WORD, T100WORD);
        T100VOID                out(T100WORD, T100WORD, T100WORD);

    protected:
        T100VOID                create(T100String);
        T100VOID                destroy();

        T100BOOL                read(T100DWORD, T100WORD);
        T100BOOL                write(T100DWORD, T100WORD);

    private:
        T100WORD                m_buffer[1024 * 16];
        T100DWORD               m_id            = 0;
        T100VDisk*              m_vdisk         = T100NULL;
        T100BOOL                m_inited        = T100FALSE;
        T100BOOL                m_readed        = T100FALSE;
};

#endif // T100DISK_H
