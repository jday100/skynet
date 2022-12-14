#include "T100VFSDirectory.h"

#include "T100String.h"
#include "T100String32Tools.h"
#include "T100VFSTable.h"
#include "T100VFSItem.h"
#include "T100VDiskFile.h"

namespace T100Component{

T100VFSDirectory::T100VFSDirectory(T100VFS* vfs)
    :m_vfs(vfs)
{
    //ctor
}

T100VFSDirectory::~T100VFSDirectory()
{
    //dtor
}

T100BOOL T100VFSDirectory::setPart(T100VFS_PART* part)
{
    if(!part){
        return T100FALSE;
    }

    T100BOOL                value;
    T100DWORD               id;
    T100VFS_TABLE_INFO      info;
    T100WORD*               data;

    data = (T100WORD*)&info;

    id      = m_vfs->absolute(m_vfs->m_table->m_table_begin);
    value   = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    if(T100VFS_ITEM_BAD == info.CELLS[0]){
        return T100FALSE;
    }else{
        //test
        m_root      = 0;
        m_current   = m_root;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100VFSDirectory::mkdir(T100STRING path)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100VFS_ITEM_HANDLE             handle;
    T100STRING                      dir, name;
    T100DWORD                       current;

    value = split(path, dir, name);
    if(!value || name.empty()){
        return T100FALSE;
    }

    if(dir.empty()){
        current = m_current;
    }else if(T100STRING(":") == dir){
        current = m_root;
    }else{
        value = search(dir, handle);
        if(!value){
            return T100FALSE;
        }
        current = handle.LOCATION;
    }

    T100STRING      dname(name);

    value = m_vfs->m_item->search(current, dname, handle);
    if(value){
        return T100FALSE;
    }

    if(m_vfs->m_item->next(current, handle)){
        value = T100Library::T100String32Tools::copy(handle.ITEM.NAME, dname.to_string32().raw_data(), dname.to_string32().raw_length());
        if(!value){
            return T100FALSE;
        }

        handle.ITEM.LENGTH          = 0;
        handle.ITEM.LOCATION        = T100VFS_ITEM_END;
        handle.ITEM.PROPERTIES[0]   = 1;
        handle.ITEM.PROPERTIES[1]   = 0;

        T100VFS_TABLE_HANDLE        table;

        value = m_vfs->m_table->next(table);
        if(!value){
            return T100FALSE;
        }

        handle.ITEM.LOCATION        = table.CELL;
        table.CELL                  = T100VFS_ITEM_END;

        value = m_vfs->m_table->save(table);
        if(!value){
            return T100FALSE;
        }

        value = m_vfs->clear(handle.ITEM.LOCATION);
        if(!value){
            return T100FALSE;
        }

        m_current = handle.ITEM.LOCATION;

        value = m_vfs->m_item->save(handle);
        if(value){
            return T100TRUE;
        }else{
            value = m_vfs->m_table->remove(table);
        }
    }
    return T100FALSE;
}

T100BOOL T100VFSDirectory::chdir(T100STRING path)
{
    T100BOOL                value;
    T100VFS_ITEM_HANDLE     handle;

    if(path.empty()){
        return T100FALSE;
    }

    if(T100STRING(":") == path){
        m_current = m_root;
        return T100TRUE;
    }

    if(L':' == path[0]){
        m_current = m_root;
    }

    T100STRING_VECTOR       dirs;

    value = T100Library::T100String32Tools::split(path, T100STRING(":"), dirs);
    if(!value){
        return T100FALSE;
    }

    if(1 != dirs.size()){
        for(int i=0;i<dirs.size();i++){
            value = chdir(dirs[i]);
            if(!value){
                return T100FALSE;
            }
        }
    }else{
        value = m_vfs->m_item->search(dirs[0], handle);
        if(value){
            m_current = handle.ITEM.LOCATION;
            return T100TRUE;
        }else{
            return T100FALSE;
        }
    }
    return T100FALSE;
}

T100BOOL T100VFSDirectory::rmdir(T100STRING path)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100VFS_ITEM_HANDLE             handle;
    T100STRING                      dir, name;
    T100DWORD                       current;

    value = isdir(path);
    if(!value){
        return T100FALSE;
    }

    value = split(path, dir, name);
    if(!value || name.empty()){
        return T100FALSE;
    }

    if(T100STRING(":") == dir){
        current = m_root;
    }else if(dir.empty()){
        current = m_current;
    }else{
        value = search(dir, handle);
        if(!value){
            return T100FALSE;
        }
        current = handle.LOCATION;
    }

    T100STRING      dname(name);

    value = m_vfs->m_item->search(current, dname, handle);
    if(!value){
        return T100FALSE;
    }

    current = handle.ITEM.LOCATION;

    handle.ITEM.LENGTH          = 0;
    handle.ITEM.LOCATION        = T100VFS_ITEM_END;
    handle.ITEM.PROPERTIES[0]   = 0;
    handle.ITEM.PROPERTIES[1]   = 0;

    T100VFS_TABLE_HANDLE        table;

    value = m_vfs->m_table->search(current, table);
    if(!value){
        return T100FALSE;
    }

    value = m_vfs->m_table->remove(table);
    if(!value){
        return T100FALSE;
    }

    value = m_vfs->clear(current);
    if(!value){
        return T100FALSE;
    }

    value = m_vfs->m_item->save(handle);
    if(value){
        return T100TRUE;
    }else{
        value = m_vfs->m_table->save(table);
    }
    return T100FALSE;
}

T100BOOL T100VFSDirectory::split(T100STRING path, T100STRING& dir, T100STRING& file)
{
    T100BOOL                value;
    T100STRING_VECTOR       dirs;

    value = T100Library::T100String32Tools::split(path, ":\\", dirs);
    if(!value){
        return T100FALSE;
    }

    if(0 == dirs.size()){
        return T100FALSE;
    }

    if(L':' == path[0]){
        dir = ":";
    }

    if(1 == dirs.size()){
        file = dirs[0];
        return T100TRUE;
    }

    for(int i=0;i<dirs.size()-1;i++){
        dir += dirs[i];
        dir += ":";
    }

    file = dirs[dirs.size()-1];

    return T100TRUE;
}

T100BOOL T100VFSDirectory::search(T100STRING path, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL            value;

    if(path.empty()){
        return T100FALSE;
    }

    T100DWORD               current;
    T100VFS_ITEM_HANDLE     item;

    if(T100STRING(":") == path){
        return T100FALSE;
    }else{
        if(L':' == path[0]){
            current = m_root;
        }else{
            current = m_current;
        }

        T100STRING_VECTOR       dirs;

        value = T100Library::T100String32Tools::split(path, ":", dirs);
        if(!value){
            return T100FALSE;
        }

        for(T100STRING dir : dirs){
            value = m_vfs->m_item->search(current, dir, item);
            if(!value){
                return T100FALSE;
            }
            current = item.ITEM.LOCATION;
        }

        handle = item;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100VFSDirectory::search(T100DWORD current, T100STRING path, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL        value;

    if(path.empty()){
        return T100FALSE;
    }

    if(T100STRING(":") == path){
        return T100FALSE;
    }else{
        if(L':' == path[0]){
            return T100FALSE;
        }

        T100STRING_VECTOR       dirs;

        value = T100Library::T100String32Tools::split(path, ":", dirs);
        if(!value){
            return T100FALSE;
        }

        T100VFS_ITEM_HANDLE     item;

        for(T100STRING dir : dirs){
            value = m_vfs->m_item->search(current, dir, item);
            if(!value){
                return T100FALSE;
            }
            current = item.ITEM.LOCATION;
        }

        handle = item;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100VFSDirectory::list(T100STRING path, T100DISK_ITEM_VECTOR& items)
{
    T100BOOL            value;
    T100DWORD           current;

    if(path.empty()){
        return T100FALSE;
    }

    if(T100STRING(":") == path){
        current = m_root;
    }else{
        if(L':' == path[0]){
            current = m_root;
        }else{
            current = m_current;
        }

        T100STRING_VECTOR       dirs;

        value = T100Library::T100String32Tools::split(path, ":", dirs);
        if(!value){
            return T100FALSE;
        }

        T100VFS_ITEM_HANDLE     handle;

        for(T100STRING dir : dirs){
            value = search(current, dir, handle);
            if(!value){
                return T100FALSE;
            }
            current = handle.ITEM.LOCATION;
        }
    }

    value = m_vfs->m_item->list(current, items);

    return value;
}

T100BOOL T100VFSDirectory::isdir(T100STRING path)
{
    T100BOOL            value;
    T100DWORD           current;

    if(path.empty()){
        return T100FALSE;
    }

    if(T100STRING(":") == path){
        return T100TRUE;
    }

    if(L':' == path[0]){
        current = m_root;
    }

    T100STRING_VECTOR       dirs;
    T100VFS_ITEM_HANDLE     target;

    value = T100Library::T100String32Tools::split(path, ":", dirs);
    if(!value){
        return T100FALSE;
    }

    if(0 == dirs.size()){
        return T100FALSE;
    }else if(1 < dirs.size()){
        for(int i=0;i<dirs.size()-1;i++){
            value = search(current, dirs[i], target);
            if(value){
                current = target.LOCATION;
            }else{
                return T100FALSE;
            }
        }
    }

    if(m_vfs->m_item->search(current, T100STRING(dirs.back()), target)){
        if(0 == target.ITEM.PROPERTIES[1]){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

}
