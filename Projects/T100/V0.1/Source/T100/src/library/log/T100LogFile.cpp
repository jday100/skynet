#include "T100LogFile.h"

namespace T100Library{

T100LogFile::T100LogFile(T100WSTRING file)
    :T100LogBase(), m_file(file)
{
    //ctor
    create();
}

T100LogFile::~T100LogFile()
{
    //dtor
    destroy();
}

T100VOID T100LogFile::create()
{
    m_writer = T100NEW T100TextFileWriter(m_file);
    if(m_writer){
        if(m_writer->open()){

        }else{
            T100SAFE_DELETE(m_writer);
        }
    }
}

T100VOID T100LogFile::destroy()
{
    if(m_writer){
        if(m_writer->close()){
            T100SAFE_DELETE(m_writer);
        }
    }
}

T100VOID T100LogFile::outline(T100LOG_TYPE type, T100WSTRING& msg, T100SOURCE_TYPE source)
{
    T100WSTRING     target;
    T100WORD        size;
    T100WORD*       data            = T100NULL;
    T100WORD        length;

    size    = msg.size() + msg.size() % 2;
    target  = msg;
    target.resize(size);

    data    = (T100WORD*)(target.data());
    length  = size / 2;

    m_writer->write(data, length);
}

}
