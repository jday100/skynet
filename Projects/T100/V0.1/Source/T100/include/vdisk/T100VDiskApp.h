#ifndef T100VDISKAPP_H
#define T100VDISKAPP_H

#include "T100AppBase.h"

namespace T100VDisk{

class T100VDiskApp : public T100Library::T100AppBase
{
    public:
        T100VDiskApp(T100Library::T100AppManager*);
        virtual ~T100VDiskApp();

    protected:

    private:
};

}

#endif // T100VDISKAPP_H
