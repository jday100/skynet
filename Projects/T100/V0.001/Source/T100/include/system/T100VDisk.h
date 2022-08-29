#ifndef T100VDISK_H
#define T100VDISK_H

#include "T100VDiskCommon.h"
#include "T100VFS.h"
#include "T100VDiskFile.h"
#include "T100VDiskPart.h"



class T100VDisk
{
    public:
        T100VDisk(T100STDSTRING);
        virtual ~T100VDisk();

        virtual T100BOOL        exists();
        virtual T100DWORD       length();

        virtual T100BOOL        create(T100DWORD);
        virtual T100BOOL        remove();


        virtual T100BOOL        open();
        virtual T100BOOL        close();

        virtual T100BOOL        read(T100DWORD, T100WORD*);
        virtual T100BOOL        write(T100DWORD, T100WORD*);

        virtual T100BOOL        part_create(T100STDSTRING, T100DWORD, T100DWORD, T100BOOL);
        virtual T100BOOL        part_remove(T100STDSTRING);
        virtual T100BOOL        part_list(T100VFS_PART_VECTOR&);
        virtual T100BOOL        part_boot(T100STDSTRING, T100BOOL);

        virtual T100BOOL        fs_format(T100STDSTRING);
        virtual T100BOOL        fs_format(T100STDSTRING, T100STDSTRING);

        virtual T100BOOL        fs_mkdir(T100STDSTRING, T100STDSTRING);
        virtual T100BOOL        fs_chdir(T100STDSTRING, T100STDSTRING);
        virtual T100BOOL        fs_rmdir(T100STDSTRING, T100STDSTRING);

        virtual T100BOOL        fs_create(T100STDSTRING, T100STDSTRING);
        virtual T100BOOL        fs_remove(T100STDSTRING, T100STDSTRING);

        virtual T100BOOL        fs_list(T100STDSTRING, T100STDSTRING);
        virtual T100BOOL        fs_copy(T100STDSTRING, T100STDSTRING, T100STDSTRING);


    protected:
        T100VOID                create(T100STDSTRING);
        T100VOID                destroy();

        virtual T100BOOL        load();

    private:
        T100VDiskFile*          m_file          = T100NULL;
        T100VDiskPart*          m_part          = T100NULL;
        T100VFS*                m_vfs           = T100NULL;

};

#endif // T100VDISK_H
