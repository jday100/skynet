#include "T100VDiskFileNew.h"

T100VDiskFileNew::T100VDiskFileNew(T100STDSTRING file)
    :m_file(file), m_stream(file)
{
    //ctor
}

T100VDiskFileNew::~T100VDiskFileNew()
{
    //dtor
}

T100BOOL T100VDiskFileNew::exists()
{
    return m_file.exists();
}

T100BOOL T100VDiskFileNew::create(T100DWORD length)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD   size;

    if(m_file.exists()){

    }else{
        if(m_file.create()){

        }else{
            return T100FALSE;
        }
    }

    m_info.LENGTH               = length;
    m_info.BLOCK_LENGTH         = T100VDISK_DATA_LENGTH;
    m_info.DATA_LENGTH          = length * T100VDISK_DATA_LENGTH;
    size                        = sizeof(T100VDISK_INFO);
    m_info.PHYSICAL_LEGNTH      = size + m_info.DATA_LENGTH * 4;
    m_info.FILE_LENGTH          = m_info.PHYSICAL_LEGNTH / 4;

    value = m_stream.open(T100FILE_WRITE);
    if(value){
        value = m_stream.seek(m_info.FILE_LENGTH - 1);
        if(value){
            value = m_stream.put(0);
            if(value){
                value = write_head();
                if(!value){
                    result = T100FALSE;
                }
            }else{
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }

        value = m_stream.close();
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFileNew::remove()
{
    return m_file.remove();
}

T100BOOL T100VDiskFileNew::read_head()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VDISK_FILE_HEAD     head;
    T100WORD*               data;
    T100WORD                length;

    data    = head.DATA;
    length  = m_block_size;

    value = m_stream.seek(0);
    if(value){
        value = m_stream.read(data, length);
        if(value){
            m_info = head.INFO;
        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFileNew::write_head()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VDISK_FILE_HEAD     head;
    T100WORD*               data;
    T100WORD                length;

    head.INFO   = m_info;
    data        = head.DATA;
    length      = m_block_size;

    value = m_stream.seek(0);
    if(value){
        value = m_stream.write(data, length);
        if(value){

        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFileNew::open(T100FILE_MODE mode)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    if(m_stream.open(mode)){
        value = read_head();
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskFileNew::close()
{
    return m_stream.close();
}

T100BOOL T100VDiskFileNew::opened()
{
    return m_stream.opened();
}

T100BOOL T100VDiskFileNew::seek(T100DWORD value)
{
    return m_stream.seek(value);
}

T100DWORD T100VDiskFileNew::length()
{
    T100DWORD   result      = 0;

    if(opened()){
        return m_info.DATA_LENGTH;
    }else{
        if(open(T100FILE_READ)){
            if(read_head()){
                result = m_info.DATA_LENGTH;
            }
            if(close()){

            }
        }
    }
    return result;
}

T100BOOL T100VDiskFileNew::read(T100DWORD id, T100WORD* data)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD   offset;
    T100WORD    length;

    offset = m_block_size * (id + 1);
    length = m_block_size;

    value = m_stream.seek(offset);
    if(value){
        value = m_stream.read(data, length);
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFileNew::write(T100DWORD id, T100WORD* data)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD   offset;
    T100WORD    length;

    offset = m_block_size * (id + 1);
    length = m_block_size;

    value = m_stream.seek(offset);
    if(value){
        value = m_stream.write(data, length);
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}
