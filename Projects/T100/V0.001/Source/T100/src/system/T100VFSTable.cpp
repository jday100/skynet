#include "T100VFSTable.h"

#include <string.h>
#include "T100VDiskFile.h"


T100VFSTable::T100VFSTable(T100VFS* vfs)
    :m_vfs(vfs)
{
    //ctor
}

T100VFSTable::~T100VFSTable()
{
    //dtor
}

T100BOOL T100VFSTable::setPart(T100VFS_PART* part)
{
    if(!part){
        return T100FALSE;
    }

    m_table_begin   = 1;
    m_table_end     = m_table_begin + part->LENGTH / 512 / 16;

    return T100TRUE;
}

T100BOOL T100VFSTable::create()
{
    T100VFS_TABLE_INFO      info;
    T100WORD*               data;

    data = (T100WORD*)&info;
    memset(data, 0, 1024 * 16 * 4);

    for(int i=0;i<1024 * 16;i++){
        data[i] = 0;
    }

    for(T100DWORD i=m_table_begin;i<m_table_end+1;i++){
        if(m_vfs->m_vdisk->write(m_vfs->absolute(i), data)){

        }else{
            return T100FALSE;
        }
    }

    return T100TRUE;
}


T100BOOL T100VFSTable::next(T100VFS_TABLE_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100VFS_TABLE_INFO      info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    for(T100DWORD i=m_table_begin;i<m_table_end+1;i++){
        value = m_vfs->m_vdisk->read(m_vfs->absolute(i), data);
        if(!value){
            result = T100FALSE;
            break;
        }

        for(T100WORD l=0;l<512 * 16;l++){
            if(T100VFS_ITEM_NONE == info.CELLS[l]){
                handle.CELL         = (i - m_table_begin) * 512 * 16 + l;
                handle.LOCATION     = i;
                handle.OFFSET       = l;
                return T100TRUE;
            }
        }
    }

    return T100FALSE;
}

T100BOOL T100VFSTable::save(T100VFS_TABLE_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_TABLE_INFO      info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(handle.LOCATION);
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    info.CELLS[handle.OFFSET] = handle.CELL;

    value = m_vfs->m_vdisk->write(id, data);

    return value;
}

T100BOOL T100VFSTable::remove(T100VFS_TABLE_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_TABLE_INFO      info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(handle.LOCATION);
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    info.CELLS[handle.OFFSET] = T100VFS_ITEM_NONE;

    value = m_vfs->m_vdisk->write(id, data);

    return value;
}

T100BOOL T100VFSTable::search(T100DWORD id, T100VFS_TABLE_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100VFS_TABLE_INFO      info;
    T100WORD*               data;
    T100DWORD   location, offset;

    location    = id / 512 / 16 + m_table_begin;
    offset      = id % (512 * 16);

    data = (T100WORD*)&info;

    value = m_vfs->m_vdisk->read(m_vfs->absolute(location), data);
    if(!value){
        return T100FALSE;
    }

    handle.CELL         = info.CELLS[offset];
    handle.LOCATION     = location;
    handle.OFFSET       = offset;

    return T100TRUE;
}

T100DWORD T100VFSTable::transform(T100DWORD id)
{
    T100DWORD result;

    result = m_table_end + 1 + id;

    return result;
}
