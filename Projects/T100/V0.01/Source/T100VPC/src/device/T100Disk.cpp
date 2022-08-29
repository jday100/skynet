#include "T100Disk.h"

T100Disk::T100Disk(T100QU32* host)
    :T100BlockDevice(host)
{
    //ctor
}

T100Disk::~T100Disk()
{
    //dtor
}

T100BOOL T100Disk::load(T100Port32* port)
{
    return T100TRUE;
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

                    read(id.DWORD, m_data[3]);
                }
                break;
            case T100DISKMODE_WRITE:
                {
                    T100DWORD_BITS      id;

                    id.WORD_LOW.WORD    = m_data[1];
                    id.WORD_HIGH.WORD   = m_data[2];

                    write(id.DWORD, m_data[3]);
                }
                break;
            }
        }
        break;
    default:
        m_data[offset] = value;
    }

    return T100TRUE;
}

T100BOOL T100Disk::read(T100DWORD offset, T100WORD length)
{

}

T100BOOL T100Disk::write(T100DWORD offset, T100WORD length)
{

}
