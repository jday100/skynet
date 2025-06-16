#include "console/T100ConsoleNormal.h"

namespace T100LIBRARY{

T100ConsoleNormal::T100ConsoleNormal() :
    T100ConsoleBase()
{
    //ctor
    init();
}

T100ConsoleNormal::~T100ConsoleNormal()
{
    //dtor
    uninit();
}

T100VOID T100ConsoleNormal::init()
{
    setlocale(LC_ALL, "");
}

T100VOID T100ConsoleNormal::uninit()
{

}

T100VOID T100ConsoleNormal::OutLine(const T100WSTRING& value)
{
    wprintf(L"%ls\n", value.c_str());
}

T100VOID T100ConsoleNormal::GetLine(const T100WSTRING& value)
{
    T100WCHAR       buffer[1024];

    wscanf(L"%ls", buffer);
    value   = buffer;
}

}
