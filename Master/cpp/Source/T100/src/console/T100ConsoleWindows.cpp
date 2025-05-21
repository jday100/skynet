#include "console/T100ConsoleWindows.h"

#include <windows.h>
#include "string/T100Unicode.h"

T100ConsoleWindows::T100ConsoleWindows() :
    T100ConsoleBase()
{
    //ctor
}

T100ConsoleWindows::~T100ConsoleWindows()
{
    //dtor
}

T100VOID T100ConsoleWindows::Print(T100WSTRING& msg)
{
    wprintf(L"%ls", msg.c_str());
}

T100VOID T100ConsoleWindows::OutLine(T100WSTRING msg)
{
    wprintf(L"%ls\n", msg.c_str());
}

T100VOID T100ConsoleWindows::GetLine(T100WSTRING& msg)
{
    T100STDCHAR         buffer[1024];
    T100STDCHAR*        ptr;
    T100STDSTRING       line;

    ptr     = buffer;
    gets(ptr);

    line    = ptr;

    msg     = T100Unicode::to_wstring(line);
}

T100VOID T100ConsoleWindows::SetForegroundColour(T100COLOUR_TYPE type)
{
    T100WORD    colour          = 0;

    switch(type){
    case T100COLOUR_TYPE_BLACK:
        {
            colour = 0;
        }
        break;
    case T100COLOUR_TYPE_WHITE:
        {
            colour = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_TYPE_RED:
        {
            colour = FOREGROUND_RED;
        }
        break;
    case T100COLOUR_TYPE_GREEN:
        {
            colour = FOREGROUND_GREEN;
        }
        break;
    case T100COLOUR_TYPE_BLUE:
        {
            colour = FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_TYPE_YELLOW:
        {
            colour = FOREGROUND_RED | FOREGROUND_GREEN;
        }
        break;
    case T100COLOUR_TYPE_PURPLE:
        {
            colour = FOREGROUND_RED | FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_TYPE_CYAN:
        {
            colour = FOREGROUND_BLUE | FOREGROUND_GREEN;
        }
        break;
    default:
        break;
    }

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(INVALID_HANDLE_VALUE == handle)return;

    WINBOOL result = SetConsoleTextAttribute(handle, colour);

    if(result){
        T100ConsoleBase::SetForegroundColour(type);
    }
}
