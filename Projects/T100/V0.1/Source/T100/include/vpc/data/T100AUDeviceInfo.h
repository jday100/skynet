#ifndef T100AUDEVICEINFO_H
#define T100AUDEVICEINFO_H

#include "T100DeviceInfo.h"

namespace T100VPC{

class T100AUDeviceInfo : public T100DeviceInfo
{
    public:
        T100AUDeviceInfo();
        virtual ~T100AUDeviceInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100AUDeviceInfo*);
        T100BOOL            remove(T100AUDeviceInfo*);
        T100BOOL            getDeviceInfos(T100DEVICE_INFO_VECTOR&);

        T100BOOL            setup();

        T100BOOL            insert(wxListView*);

    protected:
        T100VOID            init();

        T100BOOL            append(T100DeviceInfo*);
        T100BOOL            remove(T100DeviceInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100AUDEVICEINFO_H
