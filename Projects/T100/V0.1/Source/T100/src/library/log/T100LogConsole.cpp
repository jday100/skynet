#include "T100LogConsole.h"

namespace T100Library{

T100LogConsole::T100LogConsole()
    :T100LogBase()
{
    //ctor
}

T100LogConsole::~T100LogConsole()
{
    //dtor
}

T100VOID T100LogConsole::create()
{

}

T100VOID T100LogConsole::destroy()
{

}

T100VOID T100LogConsole::outline(T100LOG_TYPE type, T100WSTRING& msg, T100SOURCE_TYPE source)
{
    m_console.outline(msg);
}

}
