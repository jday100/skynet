#ifndef T100CMDLINEINFO_H
#define T100CMDLINEINFO_H

#include "T100CmdLineCommon.h"


class T100CmdLineInfo
{
    public:
        T100CmdLineInfo();
        virtual ~T100CmdLineInfo();

        T100CMDLINE_TYPE            type            = T100CMDLINE_NONE;

    protected:

    private:
};

#endif // T100CMDLINEINFO_H
