#include "log/T100Logger.h"

#include "log/T100LoggerNormal.h"

namespace T100LIBRARY{

T100Logger::T100Logger() :
    T100Class()
{
    //ctor
    init();
}

T100Logger::~T100Logger()
{
    //dtor
    uninit();
}

T100VOID T100Logger::init()
{
    m_logger    = T100NEW T100LoggerNormal();
}

T100VOID T100Logger::uninit()
{
    T100SAFE_DELETE(m_logger);
}

T100VOID T100Logger::Out(const T100WSTRING& value)
{
    m_logger->Out(value);
}

}
