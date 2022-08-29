#ifndef T100ASSEMBLYCMDLINEINFO_H
#define T100ASSEMBLYCMDLINEINFO_H

#include "T100CmdLineInfo.h"


class T100AssemblyCmdLineInfo : public T100CmdLineInfo
{
    public:
        T100AssemblyCmdLineInfo();
        virtual ~T100AssemblyCmdLineInfo();

        T100BOOL            TEST            = T100FALSE;
        T100BOOL            UNIT            = T100FALSE;

        T100WSTRING         SOURCE;
        T100WSTRING         TARGET;

    protected:

    private:
};

#endif // T100ASSEMBLYCMDLINEINFO_H
