#ifndef T100VFSDIRECTORY_H
#define T100VFSDIRECTORY_H

#include "T100VFS.h"


class T100VFSDirectory
{
    friend class T100VFSItem;
    friend class T100VFSFile;
    public:
        T100VFSDirectory(T100VFS*);
        virtual ~T100VFSDirectory();

        T100BOOL            setPart(T100VFS_PART*);

        T100BOOL            mkdir(T100String);
        T100BOOL            chdir(T100String);
        T100BOOL            rmdir(T100String);

        T100BOOL            split(T100String, T100String&, T100String&);
        T100BOOL            isdir(T100String);

        T100BOOL            search(T100String, T100VFS_ITEM_HANDLE&);
        T100BOOL            search(T100DWORD, T100String, T100VFS_ITEM_HANDLE&);
        T100BOOL            list(T100String);

    protected:
        T100DWORD           m_root          = 0;
        T100DWORD           m_current       = 0;

    private:
        T100VFS*            m_vfs           = T100NULL;

};

#endif // T100VFSDIRECTORY_H
