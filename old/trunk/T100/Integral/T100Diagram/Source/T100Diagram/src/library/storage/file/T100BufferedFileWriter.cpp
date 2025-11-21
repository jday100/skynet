#include "T100BufferedFileWriter.h"

#include "T100Unicode.h"

T100BufferedFileWriter::T100BufferedFileWriter(T100WSTRING& path) :
    m_path(path)
{
    //ctor
    init();
}

T100BufferedFileWriter::~T100BufferedFileWriter()
{
    //dtor
    uninit();
}

T100VOID T100BufferedFileWriter::init()
{
    m_opened        = T100FALSE;
    m_seek          = 0;
}

T100VOID T100BufferedFileWriter::uninit()
{

}

T100BOOL T100BufferedFileWriter::Open()
{
    T100STRING          result;

    result  = T100Unicode::ToString8(m_path);

    m_ofs   = T100NEW std::ofstream(result, std::ios::out | std::ios::binary);

    if(m_ofs){
        if(m_ofs->is_open()){
            m_opened = T100TRUE;
        }else{
            m_opened = T100FALSE;
            T100SAFE_DELETE(m_ofs);
            return T100FALSE;
        }
    }else{
        m_opened = T100FALSE;
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100BufferedFileWriter::Close()
{
    if(m_ofs){
        m_ofs->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_ofs);
        m_path.clear();
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100BufferedFileWriter::IsOpened()
{
    return m_opened;
}

T100BOOL T100BufferedFileWriter::Eof()
{
    if(m_opened){
        return m_ofs->eof();
    }
    return T100FALSE;
}

T100BOOL T100BufferedFileWriter::Seek(T100UINT64 seek)
{
    if(m_opened){
        m_seek = seek;

        m_ofs->clear();

        if(m_ofs->seekp(m_seek * 1).fail()){
            return T100FALSE;
        }

        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100BufferedFileWriter::Write(T100BYTE* data, T100UINT length)
{
    T100BOOL        result;

    if(m_opened){
        result = m_ofs->write((T100CHAR*)data, length).fail();

        if(!result){
            return T100TRUE;
        }
    }

    return T100FALSE;
}
