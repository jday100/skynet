#include "T100WinConsole.h"

#include <iostream>
#include <windows.h>


T100WinConsole::T100WinConsole()
{
    //ctor
}

T100WinConsole::~T100WinConsole()
{
    //dtor
}

T100VOID T100WinConsole::setColour(T100COLOUR_TYPE colour)
{
    T100WORD    result          = 0;

    switch(colour)
    {
    case T100COLOUR_BLACK:
        {
            break;
        }
    case T100COLOUR_NONE:
    case T100COLOUR_WHITE:
        {
            result = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        }
    case T100COLOUR_RED:
        {
            result = FOREGROUND_RED;
            break;
        }
    case T100COLOUR_GREEN:
        {
            result = FOREGROUND_GREEN;
            break;
        }
    case T100COLOUR_BLUE:
        {
            result = FOREGROUND_BLUE;
            break;
        }
    case T100COLOUR_ORANGE:
        {
            result = FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        }
    case T100COLOUR_YELLOW:
        {
            result = FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        }
    case T100COLOUR_PURPLE:
        {
            result = FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        }
    }

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(INVALID_HANDLE_VALUE == handle)return;

    SetConsoleTextAttribute(handle, result);
}

T100VOID T100WinConsole::out(T100STDSTRING& msg)
{
    std::cout << msg << std::endl;
}
