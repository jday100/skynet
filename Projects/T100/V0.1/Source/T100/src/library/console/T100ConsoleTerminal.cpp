#include "T100ConsoleTerminal.h"

#include "T100ConsoleLinux.h"
#include "T100ConsoleWindows.h"
#include "T100ConsoleTerminalParser.h"
#include "T100ConsoleTerminalThread.h"

namespace T100Library{

T100ConsoleTerminal::T100ConsoleTerminal(T100ConsoleTerminalParser* parser, T100CONSOLE_TYPE type)
    :T100ConsoleBase(),
    m_parser(parser),
    m_type(type)
{
    //ctor
    create();
}

T100ConsoleTerminal::~T100ConsoleTerminal()
{
    //dtor
    destroy();
}

T100VOID T100ConsoleTerminal::create()
{
    switch(m_type){
    case T100CONSOLE_TYPE_LINUX:
        {
            m_console = T100NEW T100ConsoleWindows();
        }
        break;
    default:
        m_console = T100NEW T100ConsoleWindows();
    }

    if(!m_parser){
        m_parser = T100NEW T100ConsoleTerminalParser();
    }
    m_parser->setConsole(this);

    m_thread = T100NEW T100ConsoleTerminalThread(this);
    m_thread->start();
}

T100VOID T100ConsoleTerminal::destroy()
{
    T100SAFE_DELETE(m_console);
}

T100VOID T100ConsoleTerminal::setParser(T100ConsoleTerminalParser* parser)
{
    m_parser = parser;
}

T100ConsoleTerminalParser* T100ConsoleTerminal::getParser()
{
    return m_parser;
}

T100VOID T100ConsoleTerminal::print(T100WSTRING& msg)
{
    m_console->print(msg);
}

T100VOID T100ConsoleTerminal::outline(T100WSTRING& msg)
{
    m_console->outline(msg);
}

T100VOID T100ConsoleTerminal::getline(T100WSTRING& msg)
{
    m_console->getline(msg);
}

}
