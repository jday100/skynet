#include "T100BufferedFileReader.h"

#include "T100Unicode.h"

T100BufferedFileReader::T100BufferedFileReader(T100WSTRING& path) :
    m_path(path)
{
    //ctor
    init();
}

T100BufferedFileReader::~T100BufferedFileReader()
{
    //dtor
    uninit();
}

T100VOID T100BufferedFileReader::init()
{
    m_opened        = T100FALSE;
    m_seek          = 0;
}

T100VOID T100BufferedFileReader::uninit()
{

}

T100BOOL T100BufferedFileReader::Open()
{
    T100STRING          result;

    result  = T100Unicode::ToString8(m_path);

    m_ifs   = T100NEW std::ifstream(result, std::ios::in | std::ios::binary);

    if(m_ifs){
        if(m_ifs->is_open()){
            m_opened = T100TRUE;
        }else{
            m_opened = T100FALSE;
            T100SAFE_DELETE(m_ifs);
            return T100FALSE;
        }
    }else{
        m_opened = T100FALSE;
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100BufferedFileReader::Close()
{
    if(m_ifs){
        m_ifs->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_ifs);
        m_path.clear();
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100BufferedFileReader::IsOpened()
{
    return m_opened;
}

T100BOOL T100BufferedFileReader::Eof()
{
    if(m_opened){
        return m_ifs->eof();
    }
    return T100FALSE;
}

T100BOOL T100BufferedFileReader::Seek(T100UINT64 seek)
{
    if(m_opened){
        m_seek = seek;

        m_ifs->clear();

        if(m_ifs->seekg(m_seek * 1).fail()){
            return T100FALSE;
        }

        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100BufferedFileReader::Read(T100BYTE* data, T100UINT& length)
{
    T100BOOL        result;
    T100UINT        size;

    if(m_opened){
        size    = m_ifs->read((T100CHAR*)data, length).gcount();
        length  = size;
        result  = m_ifs->bad();

        if(!result){
            return T100TRUE;
        }
    }

    return T100FALSE;
}
