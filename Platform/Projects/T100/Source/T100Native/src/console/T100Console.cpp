#include "T100Console.h"

#ifdef __WINDOWS__
    #include "windows/console/T100ConsoleWindows.h"
#else

#endif // __WINDOWS__

T100Console::T100Console()
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
#ifdef __WINDOWS__
    m_console   = T100NEW T100ConsoleWindows();
#else

#endif // __WINDOWS__
}

T100VOID T100Console::destroy()
{
    T100SAFE_DELETE m_console;
}

T100VOID T100Console::outline(T100WString msg)
{
    m_console->outline(msg);
}

T100VOID T100Console::getline(T100WString& msg)
{
    m_console->getline(msg);
}
