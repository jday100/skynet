#include "console/T100ConsoleLinux.h"

namespace T100NATIVE{

T100ConsoleLinux::T100ConsoleLinux() :
    T100ConsoleBase()
{
    //ctor
    init();
}

T100ConsoleLinux::~T100ConsoleLinux()
{
    //dtor
    uninit();
}

T100VOID T100ConsoleLinux::init()
{
    //setlocale(LC_ALL, "");
}

T100VOID T100ConsoleLinux::uninit()
{

}

T100VOID T100ConsoleLinux::Print(T100WSTRING& msg)
{
    wprintf(L"%ls", msg.c_str());
}

T100VOID T100ConsoleLinux::Outline(T100WSTRING& msg)
{
    wprintf(L"%ls\n", msg.c_str());
}

T100VOID T100ConsoleLinux::Getline(T100WSTRING& msg)
{
    T100WCHAR       buffer[1024];

    wscanf(L"%ls", buffer);
    msg = buffer;
}

}
