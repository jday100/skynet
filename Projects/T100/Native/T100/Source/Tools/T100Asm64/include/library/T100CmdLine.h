#ifndef T100CMDLINE_H
#define T100CMDLINE_H

#include "T100Common.h"


class T100CmdLine
{
    public:
        T100CmdLine();
        virtual ~T100CmdLine();

        virtual T100BOOL            parse(int argc, char* argv[]);

    protected:

    private:
};

#endif // T100CMDLINE_H
