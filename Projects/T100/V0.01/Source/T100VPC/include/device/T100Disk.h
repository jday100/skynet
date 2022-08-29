#ifndef T100DISK_H
#define T100DISK_H

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
        T100Disk(T100QU32*);
        virtual ~T100Disk();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

        T100BOOL            in(T100WORD, T100WORD&);
        T100BOOL            out(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            read(T100DWORD, T100WORD);
        T100BOOL            write(T100DWORD, T100WORD);

    private:
        T100VDisk*          m_vdisk         = T100NULL;

};

#endif // T100DISK_H
