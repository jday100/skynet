#ifndef T100VDISKCONSOLEAPP_H
#define T100VDISKCONSOLEAPP_H

#include "T100AppBase.h"

namespace T100VDisk{
class T100VDiskConsole;

class T100VDiskConsoleApp : public T100Library::T100AppBase
{
    friend class T100VDiskConsole;
    public:
        T100VDiskConsoleApp(T100Library::T100AppManager*, T100BOOL = T100FALSE);
        virtual ~T100VDiskConsoleApp();

        T100BOOL                run();

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100VDiskConsole*       m_console           = T100NULL;

    private:
        T100VOID                quit();

};

}

#endif // T100VDISKCONSOLEAPP_H
