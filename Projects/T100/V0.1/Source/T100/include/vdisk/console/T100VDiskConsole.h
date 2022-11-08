#ifndef T100VDISKCONSOLE_H
#define T100VDISKCONSOLE_H

#include "T100App.h"

namespace T100VDisk{

class T100VDiskConsole : public T100Library::T100App
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
