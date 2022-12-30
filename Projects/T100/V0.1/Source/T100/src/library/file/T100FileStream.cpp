#include "T100FileStream.h"

#include "T100Unicode.h"

namespace T100Library{

T100FileStream::T100FileStream(T100WSTRING file)
    :T100Stream(), m_file(file)
{
    //ctor
    create();
}

T100FileStream::~T100FileStream()
{
    //dtor
    destroy();
}

T100VOID T100FileStream::create()
{
    m_opened    = T100FALSE;
    m_seek      = 0;
}

T100VOID T100FileStream::destroy()
{

}

T100BOOL T100FileStream::open()
{
    T100STDSTRING       result;

    result      = T100Unicode::to_string8(m_file);

    m_stream    = T100NEW std::fstream(result, std::ios::in | std::ios::out | std::ios::binary);

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

T100BOOL T100FileStream::close()
{
    if(m_stream){
        m_stream->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_stream);
    }else{
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100FileStream::opened()
{
    return m_opened;
}

T100BOOL T100FileStream::seek(T100DWORD seek)
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

T100BOOL T100FileStream::put(T100WORD value)
{
    if(m_opened){
        if(!m_stream->write((T100STDCHAR*)&value, 4).fail()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100FileStream::get(T100WORD& value)
{
    if(m_opened){
        T100WORD        length;

        length = m_stream->read((T100STDCHAR*)&value, 4).gcount();

        if(4 == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100FileStream::read(T100WORD* data, T100WORD& length)
{
    T100WORD        value;

    if(m_opened){
        value   = m_stream->read((T100STDCHAR*)data, length * 4).gcount();

        length  = value / 4;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100FileStream::write(T100WORD* data, T100WORD length)
{
    T100WORD        value;

    if(m_opened){
        value = m_stream->write((T100STDCHAR*)data, length * 4).fail();
        if(!value){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

}
