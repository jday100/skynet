#include "log/T100LogFile.h"

namespace T100NATIVE{

T100LogFile::T100LogFile(T100WSTRING file) :
    T100LogBase(), m_file(file)
{
    //ctor
    init();
}

T100LogFile::~T100LogFile()
{
    //dtor
    uninit();
}

T100VOID T100LogFile::init()
{
    m_writerPtr = T100NEW T100TextFileWriter(m_file);
    if(m_writerPtr){
        if(m_writerPtr->Open()){

        }else{
            T100SAFE_DELETE(m_writerPtr);
        }
    }
}

T100VOID T100LogFile::uninit()
{
    if(m_writerPtr){
        if(m_writerPtr->Close()){
            T100SAFE_DELETE(m_writerPtr);
        }
    }
}

T100VOID T100LogFile::Outline(T100LOG_TYPE type, T100WSTRING& msg, T100SOURCE_TYPE source)
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

    m_writerPtr->Write(msg);
}

}
