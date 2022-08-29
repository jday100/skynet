#ifndef T100DEVICEINFO_H
#define T100DEVICEINFO_H

#include "T100DeviceTypes.h"
#include "T100String.h"


class T100DeviceInfo
{
    public:
        T100DeviceInfo();
        virtual ~T100DeviceInfo();

        T100DEVICE_TYPE         type            = T100DEVICE_NONE;
        T100String              name;

    protected:

    private:

};

#endif // T100DEVICEINFO_H
