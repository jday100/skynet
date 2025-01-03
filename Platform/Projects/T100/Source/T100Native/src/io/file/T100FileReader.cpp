#include "T100FileReader.h"

#include "T100Unicode.h"

T100FileReader::T100FileReader()
{
    //ctor
    create();
}

T100FileReader::~T100FileReader()
{
    //dtor
    destroy();
}

T100VOID T100FileReader::create()
{
    m_opened    = T100FALSE;
    m_seek      = 0;
}

T100VOID T100FileReader::destroy()
{
    m_opened    = T100FALSE;
    m_seek      = 0;
}

T100BOOL T100FileReader::open(T100WString filename)
{
    T100STDSTRING       result;

    result      = T100Unicode::to_string8(filename.value());

    m_stream    = T100NEW std::ifstream(result, std::ios::in | std::ios::binary);
    if(m_stream){
        if(m_stream->is_open()){
            m_opened    = T100TRUE;
            m_filename  = filename;
        }else{
            m_opened    = T100FALSE;
            T100SAFE_DELETE m_stream;
            m_stream    = T100NULL;
            return T100FALSE;
        }
    }else{
        m_opened    = T100FALSE;
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100FileReader::close()
{
    if(m_stream){
        m_stream->close();
        m_opened    = T100FALSE;
        T100SAFE_DELETE m_stream;
        m_stream    = T100NULL;
        m_filename.clear();
    }else{
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100FileReader::read(T100WChar* data, T100WORD& length)
{
    T100BOOL        result;
    T100WORD        size;

    if(m_opened){
        size    = m_stream->read((T100STDCHAR*)data, length * 2).gcount();
        length  = size / 2;
        result  = m_stream->bad();

        if(!result){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100FileReader::eof()
{
    if(m_opened){
        return m_stream->eof();
    }
    return T100TRUE;
}

T100BOOL T100FileReader::seek(T100DWORD seek)
{
    if(m_opened){
        m_seek  = seek;
        m_stream->clear();
        if(m_stream->seekg(m_seek * 2).fail()){
            return T100FALSE;
        }
        return T100TRUE;
    }
    return T100FALSE;
}
