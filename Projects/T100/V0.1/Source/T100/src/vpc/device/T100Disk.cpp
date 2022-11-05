#include "T100Disk.h"

#include "T100QU32.h"
#include "T100VPCSetup.h"

namespace T100VPC{

T100Disk::T100Disk(T100QU32* host, T100STRING file)
    :T100BlockDevice(host),
    m_file(file)
{
    //ctor
    create();
}

T100Disk::~T100Disk()
{
    //dtor
    destroy();
}

T100VOID T100Disk::create()
{
    if(m_file.empty()){
        m_file = T100VPCSetup::getVDiskFile();
    }
    if(m_file.empty()){
        return;
    }else{
        m_vdisk = T100NEW T100VDisk(m_file);
        if(m_vdisk){
            if(m_vdisk->open()){
                m_inited = T100TRUE;
            }else{
                return;
            }
        }
    }

    m_port = m_host->getPort32();
    m_port->appendDevice(m_id, this);
}

T100VOID T100Disk::destroy()
{
    if(!m_inited)return;

    if(m_loaded){
        unload();
    }

    m_port->removeDevice(m_id);

    if(m_vdisk){
        m_vdisk->close();
        T100SAFE_DELETE(m_vdisk);
    }
}

T100BOOL T100Disk::load(T100Port32* port)
{
    T100BOOL        result;
    T100WORD        size;

    size = 1024;

    if((!m_inited) || m_loaded){
        return T100FALSE;
    }

    result = m_port->allotBlock(this, size, m_blocks);
    if(result){
        m_loaded = T100TRUE;
    }
    return result;
}

T100BOOL T100Disk::unload()
{
    return T100TRUE;
}

T100BOOL T100Disk::in(T100WORD offset, T100WORD& value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    value = m_data[offset];
    return T100TRUE;
}

T100BOOL T100Disk::out(T100WORD offset, T100WORD value)
{
    T100BOOL        result          = T100TRUE;

    if(offset >= 4){
        return T100FALSE;
    }

    switch(offset){
    case 0:
        {
            m_data[0] = value;

            switch(value){
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
                    T100DWORD_BITS      length;

                    length.DWORD    = m_vdisk->length();

                    m_data[1] = 1024;
                    m_data[2] = length.WORD_LOW.WORD;
                    m_data[3] = length.WORD_HIGH.WORD;
                }
                break;
            case T100DISKMODE_BLOCK:
                {
                    T100WORD        id;
                    T100WORD        offset;

                    id      = m_blocks[0];
                    offset  = id * 1024;

                    m_data[1] = offset;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100DISKMODE_READ:
                {
                    T100DWORD_BITS      id;

                    id.WORD_LOW.WORD    = m_data[1];
                    id.WORD_HIGH.WORD   = m_data[2];

                    result = read(id.DWORD, m_data[3]);
                }
                break;
            case T100DISKMODE_WRITE:
                {
                    T100DWORD_BITS      id;

                    id.WORD_LOW.WORD    = m_data[1];
                    id.WORD_HIGH.WORD   = m_data[2];

                    result = write(id.DWORD, m_data[3]);
                }
                break;
            }
        }
        break;
    default:
        m_data[offset] = value;
    }
    return result;
}

T100BOOL T100Disk::read(T100DWORD id, T100WORD index)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            bid;
    T100DWORD           offset;
    T100WORD            length;
    T100DEVICE_BLOCK*   block           = T100NULL;
    T100WORD*           data;

    if(!m_loaded){
        return T100FALSE;
    }

    if(0 == m_blocks.size() || 16 <= index){
        return T100FALSE;
    }

    bid     = m_blocks[0];
    block   = getPort32()->getBlock(bid);
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

    T100WORD*       source;
    T100WORD*       target;

    offset  = 1024 * index;
    length  = 1024;

    source  = (T100WORD*)&m_buffer + offset;
    target  = block->data;

    memcpy(target, source, 1024 * 4);

    return result;
}

T100BOOL T100Disk::write(T100DWORD id, T100WORD index)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            bid;
    T100DWORD           offset;
    T100WORD            length;
    T100DEVICE_BLOCK*   block           = T100NULL;
    T100WORD*           data;

    if(!m_loaded){
        return T100FALSE;
    }

    if((0 == m_blocks.size()) || (16 <= index){
        return T100FALSE;
    }

    bid         = m_blocks[0];
    block       = GetPort32()->getBlock(bid);
    if(!block){
        return T100FALSE;
    }

    if(m_id == id && m_readed){

    }else{
        data        = (T100WORD*)&m_buffer;
        result      = m_vdisk->read(id, data);
        if(result){
            m_id        = id;
            m_readed    = T100TRUE;
        }else{
            return T100FALSE;
        }
    }

    T100WORD*       source;
    T100WORD*       target;

    offset  = 1024 * index;
    length  = 1024;

    target  = (T100WORD*)&m_buffer + offset;
    source  = block->data;

    memcpy(target, source, 1024 * 4);

    data    = (T100WORD*)&m_buffer;
    result  = m_vdisk->write(id, data);

    return result;
}

}
