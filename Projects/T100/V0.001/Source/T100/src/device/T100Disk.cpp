#include "T100Disk.h"

#include "T100Log.h"
#include "T100VPCSetup.h"
#include "T100HintQU32.h"
#include "T100Manager32.h"


T100Disk::T100Disk(T100String file)
{
    //ctor
    create(file);
}

T100Disk::~T100Disk()
{
    //dtor
    destroy();
}

T100VOID T100Disk::create(T100String file)
{
    T100Log::trace(T100DEVICE_HINT_DISK_LOAD);

    m_inited = T100FALSE;

    if(file.empty()){
        file = T100String(T100VPCSetup::getVDiskFile());
    }
    if(!file.empty()){
        m_vdisk = T100NEW T100VDisk(file.to_std_string());
        if(m_vdisk){
            if(m_vdisk->open()){
                m_inited = T100TRUE;
            }
        }
    }

    T100Log::debug(T100DEVICE_HINT_DISK_LOADED);
}

T100VOID T100Disk::destroy()
{
    if(!m_inited)return;

    if(m_loaded){
        if(unload()){

        }
    }

    m_vdisk->close();
    T100DELETE(m_vdisk);

    T100Log::trace(T100DEVICE_HINT_DISK_UNLOAD);
}

T100BOOL T100Disk::isInited()
{
    return m_inited;
}

T100BOOL T100Disk::load(IManager* m)
{
    return load((T100Manager32*)m);
}

T100BOOL T100Disk::load(T100Manager32* m)
{
    T100WORD    size;
    T100BOOL    result;

    m_manager       = m;
    size            = 1024;

    if(!m_inited || m_loaded){
        return T100FALSE;
    }

    result = m->allotBlock(this, size, m_block);
    if(result){
        m_loaded = T100TRUE;
    }

    T100Log::debug(T100DEVICE_HINT_DISK_LOADED);

    return result;
}

T100BYTE* T100Disk::getData()
{
    if(!m_loaded){
        return T100NULL;
    }

    T100DEVICE_BLOCK* block = getManager32()->getBlock(m_block[0]);

    if(block){
        return (T100BYTE*)block->data;
    }

    return T100NULL;
}

T100WORD T100Disk::in(T100WORD offset)
{
    T100WORD result = 0;

    if(!m_loaded){
        return result;
    }

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

void T100Disk::out(T100WORD offset, T100WORD value)
{
    if(!m_loaded){
        return;
    }

    if(offset >= 4)return;

    switch(offset){
    case 0:
        {
            switch(value)
            {
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_DISK;
                    m_data[2] = 1;
                    m_data[3] = 0;
                }
                break;
            case T100DISKMODE_TYPE:
                {
                    m_data[1] = 1;
                    m_data[2] = 0;
                    m_data[3] = 32;
                }
                break;
            case T100DISKMODE_GET:
                {
                    T100DWORD_BITS temp;

                    temp.DWORD = m_vdisk->length();

                    m_data[1] = 1024;
                    m_data[2] = temp.WORD_LOW.WORD;
                    m_data[3] = temp.WORD_HIGH.WORD;
                }
                break;
            case T100DISKMODE_BLOCK:
                {
                    T100WORD bid;
                    T100WORD offset;

                    bid = m_block[0];
                    offset = bid * 1024;

                    m_data[1] = offset;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100DISKMODE_READ:
                {
                    T100DWORD_BITS  id;

                    id.WORD_LOW.WORD    = m_data[1];
                    id.WORD_HIGH.WORD   = m_data[2];


                    read(id.DWORD, m_data[3]);
                }
                break;
            case T100DISKMODE_WRITE:
                {
                    T100DWORD_BITS  id;

                    id.WORD_LOW.WORD    = m_data[1];
                    id.WORD_HIGH.WORD   = m_data[2];

                    write(id.DWORD, m_data[3]);
                }
                break;
            };
        }
        break;
    default:
        m_data[offset] = value;
    };
}

T100WORD T100Disk::in(T100WORD id, T100WORD offset)
{
    T100WORD value;
    T100DEVICE_BLOCK* block;

    if(!m_loaded){
        return 0;
    }

    block = getManager32()->getBlock(id);
    value = block->data[offset];

    return value;
}

T100VOID T100Disk::out(T100WORD id, T100WORD offset, T100WORD value)
{
    T100DEVICE_BLOCK* block;

    if(!m_loaded){
        return;
    }

    block = getManager32()->getBlock(id);
    block->data[offset] = value;
}

T100BOOL T100Disk::read(T100DWORD id, T100WORD index)
{
    T100BOOL            result      = T100TRUE;
    T100WORD            bid;
    T100DWORD           offset;
    T100WORD            length;
    T100DEVICE_BLOCK*   block       = T100NULL;
    T100WORD*           data;

    if(!m_loaded){
        return T100FALSE;
    }

    if(0 == m_block.size() || 16 <= index){
        return T100FALSE;
    }

    bid     = m_block[0];
    block   = getManager32()->getBlock(bid);
    if(!block){
        return T100FALSE;
    }

    if(m_id == id && m_readed){

    }else{
        data    = (T100WORD*)&m_buffer;
        result  = m_vdisk->read(id, data);
        if(result){
            m_id        = id;
            m_readed    = T100TRUE;
        }else{
            return T100FALSE;
        }
    }

    T100WORD*   source;
    T100WORD*   target;

    offset  = 1024 * index;
    length  = 1024;

    source  = (T100WORD*)&m_buffer + offset;
    target  = block->data;

    memcpy(target, source, 1024 * 4);

    return result;
}

T100BOOL T100Disk::write(T100DWORD id, T100WORD index)
{
    T100BOOL            result      = T100TRUE;
    T100WORD            bid;
    T100DWORD           offset;
    T100WORD            length;
    T100DEVICE_BLOCK*   block       = T100NULL;
    T100WORD*           data;

    if(!m_loaded){
        return T100FALSE;
    }

    if(0 == m_block.size() || 16 <= index){
        return T100FALSE;
    }

    bid     = m_block[0];
    block   = getManager32()->getBlock(bid);
    if(!block){
        return T100FALSE;
    }

    if(m_id == id && m_readed){

    }else{
        data    = (T100WORD*)&m_buffer;
        result  = m_vdisk->read(id, data);
        if(result){
            m_id        = id;
            m_readed    = T100TRUE;
        }else{
            return T100FALSE;
        }
    }

    T100WORD*   source;
    T100WORD*   target;

    offset  = 1024 * index;
    length  = 1024;

    target  = (T100WORD*)&m_buffer + offset;
    source  = block->data;

    memcpy(target, source, 1024 * 4);

    data    = (T100WORD*)&m_buffer;
    result  = m_vdisk->write(id, data);

    return result;
}
