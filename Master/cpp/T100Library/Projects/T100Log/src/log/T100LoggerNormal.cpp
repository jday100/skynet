#include "log/T100LoggerNormal.h"

namespace T100LIBRARY{

T100LoggerNormal::T100LoggerNormal() :
    T100LoggerBase()
{
    //ctor
    init(L"logger.log");
}

T100LoggerNormal::T100LoggerNormal(const T100WSTRING& filename) :
    T100LoggerBase()
{
    //ctor
    init(filename);
}

T100LoggerNormal::~T100LoggerNormal()
{
    //dtor
    uninit();
}

T100VOID T100LoggerNormal::init(const T100WSTRING& filename)
{
    m_textFile      = T100NEW T100TextFile(filename);

    if(m_textFile){
        m_writer    = m_textFile->CreateWriterW();
    }
}

T100VOID T100LoggerNormal::uninit()
{
    if(m_textFile){
        if(m_writer){
            m_textFile->DestroyWriterW(m_writer);
        }
        T100SAFE_DELETE(m_textFile);
    }
}

T100VOID T100LoggerNormal::Out(const T100WSTRING& value)
{
    *m_writer << value;
}

}
