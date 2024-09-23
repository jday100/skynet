#include "T100Console.h"

#include "T100WindowsConsole.h"

T100Console::T100Console()
{
    //ctor
}

T100Console::~T100Console()
{
    //dtor
}

T100BOOL T100Console::out(T100WString msg)
{
    T100WindowsConsole          console;

    console.out(msg);

    return T100FALSE;
}
