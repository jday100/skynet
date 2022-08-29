#include "T100FileWriter.h"

#include "T100Unicode.h"


T100FileWriter::T100FileWriter(T100WSTRING file)
    :m_file(file)
{
    //ctor
    create();
}

T100FileWriter::~T100FileWriter()
{
    //dtor
    destroy();
}

T100VOID T100FileWriter::create()
{
    m_opened = T100FALSE;
}

T100VOID T100FileWriter::destroy()
{

}

T100BOOL T100FileWriter::open()
{
    T100STDSTRING   result;

    result = T100Unicode::to_string8(m_file);

    m_ofs = T100NEW std::ofstream(result, std::ios::out | std::ios::binary);

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

T100BOOL T100FileWriter::close()
{
    if(m_ofs){
        m_ofs->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_ofs);
        m_file.clear();
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100FileWriter::opened()
{
    return m_opened;
}

T100BOOL T100FileWriter::seek(T100DWORD seek)
{
    if(m_opened){
        m_seek = seek;

        m_ofs->clear();

        if(m_ofs->seekp(m_seek * 4).fail()){
            return T100FALSE;
        }

        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100FileWriter::write(T100WORD* data, T100WORD length)
{
    T100BOOL        result;

    if(m_opened){
        result = m_ofs->write((T100STDCHAR*)data, length * 4).fail();

        if(!result){
            return T100TRUE;
        }
    }

    return T100FALSE;
}
