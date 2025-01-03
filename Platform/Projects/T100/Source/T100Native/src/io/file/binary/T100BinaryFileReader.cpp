#include "T100BinaryFileReader.h"

#include "T100Unicode.h"

T100BinaryFileReader::T100BinaryFileReader()
{
    //ctor
    create();
}

T100BinaryFileReader::~T100BinaryFileReader()
{
    //dtor
    destroy();
}

T100VOID T100BinaryFileReader::create()
{
    m_opened    = T100FALSE;
    m_seek      = 0;
}

T100VOID T100BinaryFileReader::destroy()
{
    m_opened    = T100FALSE;
    m_seek      = 0;
}

T100BOOL T100BinaryFileReader::open(T100WString filename)
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

T100BOOL T100BinaryFileReader::close()
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

T100BOOL T100BinaryFileReader::read(T100BYTE* data, T100WORD& length)
{
    T100BOOL        result;
    T100WORD        size;

    if(m_opened){
        size    = m_stream->read((T100STDCHAR*)data, length).gcount();
        length  = size;
        result  = m_stream->bad();

        if(!result){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100BinaryFileReader::eof()
{
    if(m_opened){
        return m_stream->eof();
    }
    return T100TRUE;
}

T100BOOL T100BinaryFileReader::seek(T100DWORD seek)
{
    if(m_opened){
        m_seek  = seek;
        m_stream->clear();
        if(m_stream->seekg(seek).fail()){
            return T100FALSE;
        }
        return T100TRUE;
    }
    return T100FALSE;
}
