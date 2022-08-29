#include "T100VFSDirectory.h"

#include "T100StringTools.h"
#include "T100VFSTable.h"
#include "T100VFSItem.h"
#include "T100VDiskFile.h"


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

    id = m_vfs->absolute(m_vfs->m_table->m_table_begin);
    value = m_vfs->m_vdisk->read(id, data);
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


    /*
    T100BOOL                value;
    T100VFS_ITEM_HANDLE     handle;

    value = m_vfs->m_item->first(handle);
    if(value){
        m_root      = handle.OFFSET;
        m_current   = m_root;
        return T100TRUE;
    }
    */
    return T100FALSE;
}

T100BOOL T100VFSDirectory::mkdir(T100STDSTRING path)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VFS_ITEM_HANDLE     handle;
    T100STDSTRING           dir, name;
    T100DWORD               current;

    value = split(path, dir, name);
    if(!value || name.empty()){
        return T100FALSE;
    }

    if(dir.empty()){
        current = m_current;
    }else if(":" == dir){
        current = m_root;
    }else{
        value = search(dir, handle);
        if(!value){
            return T100FALSE;
        }
        current = handle.LOCATION;
    }

    T100String dname(name);
    value = m_vfs->m_item->search(current, dname, handle);
    if(value){
        return T100FALSE;
    }

    if(m_vfs->m_item->next(current, handle)){
        value = T100StringTools::copy(handle.ITEM.NAME, dname.getRawData(), dname.getRawLength());
        if(!value){
            return T100FALSE;
        }

        handle.ITEM.LENGTH          = 0;
        handle.ITEM.LOCATION        = T100VFS_ITEM_END;
        handle.ITEM.PROPERTIES[0]   = 1;
        handle.ITEM.PROPERTIES[1]   = 0;

        T100VFS_TABLE_HANDLE    table;

        value = m_vfs->m_table->next(table);
        if(!value){
            return T100FALSE;
        }

        handle.ITEM.LOCATION    = table.CELL;
        table.CELL              = T100VFS_ITEM_END;

        value = m_vfs->m_table->save(table);
        if(!value){
            return T100FALSE;
        }

        value = m_vfs->clear(handle.ITEM.LOCATION);
        if(!value){
            return T100FALSE;
        }

        m_current   = handle.ITEM.LOCATION;

        value = m_vfs->m_item->save(handle);
        if(value){
            return T100TRUE;
        }else{
            value = m_vfs->m_table->remove(table);
        }
    }


    return T100FALSE;
}

T100BOOL T100VFSDirectory::chdir(T100STDSTRING path)
{
    T100BOOL                value;
    T100VFS_ITEM_HANDLE     handle;

    if(path.empty()){
        return T100FALSE;
    }

    if(":" == path){
        m_current = m_root;
        return T100TRUE;
    }

    if(':' == path[0]){
        m_current = m_root;
    }

    T100STDSTRING_VECTOR    dirs;

    value = T100StringTools::split(path, ":", dirs);
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

T100BOOL T100VFSDirectory::rmdir(T100STDSTRING path)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VFS_ITEM_HANDLE     handle;
    T100STDSTRING           dir, name;
    T100DWORD               current;

    value = isdir(path);
    if(!value){
        return T100FALSE;
    }

    value = split(path, dir, name);
    if(!value || name.empty()){
        return T100FALSE;
    }

    if(":" == dir){
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

    T100String dname(name);
    value = m_vfs->m_item->search(current, dname, handle);
    if(!value){
        return T100FALSE;
    }

    current = handle.ITEM.LOCATION;

    handle.ITEM.LENGTH          = 0;
    handle.ITEM.LOCATION        = T100VFS_ITEM_END;
    handle.ITEM.PROPERTIES[0]   = 0;
    handle.ITEM.PROPERTIES[0]   = 0;

    T100VFS_TABLE_HANDLE    table;

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

T100BOOL T100VFSDirectory::split(T100STDSTRING path, T100STDSTRING& dir, T100STDSTRING& file)
{
    /*
    if(isdir(path)){
        return T100FALSE;
    }
    */

    T100BOOL                value;
    T100STDSTRING_VECTOR    dirs;

    value = T100StringTools::split(path, ":\\", dirs);
    if(!value){
        return T100FALSE;
    }

    if(0 == dirs.size()){
        return T100FALSE;
    }

    if(':' == path[0]){
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

T100BOOL T100VFSDirectory::search(T100STDSTRING path, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    value;

    if(path.empty()){
        return T100FALSE;
    }

    T100DWORD               current;
    T100VFS_ITEM_HANDLE     item;

    if(":" == path){
        return T100FALSE;
    }else{
        if(':' == path[0]){
            current = m_root;
        }else{
            current = m_current;
        }

        T100STDSTRING_VECTOR    dirs;

        value = T100StringTools::split(path, ":", dirs);
        if(!value){
            return T100FALSE;
        }

        for(auto dir : dirs){
            value = m_vfs->m_item->search(current, dir, item);
            if(!value){
                return T100FALSE;
            }
            current     = item.ITEM.LOCATION;
        }

        handle  = item;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFSDirectory::search(T100DWORD current, T100STDSTRING path, T100VFS_ITEM_HANDLE& handle)
{
    T100BOOL    value;

    if(path.empty()){
        return T100FALSE;
    }

    if(":" == path){
        return T100FALSE;
    }else{
        if(':' == path[0]){
            return T100FALSE;
        }

        T100STDSTRING_VECTOR    dirs;

        value = T100StringTools::split(path, ":", dirs);
        if(!value){
            return T100FALSE;
        }

        T100VFS_ITEM_HANDLE     item;

        for(auto dir : dirs){
            value = m_vfs->m_item->search(current, dir, item);
            if(!value){
                return T100FALSE;
            }
            current     = item.ITEM.LOCATION;
        }

        handle  = item;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFSDirectory::list(T100STDSTRING path)
{
    T100BOOL    value;
    T100DWORD   current;

    if(path.empty()){
        return T100FALSE;
    }

    if(":" == path){
        current = m_root;
    }else{
        if(':' == path[0]){
            current = m_root;
        }else{
            current = m_current;
        }

        T100STDSTRING_VECTOR    dirs;

        value = T100StringTools::split(path, ":", dirs);
        if(!value){
            return T100FALSE;
        }

        T100VFS_ITEM_HANDLE     handle;

        for(auto dir : dirs){
            value = search(current, dir, handle);
            if(!value){
                return T100FALSE;
            }
            current = handle.ITEM.LOCATION;
        }
    }

    value = m_vfs->m_item->list(current);

    return value;
}

T100BOOL T100VFSDirectory::isdir(T100STDSTRING path)
{
    T100BOOL                value;
    T100DWORD               current;

    if(path.empty()){
        return T100FALSE;
    }

    if(":" == path){
        return T100TRUE;
    }

    if(':' == path[0]){
        current = m_root;
    }

    T100STDSTRING_VECTOR    dirs;
    T100VFS_ITEM_HANDLE     target;

    value = T100StringTools::split(path, ":", dirs);
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

    if(m_vfs->m_item->search(current, T100String(dirs.back()), target)){
        if(0 == target.ITEM.PROPERTIES[1]){
            return T100TRUE;
        }
    }

    return T100FALSE;
}
