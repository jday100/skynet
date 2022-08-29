#include "T100VFSFile.h"

#include "T100StringTools.h"
#include "T100VDiskFile.h"
#include "T100VFSTable.h"
#include "T100VFSItem.h"
#include "T100VFSDirectory.h"


T100VFSFile::T100VFSFile(T100VFS* vfs, T100STDSTRING file)
    :m_vfs(vfs), m_file(file)
{
    //ctor
}

T100VFSFile::~T100VFSFile()
{
    //dtor
}

T100BOOL T100VFSFile::create()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100STDSTRING   dir, name;

    value = m_vfs->m_path->isdir(m_file);
    if(value){
        return T100FALSE;
    }

    value = m_vfs->m_path->split(m_file, dir, name);
    if(!value){
        return T100FALSE;
    }

    T100VFS_ITEM_HANDLE     path;
    T100VFS_ITEM_HANDLE     item;

    if(dir.empty()){
        value = m_vfs->m_item->next(item);
        if(!value){
            return T100FALSE;
        }
    }else if(":" == dir){
        value = m_vfs->m_item->next(m_vfs->m_path->m_root, item);
        if(!value){
            return T100FALSE;
        }
    }else{
        value = m_vfs->m_path->search(dir, path);
        if(!value){
            return T100FALSE;
        }

        value = m_vfs->m_item->next(path.ITEM.LOCATION, item);
        if(!value){
            return T100FALSE;
        }
    }

    T100String fname(name);

    value = T100StringTools::copy(item.ITEM.NAME, fname.getRawData(), fname.getRawLength());
    if(!value){
        return T100FALSE;
    }

    item.ITEM.LENGTH            = 0;
    item.ITEM.LOCATION          = T100VFS_ITEM_END;
    item.ITEM.PROPERTIES[0]     = 1;
    item.ITEM.PROPERTIES[1]     = 1;

    value = m_vfs->m_item->save(item);
    if(!value){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100VFSFile::remove()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    if(m_opened){

    }else{
        T100STDSTRING   dir, name;

        value = m_vfs->m_path->isdir(m_file);
        if(value){
            return T100FALSE;
        }

        value = m_vfs->m_path->split(m_file, dir, name);
        if(!value){
            return T100FALSE;
        }

        T100VFS_ITEM_HANDLE     path;
        T100VFS_ITEM_HANDLE     item;

        if(dir.empty()){
            value = m_vfs->m_item->next(item);
            if(!value){
                return T100FALSE;
            }
        }else{
            value = m_vfs->m_path->search(dir, path);
            if(!value){
                return T100FALSE;
            }

            value = m_vfs->m_item->next(path.LOCATION, item);
            if(!value){
                return T100FALSE;
            }
        }

        item.ITEM.PROPERTIES[0]     = 0;

        value = m_vfs->m_item->save(item);
        if(value){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100VFSFile::exists()
{
    T100VFS_ITEM_HANDLE     handle;

    if(m_vfs->m_path->search(m_file, handle)){
        return T100TRUE;
    }

    return T100FALSE;
}

T100DWORD T100VFSFile::length()
{
    T100DWORD               result      = 0;
    T100VFS_ITEM_HANDLE     handle;

    if(m_vfs->m_path->search(m_file, handle)){
        result = handle.ITEM.LENGTH;
        return result;
    }

    return result;
}

T100BOOL T100VFSFile::open()
{
    T100VFS_ITEM_HANDLE     handle;

    if(m_vfs->m_path->search(m_file, handle)){
        m_seek          = 0;
        m_handle        = T100NEW T100VFS_FILE_HANDLE;
        m_handle->ITEM  = handle;

        m_opened        = T100TRUE;

        return T100TRUE;
    }else{
        if(!create()){
            return T100FALSE;
        }

        if(!m_vfs->m_path->search(m_file, handle)){
            return T100FALSE;
        }

        m_seek          = 0;
        m_handle        = T100NEW T100VFS_FILE_HANDLE;
        m_handle->ITEM  = handle;

        m_opened        = T100TRUE;

        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFSFile::close()
{
    if(!m_handle){
        return T100FALSE;
    }

    T100DELETE(m_handle);
    m_handle    = T100NULL;

    return T100TRUE;
}

T100BOOL T100VFSFile::read(T100WORD* data, T100WORD& length)
{
    T100WORD    buffer[1024 * 16];
    T100WORD*   fp;

    fp = buffer;

    T100DWORD   rlocation;
    T100WORD    roffset, rlength;

    rlocation   = m_seek / 1024 / 16;
    roffset     = m_seek % (1024 * 16);
    rlength     = (1024 * 16) - roffset;

    if(0 == roffset){
        if((1024 * 16) < length){
            fp = data;

            //read(rlocation, fp);
            fp += 1024 * 16;
        }
    }else{
        fp = buffer;
        //read(rlocation, fp);
    }

    return T100FALSE;
}

T100BOOL T100VFSFile::write(T100WORD* data, T100WORD length)
{
    T100BOOL    value;
    T100DWORD   id;

    T100WORD    *fp, *fd;

    T100WORD    woffset, wlength, wamount;
    T100WORD*   wcurrent;

    wcurrent    = data;
    wamount     = length;
    fp = m_handle->BUFFER;

NEXT_WRITE:
    value = seek(m_seek);
    if(!value){
        return T100FALSE;
    }

    woffset = m_seek % (1024 * 16);

    if(0 == woffset){
        if(wamount > 1024 * 16){
            wlength = 1024 * 16;
            m_seek  += 1024 * 16;
            wamount -=wlength;

            if(0 != wamount){
                goto NEXT_WRITE;
            }
        }else{
            wlength = wamount;

            id = m_vfs->absolute(m_vfs->relative(m_handle->CURRENT));
            value = m_vfs->m_vdisk->read(id, fp);
            if(!value){
                return T100FALSE;
            }

            memcpy(fp, wcurrent, wlength * 4);

            value = m_vfs->m_vdisk->write(id, fp);
            if(!value){
                return T100FALSE;
            }

            wcurrent    += wlength;
            m_seek      += wlength;
            wamount     -= wlength;

            if(0 != wamount){
                goto NEXT_WRITE;
            }
        }
    }else{
        id = m_vfs->absolute(m_vfs->relative(m_handle->CURRENT));
        value = m_vfs->m_vdisk->read(id, fp);
        if(!value){
            return T100FALSE;
        }

        if(woffset + wamount >1024 * 16){
            wlength = (1024 * 16) - woffset;
            fd      = fp + woffset;

            memcpy(fd, wcurrent, wlength * 4);
            value = m_vfs->m_vdisk->write(id, fp);
            if(!value){
                return T100FALSE;
            }

            wcurrent    += wlength;
            m_seek      += wlength;
            wamount     -= wlength;

            if(0 != wamount){
                goto NEXT_WRITE;
            }
        }else{
            wlength = wamount;
            fd      = fp + wamount;

            memcpy(fd, wcurrent, wlength * 4);
            value = m_vfs->m_vdisk->write(id, fp);
            if(!value){
                return T100FALSE;
            }

            wcurrent    += wlength;
            m_seek      += wlength;
            wamount     -= wlength;

            if(0 != wamount){
                goto NEXT_WRITE;
            }
        }
    }

    if(m_seek > m_handle->ITEM.ITEM.LENGTH){
        m_handle->ITEM.ITEM.LENGTH  = m_seek;
        value = save(m_handle);
        if(!value){
            return T100FALSE;
        }
    }


    return T100TRUE;
}

T100BOOL T100VFSFile::seek(T100DWORD offset)
{
    T100BOOL                value;

    if(!m_opened){
        return T100FALSE;
    }

    T100DWORD               count;
    T100DWORD               location;
    T100VFS_TABLE_HANDLE    table;

    m_seek      = offset;
    count       = offset / 1024 / 16;
    location    = m_handle->ITEM.ITEM.LOCATION;

    for(int i=0;i<count+1;i++){
        if(T100VFS_ITEM_END == location){
            T100VFS_TABLE_HANDLE    next;

            value = m_vfs->m_table->next(next);
            if(!value){
                return T100FALSE;
            }

            if(0 == i){
                m_handle->ITEM.ITEM.LOCATION    = next.CELL;
                m_handle->CURRENT               = next.CELL;

                next.CELL   = T100VFS_ITEM_END;

                value = m_vfs->m_table->save(next);
                if(!value){
                    return T100FALSE;
                }

                value = save(m_handle);
                if(!value){
                    return T100FALSE;
                }

                table       = next;
                location    = table.CELL;
            }else{
                table.CELL          = next.CELL;
                m_handle->CURRENT   = next.CELL;

                next.CELL           = T100VFS_ITEM_END;

                value = m_vfs->m_table->save(next);
                if(!value){
                    return T100FALSE;
                }

                value = m_vfs->m_table->save(table);
                if(!value){
                    return T100FALSE;
                }

                table       = next;
                location    = table.CELL;
            }
        }else{
            T100VFS_TABLE_HANDLE    next;

            value = m_vfs->m_table->search(location, next);
            if(!value){
                return T100FALSE;
            }

            m_handle->CURRENT   = location;

            table = next;

            location = table.CELL;
        }
    }

    return T100TRUE;
}

T100BOOL T100VFSFile::save(T100VFS_FILE_HANDLE* handle)
{
    T100BOOL            value;
    T100DWORD           id;

    T100VFS_ITEM_INFO   info;
    T100WORD*           data;

    data = (T100WORD*)&info;

    id = m_vfs->absolute(m_vfs->relative(m_handle->ITEM.LOCATION));
    value = m_vfs->m_vdisk->read(id, data);
    if(!value){
        return T100FALSE;
    }

    info.ITEMS[handle->ITEM.OFFSET] = handle->ITEM.ITEM;

    value = m_vfs->m_vdisk->write(id, data);

    return value;

}
