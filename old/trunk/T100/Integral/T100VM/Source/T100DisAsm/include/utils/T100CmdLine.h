#ifndef T100CMDLINE_H
#define T100CMDLINE_H

#include "T100Common.h"

typedef struct {
    T100STRING      FILE;
    T100UINT        OFFSET;
}T100CmdLineInfo;

class T100CmdLine
{
    public:
        T100CmdLine();
        virtual ~T100CmdLine();

        T100CmdLineInfo*            Parse(int, char**);

    protected:

    private:
};

#endif // T100CMDLINE_H
