#ifndef T100DEVICEINFO_H
#define T100DEVICEINFO_H

#include "T100Common.h"
#include "T100String.h"
#include "T100DeviceTypes.h"


namespace T100VPC{

class T100DeviceInfo
{
    public:
        T100DeviceInfo();
        virtual ~T100DeviceInfo();

        T100Component::T100DEVICE_TYPE         type            = T100Component::T100DEVICE_NONE;
        T100STRING              name;

    protected:

    private:
};

}

#endif // T100DEVICEINFO_H
