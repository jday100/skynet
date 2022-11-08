#ifndef T100CONSOLETERMINAL_H
#define T100CONSOLETERMINAL_H

#include "T100ConsoleBase.h"

namespace T100Library{
class T100ConsoleTerminalThread;
class T100ConsoleTerminalParser;

class T100ConsoleTerminal : public T100ConsoleBase
{
    public:
        T100ConsoleTerminal(T100ConsoleTerminalParser* = T100NULL, T100CONSOLE_TYPE = T100CONSOLE_TYPE_WINDOWS);
        virtual ~T100ConsoleTerminal();

        T100VOID                print(T100WSTRING&);

        T100VOID                outline(T100WSTRING&);
        T100VOID                getline(T100WSTRING&);

        T100VOID                        setParser(T100ConsoleTerminalParser*);
        T100ConsoleTerminalParser*      getParser();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100CONSOLE_TYPE        m_type          = T100CONSOLE_TYPE_WINDOWS;
        T100ConsoleBase*        m_console       = T100NULL;

        T100ConsoleTerminalThread*      m_thread            = T100NULL;
        T100ConsoleTerminalParser*      m_parser            = T100NULL;

};

}

#endif // T100CONSOLETERMINAL_H
