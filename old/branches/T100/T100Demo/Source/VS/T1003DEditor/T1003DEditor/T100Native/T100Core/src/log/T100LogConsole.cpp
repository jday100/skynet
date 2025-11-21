#include "log/T100LogConsole.h"

namespace T100NATIVE{

T100LogConsole::T100LogConsole() :
    m_console()
{
    //ctor
    init();
}

T100LogConsole::~T100LogConsole()
{
    //dtor
    uninit();
}

T100VOID T100LogConsole::init()
{

}

T100VOID T100LogConsole::uninit()
{

}

T100VOID T100LogConsole::Outline(T100LOG_TYPE type, T100WSTRING& msg, T100SOURCE_TYPE source)
{
    m_console.Outline(msg);
}

}
