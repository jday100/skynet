#ifndef T100CONSOLETERMINALPARSER_H
#define T100CONSOLETERMINALPARSER_H

#include "T100ConsoleCommon.h"

namespace T100Library{
class T100ConsoleTerminal;

class T100ConsoleTerminalParser
{
    friend class T100ConsoleTerminal;
    friend class T100ConsoleTerminalThread;
    public:
        T100ConsoleTerminalParser();
        virtual ~T100ConsoleTerminalParser();

        T100VOID                    setConsole(T100ConsoleTerminal*);
        T100ConsoleTerminal*        getConsole();

    protected:
        virtual T100BOOL            prompt();
        virtual T100BOOL            split(T100WSTRING&, T100CONSOLE_COMMAND_VECTOR&);
        virtual T100BOOL            parse(T100CONSOLE_COMMAND_VECTOR&);

        virtual T100BOOL            quit();

    private:
        T100ConsoleTerminal*        m_console           = T100NULL;

};

}

#endif // T100CONSOLETERMINALPARSER_H
