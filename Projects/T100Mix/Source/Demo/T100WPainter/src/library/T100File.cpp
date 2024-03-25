#include "T100File.h"

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

T100BOOL T100File::open()
{
    T100STDSTRING       name;

    m_stream    = T100NEW std::wfstream(name, std::ios::in | std::ios::out | std::ios::binary);

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
    if(m_opened){
        if(m_stream->seekg(seek, std::ios::beg).good()){
            return T100TRUE;
        }
    }else{

    }
    return T100FALSE;
}

T100BOOL T100File::read(T100WORD* data, T100WORD& length)
{
    T100BOOL            result;
    T100WORD            size;

    if(m_opened){
        size    = m_stream->read((T100WCHAR*)data, length).gcount();
        result  = m_stream->good();
        return result;
    }
    return T100FALSE;
}

T100BOOL T100File::write(T100WORD* data, T100WORD length)
{

}
