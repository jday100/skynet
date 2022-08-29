#include "T100File.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include "T100Log.h"
#include "T100HintLib.h"


T100File::T100File(T100String file)
    :m_file(file)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::exists()
{
    T100INTEGER result;

    result = ::_access(m_file.to_std_string().c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100File::create()
{
    T100INTEGER result;

    result = ::_creat(m_file.to_std_string().c_str(), _S_IRWXU);

    if(-1 == result){

    }else{
        result = ::_close(result);

        if(-1 == result){

        }else{
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100File::remove()
{
    T100INTEGER result;

    result = ::remove(m_file.to_std_string().c_str());

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100File::open(T100FILE_MODE mode)
{
    if(m_opened){
        return T100FALSE;
    }

    T100Log::debug(T100HintLib::file_hint(this, T100LIB_HINT_FILE_OPEN));

    switch(mode)
    {
    case T100FILE_READ:
        {
            m_fs = T100NEW std::fstream(m_file.to_std_string(), std::ios::in | std::ios::binary);
        }
        break;
    case T100FILE_WRITE:
        {
            m_fs = T100NEW std::fstream(m_file.to_std_string(), std::ios::out | std::ios::binary | std::ios::trunc);
        }
        break;
    case T100FILE_READWRITE:
        {
            m_fs = T100NEW std::fstream(m_file.to_std_string(), std::ios::in | std::ios::out | std::ios::binary);
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

T100BOOL T100File::close()
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

T100BOOL T100File::opened()
{
    return m_opened;
}

T100BOOL T100File::seek(T100DWORD seek)
{
    if(m_opened){
        m_seek = seek;

        m_fs->clear();
        if(m_fs->seekg(m_seek * 4/*, std::ios::beg*/).fail()){
            return T100FALSE;
        }
        if(m_fs->seekp(m_seek * 4).fail()){
            return T100FALSE;
        }

        return T100TRUE;
    }

    return T100FALSE;
}

T100DWORD T100File::length()
{
    if(!m_opened){
        struct _stat64i32 state;
        int i = ::_stat(m_file.to_std_string().c_str(), &state);
        if(-1 == i){

        }else{
            m_length = state.st_size / 4;
        }
    }

    return m_length;
}

T100BOOL T100File::get(T100WORD& value)
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

T100BOOL T100File::put(T100WORD value)
{
    if(m_opened){
        if(!m_fs->write((T100STDCHAR*)&value, 4).fail()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100File::read(T100WORD* data, T100WORD& length)
{
    if(m_opened){
        T100WORD    size;

        //test
        size = length * 4;

        T100Log::info(std::to_string(m_fs->tellg()));

        size = m_fs->read((T100STDCHAR*)data, length * 4).gcount();

        T100Log::debug(T100HintLib::file_hint(this, data, size, T100LIB_HINT_FILE_READ));

        length = size / 4;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100File::write(T100WORD* data, T100WORD& length)
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

        T100Log::debug(T100HintLib::file_hint(this, data, length, T100LIB_HINT_FILE_WRITE));

        if(!value){
            return T100TRUE;
        }
    }
    return T100FALSE;
}
