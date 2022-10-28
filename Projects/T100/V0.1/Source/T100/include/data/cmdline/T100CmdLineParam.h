#ifndef T100CMDLINEPARAM_H
#define T100CMDLINEPARAM_H

#include "T100Common.h"
#include "T100StringTypes.h"
#include "T100CmdLineInfo.h"

namespace T100Library{

class T100CmdLineParam : public T100CmdLineInfo
{
    public:
        T100CmdLineParam();
        virtual ~T100CmdLineParam();

        T100WSTRING         value;

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100CMDLINEPARAM_H
