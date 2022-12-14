#ifndef T100DEVICEINFO_H
#define T100DEVICEINFO_H

#include <wx/listctrl.h>
#include "T100Common.h"
#include "T100VPCCommon.h"
#include "T100String.h"
#include "T100DeviceTypes.h"
#include "T100VPCSetup.h"


namespace T100VPC{

class T100DeviceInfo
{
    public:
        T100DeviceInfo();
        virtual ~T100DeviceInfo();

        T100Component::T100DEVICE_TYPE         type            = T100Component::T100DEVICE_NONE;
        T100STRING              name;

    public:
        virtual T100WORD        count() = 0;
        virtual T100BOOL        verify() = 0;

        virtual T100BOOL        append(T100DeviceInfo*) = 0;
        virtual T100BOOL        remove(T100DeviceInfo*) = 0;
        virtual T100BOOL        getDeviceInfos(T100DEVICE_INFO_VECTOR&) = 0;

        virtual T100BOOL        setup() = 0;

        virtual T100BOOL        insert(wxListView*) = 0;

    protected:
        virtual T100VOID        init() = 0;

    private:
};

}

#endif // T100DEVICEINFO_H
