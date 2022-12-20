#ifndef T100VDISKCONSOLE_H
#define T100VDISKCONSOLE_H

#include "T100AppBase.h"

namespace T100VDisk{
class T100VDiskConsoleApp;

class T100VDiskConsole
{
    public:
        T100VDiskConsole(T100VDiskConsoleApp* = T100NULL);
        virtual ~T100VDiskConsole();

        T100BOOL                    run();

    protected:

    private:
        T100VDiskConsoleApp*        m_app           = T100NULL;

};

}

#endif // T100VDISKCONSOLE_H
