#include "T100VDiskPart.h"

#include <cstring>
#include "T100StringTools.h"


T100VDiskPart::T100VDiskPart(T100VDiskFile* vdisk)
    :m_vdisk(vdisk)
{
    //ctor
    start();
}

T100VDiskPart::~T100VDiskPart()
{
    //dtor
    stop();
}

T100VOID T100VDiskPart::start()
{
    memset((void*)&m_parts, 0, sizeof(m_parts));
}

T100VOID T100VDiskPart::stop()
{

}

T100BOOL T100VDiskPart::load()
{

    if(m_vdisk->read(0, m_parts.DATA)){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VDiskPart::save()
{
    if(m_vdisk->write(0, m_parts.DATA)){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VDiskPart::create(T100String name, T100DWORD location, T100DWORD length, T100BOOL boot)
{
    T100BOOL    result      = T100FALSE;

    T100VFS_PART*   part    = T100NULL;

    part = search(name);
    if(part){
        return T100FALSE;
    }

    if(0 == location || length < 4){
        return T100FALSE;
    }

    for(int i=0;i<T100VFS_PART_SIZE;i++){
        if(0 == m_parts.PARTS[i].USED){
            if(!T100StringTools::copy(m_parts.PARTS[i].LABEL, name.getRawData(), 16)){
                return T100FALSE;
            }

            m_parts.PARTS[i].LOCATION   = location;
            m_parts.PARTS[i].LENGTH     = length;
            m_parts.PARTS[i].USED       = 1;
            if(boot){
                m_parts.PARTS[i].BOOT   = 1;
            }else{
                m_parts.PARTS[i].BOOT   = 0;
            }

            if(save()){
                return T100TRUE;
            }else{
                m_parts.PARTS[i].USED       = 0;
                return T100FALSE;
            }
        }
    }


    return result;
}

T100BOOL T100VDiskPart::remove(T100String name)
{
    T100BOOL    result      = T100FALSE;

    for(int i=0;i<T100VFS_PART_SIZE;i++){
        if(1 == m_parts.PARTS[i].USED){
            if(T100StringTools::compare(m_parts.PARTS[i].LABEL, 16, name)){
                //m_parts.PARTS[i].LOCATION   = T100VFS_ITEM_END;
                //m_parts.PARTS[i].LENGTH     = 0;
                m_parts.PARTS[i].USED           = 0;

                if(save()){
                    return T100TRUE;
                }else{
                    m_parts.PARTS[i].USED       = 1;
                    return T100FALSE;
                }
            }
        }
    }

    return result;
}

T100BOOL T100VDiskPart::list(T100VFS_PART_VECTOR& parts)
{
    for(int i=0;i<T100VFS_PART_SIZE;i++){
        if(1 == m_parts.PARTS[i].USED){
            T100VFS_PART* part = T100NEW T100VFS_PART;

            memcpy(part->LABEL, m_parts.PARTS[i].LABEL, sizeof(T100VFS_PART::LABEL));
            *part = m_parts.PARTS[i];

            parts.push_back(*part);
        }
    }
    return T100TRUE;
}

T100BOOL T100VDiskPart::boot(T100String name, T100BOOL boot)
{
    T100BOOL    result      = T100FALSE;

    T100WORD        value;
    T100VFS_PART*   part    = T100NULL;

    part = search(name);
    if(!part){
        return T100FALSE;
    }

    value = part->BOOT;
    if(boot){
        part->BOOT  = 1;
    }else{
        part->BOOT  = 0;
    }

    if(save()){
        return T100TRUE;
    }else{
        part->BOOT  = value;
        return T100FALSE;
    }

    return result;
}

T100VFS_PART* T100VDiskPart::search(T100String name)
{
    T100VFS_PART*   result      = T100NULL;

    for(int i=0;i<T100VFS_PART_SIZE;i++){
        if(1 == m_parts.PARTS[i].USED){
            if(T100StringTools::compare(m_parts.PARTS[i].LABEL, 16, name)){
                result = &(m_parts.PARTS[i]);
                return result;
            }
        }
    }

    return result;
}

