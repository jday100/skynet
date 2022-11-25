#ifndef T100VDISKCONSOLE_H
#define T100VDISKCONSOLE_H

#include "T100AppBase.h"

namespace T100VDisk{

class T100VDiskConsole : public ::T100Library::T100AppBase
{
    public:
        T100VDiskConsole(T100Library::T100AppManager*);
        virtual ~T100VDiskConsole();

        T100BOOL                run();

    protected:

    private:
};

}

#endif // T100VDISKCONSOLE_H
