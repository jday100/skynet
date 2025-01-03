#include "T100LogConsole.h"

T100LogConsole::T100LogConsole()
    :T100LogBase()
{
    //ctor
}

T100LogConsole::~T100LogConsole()
{
    //dtor
}

T100VOID T100LogConsole::outline(T100WString msg)
{
    m_console.outline(msg);
}

T100VOID T100LogConsole::getline(T100WString& msg)
{
    m_console.getline(msg);
}
