#include "T100ConsoleTerminalThread.h"

#include "T100String.h"
#include "T100ConsoleTerminalParser.h"

namespace T100Library{

T100ConsoleTerminalThread::T100ConsoleTerminalThread(T100ConsoleTerminal* console)
    :T100Thread(), m_console(console)
{
    //ctor
}

T100ConsoleTerminalThread::~T100ConsoleTerminalThread()
{
    //dtor
}

T100VOID T100ConsoleTerminalThread::run()
{
    T100STRING                      msg;
    T100WSTRING                     line;
    T100CONSOLE_COMMAND_VECTOR      cmds;

    msg = L"Test";

    do{
        m_console->getParser()->prompt();

        m_console->getline(line);

        if(L"quit" == line){
            return;
        }

        m_console->getParser()->split(line, cmds);

        m_console->getParser()->parse(cmds);

        //Test
        sleep(100);
    }while(T100TRUE);
}

}
