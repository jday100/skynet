#ifndef T100DISPLAYINFO_H
#define T100DISPLAYINFO_H

#include "T100DeviceInfo.h"


class T100DisplayInfo : public T100DeviceInfo
{
    public:
        T100DisplayInfo();
        virtual ~T100DisplayInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100DISPLAYINFO_H
