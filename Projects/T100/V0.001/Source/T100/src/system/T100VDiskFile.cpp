#include "T100VDiskFile.h"

T100VDiskFile::T100VDiskFile(T100STDSTRING file)
    :T100File(T100String(file)), m_stream(file)
{
    //ctor
}

T100VDiskFile::~T100VDiskFile()
{
    //dtor
}

T100BOOL T100VDiskFile::exists()
{
    return T100File::exists();
}

T100BOOL T100VDiskFile::create(T100DWORD length)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD   size;

    if(T100File::exists()){

    }else{
        if(T100File::create()){

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

    value = T100File::open(T100FILE_WRITE);
    if(value){
        value = T100File::seek(m_info.FILE_LENGTH - 1);
        if(value){
            value = T100File::put(0);
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

        value = T100File::close();
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFile::remove()
{
    return T100File::remove();
}

T100BOOL T100VDiskFile::read_head()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VDISK_FILE_HEAD     head;
    T100WORD*               data;
    T100WORD                length;

    data    = head.DATA;
    length  = m_block_size;

    value = T100File::seek(0);
    if(value){
        value = T100File::read(data, length);
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

T100BOOL T100VDiskFile::write_head()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VDISK_FILE_HEAD     head;
    T100WORD*               data;
    T100WORD                length;

    head.INFO   = m_info;
    data        = head.DATA;
    length      = m_block_size;

    value = T100File::seek(0);
    if(value){
        value = T100File::write(data, length);
        if(value){

        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFile::open(T100FILE_MODE mode)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    if(T100File::open(mode)){
        value = read_head();
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskFile::close()
{
    return T100File::close();
}

T100BOOL T100VDiskFile::opened()
{
    return T100File::opened();
}

T100BOOL T100VDiskFile::seek(T100DWORD value)
{
    return T100File::seek(value);
}

T100DWORD T100VDiskFile::length()
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

T100BOOL T100VDiskFile::read(T100DWORD id, T100WORD* data)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD   offset;
    T100WORD    length;

    offset = m_block_size * (id + 1);
    length = m_block_size;

    value = T100File::seek(offset);
    if(value){
        value = T100File::read(data, length);
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskFile::write(T100DWORD id, T100WORD* data)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100DWORD   offset;
    T100WORD    length;

    offset = m_block_size * (id + 1);
    length = m_block_size;

    value = T100File::seek(offset);
    if(value){
        value = T100File::write(data, length);
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}
