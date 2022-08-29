#ifndef T100CMDPARSER_H
#define T100CMDPARSER_H

#include "T100ConsoleCommon.h"


class T100CmdParser
{
    public:
        T100CmdParser();
        virtual ~T100CmdParser();

        virtual T100INTEGER             parse(T100COMMAND_VECTOR&);
        virtual T100BOOL                quit();

    protected:

    private:
};

#endif // T100CMDPARSER_H
