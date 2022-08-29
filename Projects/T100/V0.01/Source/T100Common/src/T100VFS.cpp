#include "T100VFS.h"

#include <string.h>
#include "T100FileTools.h"
#include "T100VDiskPart.h"
#include "T100VFSItem.h"
#include "T100VFSTable.h"
#include "T100VFSDirectory.h"
#include "T100VFSFile.h"


T100VFS::T100VFS(T100VDiskFile* vdisk, T100VDiskPart* part)
    :m_vdisk(vdisk), m_part(part)
{
    //ctor
    create();
}

T100VFS::~T100VFS()
{
    //dtor
    destroy();
}

T100VOID T100VFS::create()
{
    m_table     = T100NEW T100VFSTable(this);
    m_item      = T100NEW T100VFSItem(this);

    m_path      = T100NEW T100VFSDirectory(this);
}

T100VOID T100VFS::destroy()
{
    T100SAFE_DELETE(m_path);
    T100SAFE_DELETE(m_item);
    T100SAFE_DELETE(m_table);
}

T100BOOL T100VFS::format(T100STRING name)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part    = m_part->search(name);

    if(!part){
        return T100FALSE;
    }

    value = change_part(part);
    if(!value){
        return T100FALSE;
    }


    if(m_table->create()){
        if(m_item->create()){
            return T100TRUE;
        }
    }

    result = T100FALSE;

    return result;
}

T100BOOL T100VFS::format(T100STRING name, T100STRING boot)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    value = format(name);
    if(value){
        part = m_part->search(name);

        if(part && 1 == part->BOOT){
            T100WORD_VECTOR     file;
            T100WORD*           data;
            T100WORD            length;
            T100WORD            buffer[1024 * 16];

            value = T100FileTools::load(boot.to_wstring(), file, 0);
            if(value){
                if(file.size() > 1024 * 16){
                    return T100FALSE;
                }

                memcpy(buffer, file.data(), file.size() * 4);
                value = m_vdisk->write(part->LOCATION, buffer);
                if(value){
                    result = T100TRUE;
                }else{
                    result = T100FALSE;
                }
            }else{
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

T100BOOL T100VFS::mkdir(T100STRING name, T100STRING path)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);

    if(!part){
        return T100FALSE;
    }

    value = change_part(part);
    if(!value){
        return T100FALSE;
    }

    value = m_path->mkdir(path);
    if(value){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFS::chdir(T100STRING name, T100STRING path)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);

    if(!part){
        return T100FALSE;
    }

    value = change_part(part);
    if(!value){
        return T100FALSE;
    }

    value = m_path->chdir(path);
    if(value){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFS::rmdir(T100STRING name, T100STRING path)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);

    if(!part){
        return T100FALSE;
    }

    value = change_part(part);
    if(!value){
        return T100FALSE;
    }

    value = m_path->rmdir(path);
    if(value){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFS::create(T100STRING name, T100STRING file)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);

    if(!part){
        return T100FALSE;
    }

    if(!change_part(part)){
        return T100FALSE;
    }

    T100VFSFile     item(this, file);

    value = item.create();
    if(value){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFS::remove(T100STRING name, T100STRING file)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);

    if(!part){
        return T100FALSE;
    }

    T100VFSFile     item(this, file);

    value = item.remove();
    if(value){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VFS::list(T100STRING name, T100STRING path)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);

    if(part){
        value = change_part(part);
        if(!value){
            return T100FALSE;
        }
    }else{
        return T100FALSE;
    }

    value = m_path->list(path);

    return value;
}

T100BOOL T100VFS::copy(T100STRING source, T100STRING name, T100STRING target)
{
    /*
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VFS_PART*   part        = T100NULL;

    part = m_part->search(name);
    if(!part){
        return T100FALSE;
    }

    value = change_part(part);
    if(!value){
        return T100FALSE;
    }

    T100STRING   sdir, sfile;
    T100STRING   tdir, tfile;
    T100STRING   path;

    value = m_path->isdir(source);
    if(value){
        return T100FALSE;
    }

    value = m_path->split(source, sdir, sfile);
    if(!value){
        return T100FALSE;
    }

    if(sfile.empty()){
        return T100FALSE;
    }

    value = m_path->isdir(target);
    if(value){
        path = target + ":" + sfile;
    }else{
        path = target;
    }

    T100DWORD       tfp;
    T100VFSFile     tf(this, target);
    T100WORD        buffer[1024 * 16];
    T100WORD*       data;
    T100DWORD       offset      = 0;
    T100WORD        length      = 0;

    data = buffer;

    tfp = tf.open();
    if(!tfp){
        return T100FALSE;
    }

    std::ifstream ifs(source, std::ios::in | std::ios::binary);
    if(!ifs.is_open()){
        value = tf.close();
        if(!value){
            return T100FALSE;
        }
        return T100FALSE;
    }

NEXT_WRITE:
    length  = ifs.read((T100STDCHAR*)data, 1024 * 16 * 4).gcount();
    if(0 != length){
        value   = tf.write(data, (length + 3) / 4);
        if(!value)goto WRITE_END;
        offset  += length;
        goto NEXT_WRITE;
    }

WRITE_END:
    ifs.close();
    value = tf.close();
    if(!value){
        result = T100FALSE;
    }

    return result;
    */
}

T100BOOL T100VFS::change_part(T100VFS_PART* part)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    if(!part){
        return T100FALSE;
    }

    value = m_table->setPart(part);
    if(value){
        value = m_item->setPart(part);
        if(value){
            value = m_path->setPart(part);
            if(value){

            }else{
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

T100BOOL T100VFS::clear(T100DWORD id)
{
    T100BOOL    result      = T100TRUE;
    T100WORD    buffer[1024 * 16];
    T100WORD*   data;

    data = buffer;

    //result = read(transform(id), data);

    memset(data, 0, 1024 * 16 * 4);

    //result = m_vdisk->write(m_table->transform(id), data);
    result = m_vdisk->write(absolute(relative(id)), data);

    return result;
}

T100DWORD T100VFS::absolute(T100DWORD id)
{
    T100DWORD   result      = 0;

    result = m_item->m_location + id;

    return result;
}

T100DWORD T100VFS::relative(T100DWORD id)
{
    T100DWORD   result      = 0;

    result = m_table->m_table_end + 1 + id;

    return result;
}

T100DWORD T100VFS::transform(T100DWORD location, T100WORD offset)
{
    T100DWORD   result      = 0;

    result = (location - m_table->m_table_begin) * 512 * 16 + offset;

    return result;
}
