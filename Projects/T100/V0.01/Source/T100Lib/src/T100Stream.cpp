#include "T100Stream.h"

#include "T100Unicode.h"


T100Stream::T100Stream(T100WSTRING file)
    :m_file(file)
{
    //ctor
    create();
}

T100Stream::~T100Stream()
{
    //dtor
    destroy();
}

T100VOID T100Stream::create()
{
    m_opened    = T100FALSE;
    m_seek      = 0;
}

T100VOID T100Stream::destroy()
{

}

T100BOOL T100Stream::open()
{
    T100STDSTRING       result;

    result = T100Unicode::to_string8(m_file);

    m_stream = T100NEW std::fstream(result, std::ios::in | std::ios::out | std::ios::binary);

    if(m_stream){
        if(m_stream->is_open()){
            m_opened = T100TRUE;
        }else{
            m_opened = T100FALSE;
            T100SAFE_DELETE(m_stream);
            return T100FALSE;
        }
    }else{
        m_opened = T100FALSE;
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100Stream::close()
{
    if(m_stream){
        m_stream->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_stream);
        //m_file.clear();
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100Stream::opened()
{
    return m_opened;
}

T100BOOL T100Stream::seek(T100DWORD seek)
{
    if(m_opened){
        m_stream->clear();

        if(m_stream->seekp(seek * 4).fail()){
            return T100FALSE;
        }

        if(m_stream->seekg(seek * 4).fail()){
            return T100FALSE;
        }

        m_seek = seek;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Stream::put(T100WORD value)
{
    if(m_opened){
        if(!m_stream->write((T100STDCHAR*)&value, 4).fail()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Stream::get(T100WORD& value)
{
    if(m_opened){
        T100WORD    length;

        length = m_stream->read((T100STDCHAR*)&value, 4).gcount();

        if(4 == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Stream::read(T100WORD* data, T100WORD& length)
{
    if(m_opened){
        T100WORD    size;

        //test
        size = length * 4;

        //T100Log::info(std::to_string(m_fs->tellg()));

        size = m_stream->read((T100STDCHAR*)data, length * 4).gcount();

        //T100Log::debug(T100HintLib::file_hint(this, data, size, T100LIB_HINT_FILE_READ));

        length = size / 4;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100Stream::write(T100WORD* data, T100WORD length)
{
    T100BOOL    value;

    if(m_opened){
        //m_fs->clear();
        //T100Log::info(std::to_string(m_fs->tellp()));

        value = m_stream->write((T100STDCHAR*)data, length * 4).fail();

        //T100Log::debug(T100HintLib::file_hint(this, data, length, T100LIB_HINT_FILE_WRITE));

        if(!value){
            return T100TRUE;
        }
    }
    return T100FALSE;
}
