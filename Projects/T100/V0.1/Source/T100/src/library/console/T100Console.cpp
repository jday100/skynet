#include "T100Console.h"

#include "T100ConsoleLog.h"
#include "T100ConsoleLinux.h"
#include "T100ConsoleWindows.h"


namespace T100Library{

T100Console::T100Console(T100CONSOLE_TYPE type)
    :T100Class(), m_type(type)
{
    //ctor
    create();
}

T100Console::~T100Console()
{
    //dtor
    destroy();
}

T100VOID T100Console::create()
{
    switch(m_type){
    case T100CONSOLE_TYPE_LOG:
        {
            m_console = T100NEW T100ConsoleLog();
        }
        break;
    case T100CONSOLE_TYPE_LINUX:
        {
            m_console = T100NEW T100ConsoleLinux();
        }
        break;
    case T100CONSOLE_TYPE_WINDOWS:
    default:
        {
            m_console = T100NEW T100ConsoleWindows();
        }
        break;
    }
}

T100VOID T100Console::destroy()
{
    T100SAFE_DELETE(m_console);
}

T100VOID T100Console::outline(T100WSTRING& msg)
{
    m_console->outline(msg);
}

T100VOID T100Console::getline(T100WSTRING& msg)
{
    m_console->getline(msg);
}

}
