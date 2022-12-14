#ifndef T100VDISK_H
#define T100VDISK_H

#include "T100DiskCommon.h"
#include "T100VDiskCommon.h"
#include "T100VFS.h"
#include "T100VDiskFile.h"
#include "T100VDiskPart.h"


namespace T100Component{

class T100VDisk
{
    public:
        T100VDisk(T100STRING);
        virtual ~T100VDisk();

        virtual T100BOOL            exists();
        virtual T100DWORD           length();
        virtual T100DWORD           cluster_length();

        virtual T100BOOL            create(T100DWORD);
        virtual T100BOOL            remove();

        virtual T100BOOL            open();
        virtual T100BOOL            close();
        virtual T100BOOL            opened();

        virtual T100BOOL            read(T100DWORD, T100WORD*);
        virtual T100BOOL            write(T100DWORD, T100WORD*);

        virtual T100BOOL            part_create(T100STRING, T100DWORD, T100DWORD, T100BOOL);
        virtual T100BOOL            part_remove(T100STRING);
        virtual T100BOOL            part_list(T100VFS_PART_VECTOR&);
        virtual T100BOOL            part_boot(T100STRING, T100BOOL);

        virtual T100BOOL            fs_format(T100STRING);
        virtual T100BOOL            fs_format(T100STRING, T100STRING);

        virtual T100BOOL            fs_mkdir(T100STRING, T100STRING);
        virtual T100BOOL            fs_chdir(T100STRING, T100STRING);
        virtual T100BOOL            fs_rmdir(T100STRING, T100STRING);

        virtual T100BOOL            fs_create(T100STRING, T100STRING);
        virtual T100BOOL            fs_remove(T100STRING, T100STRING);

        virtual T100BOOL            fs_list(T100STRING, T100STRING, T100DISK_ITEM_VECTOR&);
        virtual T100BOOL            fs_copy(T100STRING, T100STRING, T100STRING);


    protected:
        T100VOID                    create(T100STRING);
        T100VOID                    destroy();

        virtual T100BOOL            load();

    private:
        T100VDiskFile*              m_file          = T100NULL;
        T100VDiskPart*              m_part          = T100NULL;
        T100VFS*                    m_vfs           = T100NULL;

};

}

#endif // T100VDISK_H
