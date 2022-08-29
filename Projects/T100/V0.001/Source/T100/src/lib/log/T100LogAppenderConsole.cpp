#include "T100LogAppenderConsole.h"

#include "T100WinConsole.h"


T100LogAppenderConsole::T100LogAppenderConsole()
{
    //ctor
}

T100LogAppenderConsole::~T100LogAppenderConsole()
{
    //dtor
}

T100VOID T100LogAppenderConsole::out(T100LOG_TYPE type, T100STDSTRING msg)
{
    switch(type)
    {
    case T100LOG_TYPE_FATAL:
        {
            T100WinConsole::setColour(T100COLOUR_RED);
        }
        break;
    }

    T100WinConsole::out(msg);
    T100WinConsole::setColour(T100COLOUR_WHITE);

}
