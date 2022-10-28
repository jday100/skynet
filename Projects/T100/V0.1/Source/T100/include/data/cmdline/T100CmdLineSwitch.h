#ifndef T100CMDLINESWITCH_H
#define T100CMDLINESWITCH_H

#include "T100Common.h"
#include "T100StringTypes.h"
#include "T100CmdLineInfo.h"

namespace T100Library{

class T100CmdLineSwitch : public T100CmdLineInfo
{
    public:
        T100CmdLineSwitch();
        virtual ~T100CmdLineSwitch();

        T100WCHAR           value;

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100CMDLINESWITCH_H
