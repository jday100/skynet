#ifndef T100KEYBOARDINFO_H
#define T100KEYBOARDINFO_H

#include "T100DeviceInfo.h"

namespace T100VPC{

class T100KeyboardInfo : public T100DeviceInfo
{
    public:
        T100KeyboardInfo();
        virtual ~T100KeyboardInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100KeyboardInfo*);
        T100BOOL            remove(T100KeyboardInfo*);
        T100BOOL            getDeviceInfos(T100DEVICE_INFO_VECTOR&);

        T100BOOL            setup();

    protected:
        T100BOOL            append(T100DeviceInfo*);
        T100BOOL            remove(T100DeviceInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100KEYBOARDINFO_H
