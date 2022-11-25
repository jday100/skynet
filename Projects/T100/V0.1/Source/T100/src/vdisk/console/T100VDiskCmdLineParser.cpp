#include "T100VDiskCmdLineParser.h"

#include "T100File.h"

namespace T100VDisk{

T100VDiskCmdLineParser::T100VDiskCmdLineParser()
{
    //ctor
}

T100VDiskCmdLineParser::~T100VDiskCmdLineParser()
{
    //dtor
}

T100BOOL T100VDiskCmdLineParser::parse(T100CONSOLE_COMMAND_VECTOR& cmds)
{
    T100BOOL        result          = T100TRUE;

    if(cmds.empty()){
        return T100FALSE;
    }

    T100WSTRING         cmd;
    T100WORD            size;

    cmd     = cmds[0];
    size    = cmds.size();

    if(L"help" == cmd){
        result = help();
    }else if(L"quit" == cmd){
        result = quit();
    }else if(L"create" == cmd){
        switch(size){
        case 4:
            {
                cmd = cmds[1];
                if(L"vdisk" == cmd){
                    result = create(cmds[2], cmds[3]);
                }else if(L"file" == cmd){
                    result = fs_create(cmds[2], cmds[3]);
                }else if(L"dir" == cmd){
                    result = fs_mkdir(cmds[2], cmds[3]);
                }else{
                    result = T100FALSE;
                }
            }
            break;
        case 5:
            {
                cmd = cmds[1];
                if(L"part" == cmd){
                    result = part_create(cmds[2], cmds[3], cmds[4], T100FALSE);
                }else{
                    result = T100FALSE;
                }
            }
            break;
        case 6:
            {
                cmd = cmds[1];
                if(L"part" == cmd && L"boot" == cmds[3]){
                    result = part_create(cmds[2], cmds[4], cmds[5], T100TRUE);
                }else{
                    result = T100FALSE;
                }
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"remove" == cmd){
        switch(size){
        case 3:
            {
                cmd = cmds[1];
                if(L"vdisk" == cmd){
                    result = remove(cmds[2]);
                }else if(L"part" == cmd){
                    result = part_remove(cmds[2]);
                }else{
                    result = T100FALSE;
                }
            }
            break;
        case 4:
            {
                cmd = cmds[1];
                if(L"file" == cmd){
                    result = fs_remove(cmds[2], cmds[3]);
                }else if(L"dir" == cmd){
                    result = fs_rmdir(cmds[2], cmds[3]);
                }else{
                    result = T100FALSE;
                }
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"set" == cmd){
        switch(size){
        case 5:
            {
                if(L"part" == cmds[1] && L"boot" == cmds[3]){
                    result = part_boot(cmds[2], cmds[4]);
                }else{
                    result = T100FALSE;
                }
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"load" == cmd){
        switch(size){
        case 2:
            {
                result = load(cmds[1]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"list" == cmd){
        switch(size){
        case 1:
            {
                result = part_list();
            }
            break;
        case 3:
            {
                cmd     = cmds[1];
                result  = fs_list(cmds[1], cmds[2]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"format" == cmd){
        switch(size){
        case 2:
            {
                result = fs_format(cmds[1]);
            }
            break;
        case 3:
            {
                result = fs_format(cmds[1], cmds[2]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"mkdir" == cmd){
        switch(size){
        case 3:
            {
                result = fs_mkdir(cmds[1], cmds[2]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"chdir" == cmd){
        switch(size){
        case 3:
            {
                result = fs_chdir(cmds[1], cmds[2]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"rmdir" == cmd){
        switch(size){
        case 3:
            {
                result = fs_rmdir(cmds[1], cmds[2]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }else if(L"copy" == cmd){
        switch(size){
        case 4:
            {
                result = fs_copy(cmds[1], cmds[2], cmds[3]);
            }
            break;
        default:
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VDiskCmdLineParser::help()
{
    return T100FALSE;
}

T100BOOL T100VDiskCmdLineParser::create(T100WSTRING file, T100WSTRING value)
{
    T100DWORD       length;

    length  = stol(value);

    m_vdisk = T100NEW T100Component::T100VDisk(file);

    if(m_vdisk->exists()){
        if(!m_vdisk->remove()){
            return T100FALSE;
        }
    }

    return m_vdisk->create(length);
}

T100BOOL T100VDiskCmdLineParser::remove(T100WSTRING file)
{
    T100Library::T100File        target(file);

    if(target.exists()){
        if(target.remove()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100VDiskCmdLineParser::load(T100WSTRING file)
{
    if(m_vdisk){
        if(m_vdisk->close()){
            T100SAFE_DELETE(m_vdisk);
        }else{
            return T100FALSE;
        }
    }

    if(!m_vdisk){
        m_vdisk = T100NEW T100Component::T100VDisk(file);

        if(m_vdisk->open()){
            return T100TRUE;
        }else{
            T100SAFE_DELETE(m_vdisk);
        }
    }
    return T100FALSE;
}

T100BOOL T100VDiskCmdLineParser::part_create(T100WSTRING name, T100WSTRING start, T100WSTRING value, T100BOOL boot)
{
    T100DWORD       location;
    T100DWORD       length;
    T100BOOL        result;

    location        = stol(start);
    length          = stol(value);

    result          = m_vdisk->part_create(name, location, length, boot);

    return result;
}

T100BOOL T100VDiskCmdLineParser::part_remove(T100WSTRING name)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->part_remove(name);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::part_list()
{
    T100BOOL                result;
    T100VFS_PART_VECTOR     parts;

    result = m_vdisk->part_list(parts);
    if(!result){
        return T100FALSE;
    }

    if(parts.empty()){
        return T100TRUE;
    }

    for(T100Component::T100VFS_PART part : parts){

    }
    return T100TRUE;
}

T100BOOL T100VDiskCmdLineParser::part_boot(T100WSTRING part, T100WSTRING boot)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;
    T100BOOL        flag;

    if(L"1" == boot){
        flag = T100TRUE;
    }else if(L"0" == boot){
        flag = T100FALSE;
    }

    value = m_vdisk->part_boot(part, flag);

    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_format(T100WSTRING name)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_format(name);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_format(T100WSTRING name, T100WSTRING boot)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_format(name, boot);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_mkdir(T100WSTRING name, T100WSTRING path)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_mkdir(name, path);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_chdir(T100WSTRING name, T100WSTRING path)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_chdir(name, path);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_rmdir(T100WSTRING name, T100WSTRING path)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_rmdir(name, path);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_create(T100WSTRING name, T100WSTRING file)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_create(name, file);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_remove(T100WSTRING name, T100WSTRING file)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_format(name, file);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_list(T100WSTRING name, T100WSTRING path)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;
    T100DISK_ITEM_VECTOR        items;

    value = m_vdisk->fs_list(name, path, items);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::fs_copy(T100WSTRING source, T100WSTRING name, T100WSTRING target)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_vdisk->fs_copy(source, name, target);
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskCmdLineParser::quit()
{
    if(m_vdisk){
        return m_vdisk->close();
    }
    return T100TRUE;
}

}
