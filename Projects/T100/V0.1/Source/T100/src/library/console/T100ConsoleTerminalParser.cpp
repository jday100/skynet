#include "T100ConsoleTerminalParser.h"

#include "T100StringTools.h"
#include "T100ConsoleTerminal.h"

namespace T100Library{

T100ConsoleTerminalParser::T100ConsoleTerminalParser()
{
    //ctor
}

T100ConsoleTerminalParser::~T100ConsoleTerminalParser()
{
    //dtor
}

T100VOID T100ConsoleTerminalParser::setConsole(T100ConsoleTerminal* console)
{
    m_console = console;
}

T100ConsoleTerminal* T100ConsoleTerminalParser::getConsole()
{
    return m_console;
}

T100BOOL T100ConsoleTerminalParser::prompt()
{
    T100WSTRING     msg;

    msg = T100CONSOLE_PROMPT_DEFAULT;

    m_console->print(msg);

    return T100TRUE;
}

T100BOOL T100ConsoleTerminalParser::split(T100WSTRING& line, T100CONSOLE_COMMAND_VECTOR& cmds)
{
    T100BOOL        result          = T100TRUE;
    T100WSTRING     mask;

    mask    = T100CONSOLE_SEPARATOR_DEFAULT;

    result  = T100StringTools::split(line, mask, cmds);

    return result;
}

T100BOOL T100ConsoleTerminalParser::parse(T100CONSOLE_COMMAND_VECTOR& cmds)
{
    return T100FALSE;
}

}
