#include "T100ConsoleWindows.h"

#include <windows.h>


T100ConsoleWindows::T100ConsoleWindows()
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
    setlocale(LC_ALL, "");
}

T100VOID T100ConsoleWindows::destroy()
{

}

T100VOID T100ConsoleWindows::setForegroundColour(T100COLOUR_PRIMITIVE_TYPE type)
{
    T100WORD    colour      = 0;

    switch(type){
    case T100COLOUR_BLACK:
        {
            colour = 0;
        }
        break;
    case T100COLOUR_WHITE:
        {
            colour = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_RED:
        {
            colour = FOREGROUND_RED;
        }
        break;
    case T100COLOUR_GREEN:
        {
            colour = FOREGROUND_GREEN;
        }
        break;
    case T100COLOUR_BLUE:
        {
            colour = FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_ORANGE:
        {
            colour = FOREGROUND_RED | FOREGROUND_GREEN;
        }
        break;
    case T100COLOUR_YELLOW:
        {
            colour = FOREGROUND_RED | FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_PURPLE:
        {
            colour = FOREGROUND_BLUE | FOREGROUND_GREEN;
        }
        break;
    default:
        break;
    };

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(INVALID_HANDLE_VALUE == handle)return;

    WINBOOL result = SetConsoleTextAttribute(handle, colour);

    if(result){
        T100ConsoleBase::setForegroundColour(type);
    }

}

T100VOID T100ConsoleWindows::outline(T100WSTRING& msg)
{
    wprintf(L"%ls\n", msg.c_str());
}

T100VOID T100ConsoleWindows::getline(T100WSTRING& msg)
{
    T100WCHAR       buffer[1024];

    wscanf(L"%ls", buffer);
    msg = buffer;
}
