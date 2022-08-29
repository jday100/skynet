#include "T100VFSItem.h"

#include <string.h>
#include "T100Log.h"
#include "T100HintSystem.h"
#include "T100StringTools.h"
#include "T100VDiskFile.h"
#include "T100VFSTable.h"
#include "T100VFSDirectory.h"


T100VFSItem::T100VFSItem(T100VFS* vfs)
    :m_vfs(vfs)
{
    //ctor
}

T100VFSItem::~T100VFSItem()
{
    //dtor
}

T100BOOL T100VFSItem::setPart(T100VFS_PART* part)
{
    if(!part){
        return T100FALSE;
    }
    m_location      = part->LOCATION;
    m_length        = part->LENGTH;

    return T100TRUE;
}

T100BOOL T100VFSItem::create()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    T100DWORD               id;
    T100VFS_TABLE_HANDLE    handle;

    value = m_vfs->m_table->next(handle);
    if(value){
        data = (T100WORD*)&info;
        memset(data, 0, 1024 * 16 * 4);

        m_vfs->m_path->m_root       = handle.CELL;
        m_vfs->m_path->m_current    = handle.CELL;

        id = m_vfs->absolute(m_vfs->relative(handle.CELL));
        value = m_vfs->m_vdisk->write(id, data);
        if(value){
            handle.CELL = T100VFS_ITEM_END;
            value = m_vfs->m_table->save(handle);
            if(!value){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VFSItem::next(T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(m_vfs->m_path->m_current));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    for(int i=0;i<16 * 16 - 1;i++){
        if(0 == info.ITEMS[i].PROPERTIES[0]){
            handle.ITEM         = info.ITEMS[i];
            handle.LOCATION     = m_vfs->m_path->m_current;
            handle.OFFSET       = i;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100VFSItem::save(T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(handle.LOCATION));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    info.ITEMS[handle.OFFSET] = handle.ITEM;

    value = m_vfs->m_vdisk->write(id, data);

    return value;
}

T100BOOL T100VFSItem::remove(T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(handle.LOCATION));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    info.ITEMS[handle.OFFSET].PROPERTIES[0]     = 0;
    info.ITEMS[handle.OFFSET].LOCATION          = T100VFS_ITEM_NONE;

    value = m_vfs->m_vdisk->write(id, data);

    return value;
}

T100BOOL T100VFSItem::list(T100DWORD current)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(current));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    value = T100FALSE;
    for(int i=0;i<16 * 16 - 1;i++){
        if(1 == info.ITEMS[i].PROPERTIES[0]){
            T100Log::info(T100HintSystem::item_hint(info.ITEMS[i]));
            value = T100TRUE;
        }
    }

    if(!value){
        T100Log::info(T100SYSTEM_HINT_VDISK_NO_ITEM);
    }

    return T100TRUE;
}

T100BOOL T100VFSItem::search(T100String name, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(m_vfs->m_path->m_current));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    for(int i=0;i<16 * 16 - 1;i++){
        if(1 == info.ITEMS[i].PROPERTIES[0]
           && T100StringTools::compare(info.ITEMS[i].NAME, 111, name)){
                handle.ITEM         = info.ITEMS[i];
                handle.LOCATION     = m_vfs->m_path->m_current;
                handle.OFFSET       = i;
                return T100TRUE;
           }
    }

    return T100FALSE;
}

T100BOOL T100VFSItem::search(T100DWORD current, T100String name, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(current));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    for(int i=0;i<16 * 16 - 1;i++){
        if(1 == info.ITEMS[i].PROPERTIES[0]
           && T100StringTools::compare(info.ITEMS[i].NAME, 200, name)){
                handle.ITEM         = info.ITEMS[i];
                handle.LOCATION     = current;
                handle.OFFSET       = i;
                return T100TRUE;
           }
    }

    return T100FALSE;
}

T100BOOL T100VFSItem::first(T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(1);
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    for(int i=0;i<16 * 16 - 1;i++){
        if(0 != info.ITEMS[i].PROPERTIES[0] && T100VFS_ITEM_BAD != info.ITEMS[i].PROPERTIES[0]){
            handle.ITEM         = info.ITEMS[i];
            handle.LOCATION     = 0;
            handle.OFFSET       = i;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100VFSItem::next(T100DWORD current, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD               id;
    T100VFS_ITEM_INFO       info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(current));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    for(int i=0;i<16 * 16 - 1;i++){
        if(0 == info.ITEMS[i].PROPERTIES[0]){
            handle.ITEM         = info.ITEMS[i];
            handle.LOCATION     = current;
            handle.OFFSET       = i;
            return T100TRUE;
        }
    }

    return T100FALSE;
}
