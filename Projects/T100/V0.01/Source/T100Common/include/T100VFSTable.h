#ifndef T100VFSTABLE_H
#define T100VFSTABLE_H

#include "T100Common.h"
#include "T100VFS.h"


class T100VFSTable
{
    friend class T100VFS;
    friend class T100VFSDirectory;
    public:
        T100VFSTable(T100VFS*);
        virtual ~T100VFSTable();

        T100BOOL                setPart(T100VFS_PART*);

        T100BOOL                create();

        T100BOOL                next(T100VFS_TABLE_HANDLE&);
        T100BOOL                save(T100VFS_TABLE_HANDLE&);
        T100BOOL                remove(T100VFS_TABLE_HANDLE&);
        T100BOOL                search(T100DWORD, T100VFS_TABLE_HANDLE&);

        T100DWORD               transform(T100DWORD);

    protected:
        T100DWORD               m_table_begin           = 0;
        T100DWORD               m_table_end             = 0;

    private:
        T100VFS*                m_vfs                   = T100NULL;

};

#endif // T100VFSTABLE_H
