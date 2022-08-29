#include "T100LogAppenderFile.h"

T100LogAppenderFile::T100LogAppenderFile(T100WSTRING file)
    :m_file(file)
{
    //ctor
    create();
}

T100LogAppenderFile::~T100LogAppenderFile()
{
    //dtor
    destroy();
}

T100VOID T100LogAppenderFile::create()
{
    m_writer = T100NEW T100TextFileWriter(m_file);
}

T100VOID T100LogAppenderFile::destroy()
{
    if(m_writer){
        m_writer->close();
    }
}

T100VOID T100LogAppenderFile::outline(T100WORD type, T100WSTRING msg)
{
    T100WORD*       data;
    T100WORD        length;

    m_writer->write(data, length);
}
