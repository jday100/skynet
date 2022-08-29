#include "T100Stream.h"

#include "T100Log.h"
#include "T100HintLib.h"


T100Stream::T100Stream(T100STDSTRING file)
    :m_file(file)
{
    //ctor
}

T100Stream::~T100Stream()
{
    //dtor
}

T100BOOL T100Stream::open(T100FILE_MODE mode)
{
    if(m_opened){
        return T100FALSE;
    }

    switch(mode)
    {
    case T100FILE_READ:
        {
            m_fs = T100NEW std::fstream(m_file, std::ios::in | std::ios::binary);
        }
        break;
    case T100FILE_WRITE:
        {
            m_fs = T100NEW std::fstream(m_file, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
        }
        break;
    case T100FILE_READWRITE:
        {
            m_fs = T100NEW std::fstream(m_file, std::ios::in | std::ios::out | std::ios::binary);
        }
        break;
    default:
        return T100FALSE;
    }

    if(m_fs->is_open()){
        m_opened = T100TRUE;
        return T100TRUE;
    }

    T100DELETE(m_fs);
    m_fs    = T100NULL;

    return T100FALSE;
}

T100BOOL T100Stream::close()
{
    if(m_opened){
        m_fs->close();
        T100DELETE(m_fs);
        m_fs        = T100NULL;
        m_opened    = T100FALSE;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100Stream::opened()
{
    return m_opened;
}

T100BOOL T100Stream::seek(T100DWORD seek)
{
    if(m_opened){

        m_fs->clear();
        if(m_fs->seekg(seek * 4, std::ios::beg).fail()){
            return T100FALSE;
        }
        if(m_fs->seekp(seek * 4, std::ios::beg).fail()){
            return T100FALSE;
        }

        m_seek = seek;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Stream::get(T100WORD& value)
{
    if(m_opened){
        T100WORD    length;

        length = m_fs->read((T100STDCHAR*)&value, 4).gcount();

        if(4 == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Stream::put(T100WORD value)
{
    if(m_opened){
        if(!m_fs->write((T100STDCHAR*)&value, 4).fail()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Stream::read(T100WORD* data, T100WORD& length)
{
    if(m_opened){
        T100WORD    size;

        //test
        size = length * 4;

        T100Log::info(std::to_string(m_fs->tellg()));

        size = m_fs->read((T100STDCHAR*)data, length * 4).gcount();

        length = size / 4;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100Stream::write(T100WORD* data, T100WORD& length)
{
    T100BOOL    value;

    if(m_opened){
        //m_fs->clear();
        T100Log::info(std::to_string(m_fs->tellp()));

        value = m_fs->write((T100STDCHAR*)data, length * 4).fail();

        //test
        T100Log::info(m_fs->bad()?"bad:true":"bad::false");
        T100Log::info(m_fs->badbit==1?"badbit:true":"badbit::false");
        T100Log::info(m_fs->eof()?"eof:true":"eof::false");
        T100Log::info(m_fs->eofbit==1?"eofbit:true":"eofbit::false");
        T100Log::info(m_fs->fail()?"fail:true":"fail::false");
        T100Log::info(m_fs->failbit==1?"failbit:true":"failbit::false");
        T100Log::info(m_fs->good()?"good:true":"good::false");
        T100Log::info(m_fs->goodbit==1?"goodbit:true":"goodbit::false");

        if(!value){
            return T100TRUE;
        }
    }
    return T100FALSE;
}
