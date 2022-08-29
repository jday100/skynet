#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100ConsoleCommon.h"
#include "T100CmdParser.h"


class T100Console
{
    public:
        T100Console();
        virtual ~T100Console();

        virtual T100INTEGER     run(T100INTEGER, T100STDCHAR**);
        virtual T100INTEGER     run(T100STDSTRING);
        virtual T100INTEGER     run();

        T100VOID                setCmdParser(T100CmdParser*);

    protected:
        T100BOOL                prompt();
        T100BOOL                getline(T100STDSTRING&);
        T100BOOL                split(T100STDSTRING&, T100COMMAND_VECTOR&);

        T100INTEGER             shell();

        T100BOOL                load(T100INTEGER, T100STDCHAR**, T100COMMAND_VECTOR&);

    private:
        T100CmdParser*          m_parser        = T100NULL;
};

#endif // T100CONSOLE_H
