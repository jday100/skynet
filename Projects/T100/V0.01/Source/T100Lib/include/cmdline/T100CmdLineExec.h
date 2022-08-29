#ifndef T100CMDLINEEXEC_H
#define T100CMDLINEEXEC_H

#include "T100Common.h"
#include "T100CmdLineInfo.h"


class T100CmdLineExec : public T100CmdLineInfo
{
    public:
        T100CmdLineExec();
        virtual ~T100CmdLineExec();

        T100WSTRING         value;

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100CMDLINEEXEC_H
