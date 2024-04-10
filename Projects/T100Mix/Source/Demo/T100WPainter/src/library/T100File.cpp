#include "T100File.h"

#include "T100Unicode.h"

T100File::T100File(T100STRING filename)
    :m_filename(filename)
{
    //ctor
    create();
}

T100File::~T100File()
{
    //dtor
    destroy();
}

T100VOID T100File::create()
{
    m_opened    = T100FALSE;
}

T100VOID T100File::destroy()
{

}

T100BOOL T100File::opened()
{
    return m_opened;
}

T100BOOL T100File::eof()
{
    if(m_stream){
        return m_stream->eof();
    }
    return T100TRUE;
}

T100BOOL T100File::open()
{
    T100STDSTRING       name;

    name    = T100Unicode::to_string8(m_filename);
    m_stream    = T100NEW std::fstream(name, std::ios::in | std::ios::out | std::ios::binary);

    if(m_stream){
        if(m_stream->is_open()){
            m_opened    = T100TRUE;
            return T100TRUE;
        }else{
            m_opened    = T100FALSE;
            T100DELETE  m_stream;
            m_stream    = T100NULL;
        }
    }else{
        m_opened    = T100FALSE;
    }
    return T100FALSE;
}

T100BOOL T100File::close()
{
    if(m_stream){
        m_stream->close();
        m_opened    = T100FALSE;
        T100DELETE  m_stream;
        m_stream    = T100NULL;
        m_filename.clear();
        return T100TRUE;
    }else{

    }
    return T100FALSE;
}

T100BOOL T100File::seek(T100DWORD seek)
{
    T100BOOL            result;
    if(m_opened){
        result  = m_stream->seekg(seek, std::ios::beg).good();
        result  = m_stream->seekp(seek, std::ios::beg).good() ? result : T100FALSE;
    }else{
        result  = T100FALSE;
    }
    return result;
}

T100BOOL T100File::read(T100WCHAR* data, T100WORD& length)
{
    T100BOOL            result;
    T100WORD            size;

    if(m_opened){
        size    = m_stream->read((T100STDCHAR*)data, length * 2).gcount();
        result  = m_stream->good();
        length  = size / 2;
        return result;
    }
    return T100FALSE;
}

T100BOOL T100File::write(T100WCHAR* data, T100WORD length)
{
    T100BOOL            result;

    if(m_opened){
        result  = m_stream->write((T100STDCHAR*)data, length * 2).good();
        return result;
    }
    return T100FALSE;
}
