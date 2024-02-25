#include "T100File.h"

T100File::T100File(T100STRING file)
    :m_filename(file)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::create()
{
    m_fs    = T100NEW std::fstream(m_filename, std::ios::out | std::ios::in | std::ios::binary | std::ios::trunc);

    if(m_fs){
        if(m_fs->is_open()){
            return T100TRUE;
        }else{
            T100DELETE m_fs;
            m_fs    = T100NULL;
            return T100FALSE;
        }
    }

    return T100FALSE;
}

T100BOOL T100File::remove()
{
    if(m_fs){
        if(m_fs->is_open()){
            m_fs->close();
        }
    }

    T100INT32       result      = 0;

    result  = ::remove(m_filename.c_str());

    if(0 == result){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100File::open()
{
    if(m_fs){
        if(m_fs->is_open()){
            return T100TRUE;
        }else{
            m_fs->open(m_filename, std::ios::in | std::ios::out | std::ios::binary);

            return m_fs->is_open();
        }
    }else{
        return create();
    }
}

T100BOOL T100File::close()
{
    if(m_fs){
        m_fs->close();
        if(m_fs->is_open()){

        }else{
            T100DELETE m_fs;
            m_fs    = T100NULL;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100File::read(T100BYTE* data, T100INT32& length)
{
    T100INT32       result          = 0;

    if(m_fs){
        char* buffer = (char*)data;
        result  = m_fs->read(buffer, length).gcount();
        if(result == length){
            return T100TRUE;
        }else{
            length  = result;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100File::write(T100BYTE* data, T100INT32 length)
{
    if(m_fs){
        const char* buffer = const_cast<const char*>((char*)data);
        return m_fs->write(buffer, length).good();
    }

    return T100FALSE;
}

T100BOOL T100File::seek(T100INT64 offset)
{
    if(m_fs){
        m_fs->seekg(offset);
        m_fs->seekp(offset);
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100File::state_seek(T100INT64 offset, T100FILE_CALLBACK run, T100VOID* data)
{
    if(m_fs){
        if(run){
            m_cancel    = T100FALSE;
            T100INT64   value   = 128LL * 1024 * 1024;
            T100INT64   index   = 0LL;
            T100BYTE    range;

            value   = value > offset ? offset : value;
            for(T100INT64 i=0LL;i<offset;i+=value){
                m_fs->seekg(value, std::ios_base::seekdir::_S_cur);
                index   += value;
                range   = (index * 100) / offset;
                run(data, range);
                if(m_cancel){
                    return T100FALSE;
                }
            }

            //m_fs->seekg(offset, std::ios_base::seekdir::_S_beg);
        }else{
            m_fs->seekg(offset);
        }
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100File::state_cancel()
{
    m_cancel    = T100TRUE;
}
