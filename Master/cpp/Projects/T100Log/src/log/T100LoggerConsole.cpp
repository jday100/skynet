#include "log/T100LoggerConsole.h"

T100LoggerConsole::T100LoggerConsole() :
    T100LogBase()
{
    //ctor
}

T100LoggerConsole::~T100LoggerConsole()
{
    //dtor
}

T100VOID T100LoggerConsole::OutLine(T100LOG_TYPE type, T100WSTRING& value, T100SOURCE_TYPE source)
{
    m_console.OutLine(value);
}
