#include "T100ConsoleWindows.h"

#include "T100Unicode.h"

T100ConsoleWindows::T100ConsoleWindows()
    :T100ConsoleBase()
{
    //ctor
    create();
}

T100ConsoleWindows::~T100ConsoleWindows()
{
    //dtor
    destroy();
}

T100VOID T100ConsoleWindows::create()
{

}

T100VOID T100ConsoleWindows::destroy()
{

}

T100VOID T100ConsoleWindows::outline(T100WString msg)
{
    wprintf(L"%ls\n", msg.value().c_str());
}

T100VOID T100ConsoleWindows::getline(T100WString& msg)
{
    T100STDCHAR         buffer[1024];
    T100STDCHAR*        ptr;
    T100STDSTRING       line;

    ptr     = buffer;
    gets(ptr);

    line    = ptr;

    msg     = T100Unicode::to_wstring(line);
}
