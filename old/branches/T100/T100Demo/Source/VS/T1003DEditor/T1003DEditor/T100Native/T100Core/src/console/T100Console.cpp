#include "console/T100Console.h"

#include "console/T100AllLogs.h"

namespace T100NATIVE{

T100Console::T100Console(T100CONSOLE_TYPE type) :
    m_type(type)
{
    //ctor
    init();
}

T100Console::~T100Console()
{
    //dtor
    uninit();
}

T100VOID T100Console::init()
{
    switch(m_type){
    case T100CONSOLE_TYPE_LOG:
        {
            m_consolePtr    = T100NEW T100ConsoleLog();
        }
        break;
    case T100CONSOLE_TYPE_LINUX:
        {
            m_consolePtr    = T100NEW T100ConsoleLinux();
        }
        break;
    case T100CONSOLE_TYPE_WINDOWS:
    default:
        {
            m_consolePtr    = T100NEW T100ConsoleWindows();
        }
        break;
    }
}

T100VOID T100Console::uninit()
{
    T100SAFE_DELETE m_consolePtr;
}

T100VOID T100Console::Outline(T100WSTRING& msg)
{
    m_consolePtr->Outline(msg);
}

T100VOID T100Console::Getline(T100WSTRING& msg)
{
    m_consolePtr->Getline(msg);
}

}
