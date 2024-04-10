#include "T100StdFile.h"

#include "T100Unicode.h"

T100StdFile::T100StdFile(T100STRING filename)
    :m_filename(filename)
{
    //ctor
    create();
}

T100StdFile::~T100StdFile()
{
    //dtor
    destroy();
}

T100VOID T100StdFile::create()
{
    m_opened    = T100FALSE;
}

T100VOID T100StdFile::destroy()
{

}

T100BOOL T100StdFile::opened()
{
    return m_opened;
}

T100BOOL T100StdFile::eof()
{
    if(m_stream){
        return m_stream->eof();
    }
    return T100TRUE;
}

T100BOOL T100StdFile::open()
{
    T100STDSTRING       name;

    name        = T100Unicode::to_string8(m_filename);
    m_stream    = T100NEW std::fstream(name, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

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

T100BOOL T100StdFile::close()
{
    if(m_stream){
        m_stream->close();
        m_opened    = T100FALSE;
        T100DELETE  m_stream;
        m_stream    = T100NULL;
        m_filename.clear();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100StdFile::seek(T100DWORD seek)
{
    T100BOOL        result;
    if(m_opened){
        result  = m_stream->seekg(seek, std::ios::beg).good();
        result  = m_stream->seekp(seek, std::ios::beg).good() ? result : T100FALSE;

        return result;
    }
    return T100FALSE;
}

T100BOOL T100StdFile::read(T100CHAR* data, T100WORD& length)
{
    T100BOOL        result;
    T100WORD        size;

    if(m_opened){
        size    = m_stream->read(data, length).gcount();
        result  = m_stream->good();
        return result;
    }
    return T100FALSE;
}

T100BOOL T100StdFile::write(T100CHAR* data, T100WORD length)
{
    T100BOOL        result;

    if(m_opened){
        result  = m_stream->write(data, length).good();
        return result;
    }
    return T100FALSE;
}
