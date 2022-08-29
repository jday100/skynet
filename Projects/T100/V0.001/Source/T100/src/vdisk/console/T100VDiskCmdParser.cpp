#include "T100VDiskCmdParser.h"

#include "T100VDiskHelp.h"
#include "T100Log.h"


T100VDiskCmdParser::T100VDiskCmdParser()
{
    //ctor
}

T100VDiskCmdParser::~T100VDiskCmdParser()
{
    //dtor
}

T100INTEGER T100VDiskCmdParser::parse(T100COMMAND_VECTOR& cmds)
{
    T100INTEGER result;

    if(cmds.empty()){
        return -1;
    }

    T100STDSTRING   cmd;
    T100WORD        size;

    cmd     = cmds[0];
    size    = cmds.size();

    if("help" == cmd){
        if(help()){
            result = 0;
        }else{
            result = -1;
        }
    }else if("create" == cmd){
        switch(size){
        case 4:
            {
                cmd = cmds[1];
                if("vdisk" == cmd){
                    if(create(cmds[2], cmds[3])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else if("file" == cmd){
                    if(fs_create(cmds[2], cmds[3])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else if("dir" == cmd){
                    if(fs_mkdir(cmds[2], cmds[3])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else{
                    result = -1;
                }
            }
            break;
        case 5:
            {
                cmd = cmds[1];
                if("part" == cmd){
                    if(part_create(cmds[2], cmds[3], cmds[4], T100FALSE)){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else{
                    result = -1;
                }
            }
            break;
        case 6:
            {
                cmd = cmds[1];
                if("part" == cmd && "boot" == cmds[3]){
                    if(part_create(cmds[2], cmds[4], cmds[5], T100TRUE)){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("remove" == cmd){
        switch(size){
        case 3:
            {
                cmd = cmds[1];
                if("vdisk" == cmd){
                    if(remove(cmds[2])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else if("part" == cmd){
                    if(part_remove(cmds[2])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else{
                    result = -1;
                }
            }
            break;
        case 4:
            {
                cmd = cmds[1];
                if("file" == cmd){
                    if(fs_remove(cmds[2], cmds[3])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else if("dir" == cmd){
                    if(fs_rmdir(cmds[2], cmds[3])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("set" == cmd){
        switch(size){
        case 5:
            {
                if("part" == cmds[1] && "boot" == cmds[3]){
                    if(part_boot(cmds[2], cmds[4])){
                        result = 0;
                    }else{
                        result = -1;
                    }
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("load" == cmd){
        switch(size){
        case 2:
            {
                if(load(cmds[1])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("list" == cmd){
        switch(size){
        case 1:
            {
                if(part_list()){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        case 3:
            {
                cmd = cmds[1];

                if(fs_list(cmds[1], cmds[2])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("format" == cmd){
        switch(size){
        case 2:
            {
                if(fs_format(cmds[1])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        case 3:
            {
                if(fs_format(cmds[1], cmds[2])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("mkdir" == cmd){
        switch(size){
        case 3:
            {
                if(fs_mkdir(cmds[1], cmds[2])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("chdir" == cmd){
        switch(size){
        case 3:
            {
                if(fs_chdir(cmds[1], cmds[2])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("rmdir" == cmd){
        switch(size){
        case 3:
            {
                if(fs_rmdir(cmds[1], cmds[2])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }else if("copy" == cmd){
        switch(size){
        case 4:
            {
                if(fs_copy(cmds[1], cmds[2], cmds[3])){
                    result = 0;
                }else{
                    result = -1;
                }
            }
            break;
        default:
            result = -1;
        }
    }

    return result;
}

T100BOOL T100VDiskCmdParser::quit()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    if(m_vdisk){
        value = m_vdisk->close();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VDiskCmdParser::help()
{
    T100VDiskHelp   vdisk;

    return vdisk.show();
}

T100BOOL T100VDiskCmdParser::create(T100STDSTRING file, T100STDSTRING value)
{
    T100DWORD   length;

    length  = stol(value);

    m_vdisk = T100NEW T100VDisk(file);

    if(m_vdisk->exists()){
        if(!m_vdisk->remove()){
            return T100FALSE;
        }
    }

    return m_vdisk->create(length);
}

T100BOOL T100VDiskCmdParser::remove(T100STDSTRING file)
{
    T100File    target(file);

    if(target.exists()){
        if(target.remove()){
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100VDiskCmdParser::load(T100STDSTRING file)
{
    if(m_vdisk){
        m_vdisk->close();
        m_vdisk = T100NULL;
    }

    if(!m_vdisk){
        m_vdisk = T100NEW T100VDisk(file);

        if(m_vdisk->open()){
            return T100TRUE;
        }else{
            T100DELETE(m_vdisk);
            m_vdisk = T100NULL;
        }
    }
    return T100FALSE;
}

T100BOOL T100VDiskCmdParser::part_create(T100STDSTRING name, T100STDSTRING start, T100STDSTRING value, T100BOOL boot)
{
    T100DWORD   location;
    T100DWORD   length;
    T100BOOL    result;

    location    = stol(start);
    length      = stol(value);

    result      = m_vdisk->part_create(name, location, length, boot);

    return result;
}

T100BOOL T100VDiskCmdParser::part_remove(T100STDSTRING name)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->part_remove(name);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::part_list()
{
    T100BOOL                result;
    T100VFS_PART_VECTOR     parts;

    result = m_vdisk->part_list(parts);
    if(!result){
        return T100FALSE;
    }

    if(parts.empty()){
        T100Log::info(T100VDiskHint::part_hint());
        return T100TRUE;
    }

    for(auto part : parts){
        T100Log::info(T100VDiskHint::part_hint(part));
    }

    return T100TRUE;
}

T100BOOL T100VDiskCmdParser::part_boot(T100STDSTRING part, T100STDSTRING boot)
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100BOOL        flag;

    if("1" == boot){
        flag = T100TRUE;
    }else if("0" == boot){
        flag = T100FALSE;
    }

    value = m_vdisk->part_boot(part, flag);

    return result;
}

T100BOOL T100VDiskCmdParser::fs_format(T100STDSTRING name)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_format(name);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_format(T100STDSTRING name, T100STDSTRING boot)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_format(name, boot);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_mkdir(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_mkdir(name, path);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_chdir(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_chdir(name, path);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_rmdir(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_rmdir(name, path);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_create(T100STDSTRING name, T100STDSTRING file)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_create(name, file);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_remove(T100STDSTRING name, T100STDSTRING file)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_format(name, file);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_list(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_list(name, path);
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskCmdParser::fs_copy(T100STDSTRING source, T100STDSTRING name, T100STDSTRING target)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = m_vdisk->fs_copy(source, name, target);
    if(!value){
        result = T100FALSE;
    }

    return result;
}
