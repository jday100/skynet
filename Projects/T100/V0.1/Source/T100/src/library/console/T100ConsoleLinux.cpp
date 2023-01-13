#include "T100ConsoleLinux.h"

namespace T100Library{

T100ConsoleLinux::T100ConsoleLinux()
    :T100ConsoleBase()
{
    //ctor
    create();
}

T100ConsoleLinux::~T100ConsoleLinux()
{
    //dtor
    destroy();
}

T100VOID T100ConsoleLinux::create()
{
    //setlocale(LC_ALL, "");
}

T100VOID T100ConsoleLinux::destroy()
{

}

T100VOID T100ConsoleLinux::print(T100WSTRING& msg)
{
    wprintf(L"%ls", msg.c_str());
}

T100VOID T100ConsoleLinux::outline(T100WSTRING& msg)
{
    wprintf(L"%ls\n", msg.c_str());
}

T100VOID T100ConsoleLinux::getline(T100WSTRING& msg)
{
    T100WCHAR       buffer[1024];

    wscanf(L"%ls", buffer);
    msg = buffer;
}

}
