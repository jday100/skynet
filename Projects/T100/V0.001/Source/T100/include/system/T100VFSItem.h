#ifndef T100VFSITEM_H
#define T100VFSITEM_H

#include "T100DataTypes.h"
#include "T100VFS.h"


class T100VFSItem
{
    friend class T100VFS;
    public:
        T100VFSItem(T100VFS*);
        virtual ~T100VFSItem();

        T100BOOL            setPart(T100VFS_PART*);

        T100BOOL            create();

        T100BOOL            next(T100VFS_ITEM_HANDLE&);
        T100BOOL            save(T100VFS_ITEM_HANDLE&);
        T100BOOL            remove(T100VFS_ITEM_HANDLE&);

        T100BOOL            first(T100VFS_ITEM_HANDLE&);
        T100BOOL            next(T100DWORD, T100VFS_ITEM_HANDLE&);

        T100BOOL            search(T100String, T100VFS_ITEM_HANDLE&);
        T100BOOL            search(T100DWORD, T100String, T100VFS_ITEM_HANDLE&);

        T100BOOL            list(T100DWORD);

    protected:
        T100DWORD           m_location      = 0;
        T100DWORD           m_length        = 0;

    private:
        T100VFS*            m_vfs           = T100NULL;
};

#endif // T100VFSITEM_H
