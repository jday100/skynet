#include "T100WindowsConsole.h"

#include <iostream>

T100WindowsConsole::T100WindowsConsole()
    :T100ConsoleBase()
{
    //ctor
}

T100WindowsConsole::~T100WindowsConsole()
{
    //dtor
}

T100BOOL T100WindowsConsole::out(T100WString msg)
{
    //std::cout << msg << std::endl;
    std::wcout << msg.data() << std::endl;
    return T100FALSE;
}

T100BOOL T100WindowsConsole::in(T100WString& in)
{
    return T100FALSE;
}
