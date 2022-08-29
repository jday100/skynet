#ifndef T100MOUSEINFO_H
#define T100MOUSEINFO_H

#include "T100DeviceInfo.h"


class T100MouseInfo : public T100DeviceInfo
{
    public:
        T100MouseInfo();
        virtual ~T100MouseInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100MOUSEINFO_H
