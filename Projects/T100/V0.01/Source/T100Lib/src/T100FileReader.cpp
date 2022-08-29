#include "T100FileReader.h"

#include "T100Unicode.h"


T100FileReader::T100FileReader(T100WSTRING file)
    :m_file(file)
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
    m_opened = T100FALSE;
}

T100VOID T100FileReader::destroy()
{

}

T100BOOL T100FileReader::open()
{
    T100STDSTRING   result;

    result = T100Unicode::to_string8(m_file);

    m_ifs = T100NEW std::ifstream(result, std::ios::out | std::ios::binary);

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

T100BOOL T100FileReader::close()
{
    if(m_ifs){
        m_ifs->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_ifs);
        m_file.clear();
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100FileReader::opened()
{
    return m_opened;
}

T100BOOL T100FileReader::seek(T100DWORD seek)
{
    if(m_opened){
        m_seek = seek;

        m_ifs->clear();

        if(m_ifs->seekg(m_seek * 4).fail()){
            return T100FALSE;
        }

        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100FileReader::read(T100WORD* data, T100WORD& length)
{
    T100BOOL        result;

    if(m_opened){
        result = m_ifs->read((T100STDCHAR*)data, length * 4).fail();

        if(!result){
            return T100TRUE;
        }
    }

    return T100FALSE;
}
