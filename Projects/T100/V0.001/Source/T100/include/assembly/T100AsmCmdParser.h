#ifndef T100ASMCMDPARSER_H
#define T100ASMCMDPARSER_H

#include "T100AsmCommon.h"
#include "T100CmdParser.h"


class T100AsmCmdParser : public T100CmdParser
{
    public:
        T100AsmCmdParser();
        virtual ~T100AsmCmdParser();

        T100INTEGER             parse(T100COMMAND_VECTOR&);

    protected:
        T100BOOL                quit();
        T100BOOL                step();
        T100BOOL                run();

        T100BOOL                log(T100STDSTRING);
        T100BOOL                detail(T100STDSTRING);
        T100BOOL                show(T100STDSTRING);
        T100BOOL                show(T100STDSTRING, T100STDSTRING);

    private:
};

#endif // T100ASMCMDPARSER_H
