#include "T100ConsoleLinux.h"

T100ConsoleLinux::T100ConsoleLinux() :
    T100ConsoleBase()
{
    //ctor
}

T100ConsoleLinux::~T100ConsoleLinux()
{
    //dtor
}

T100VOID T100ConsoleLinux::Print(T100WSTRING& msg)
{
    wprintf(L"%ls", msg.c_str());
}

T100VOID T100ConsoleLinux::OutLine(T100WSTRING msg)
{
    wprintf(L"%ls\n", msg.c_str());
}

T100VOID T100ConsoleLinux::GetLine(T100WSTRING& msg)
{
    T100WCHAR       buffer[1024];

    wscanf(L"%ls", buffer);
    msg = buffer;
}
