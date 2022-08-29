#include "T100VDiskFile.h"

#include "T100String.h"
#include "T100File.h"


T100VDiskFile::T100VDiskFile(T100STRING file)
    :T100File(file.to_wstring())
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

    m_stream = T100NEW T100Stream(getName());
    if(!m_stream){
        return T100FALSE;
    }

    value = m_stream->open();
    if(value){
        value = m_stream->seek(m_info.FILE_LENGTH - 1);
        if(value){
            value = m_stream->put(0);
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

        value = m_stream->close();
        if(!value){
            result = T100FALSE;
        }
        T100SAFE_DELETE(m_stream);
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

    value = m_stream->seek(0);
    if(value){
        value = m_stream->read(data, length);
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

    value = m_stream->seek(0);
    if(value){
        value = m_stream->write(data, length);
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

    if(m_stream){
        return T100FALSE;
    }

    m_stream = T100NEW T100Stream(getName());
    if(!m_stream){
        return T100FALSE;
    }

    if(m_stream->open()){
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
    T100BOOL            result          = T100TRUE;

    result = m_stream->close();
    T100SAFE_DELETE(m_stream);

    return result;
}

T100BOOL T100VDiskFile::opened()
{
    return m_stream->opened();
}

T100BOOL T100VDiskFile::seek(T100DWORD value)
{
    return m_stream->seek(value);
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

    value = m_stream->seek(offset);
    if(value){
        value = m_stream->read(data, length);
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

    value = m_stream->seek(offset);
    if(value){
        value = m_stream->write(data, length);
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}
