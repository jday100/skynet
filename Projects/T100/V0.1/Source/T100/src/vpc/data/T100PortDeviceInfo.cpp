#include "T100PortDeviceInfo.h"

namespace T100VPC{

T100PortDeviceInfo::T100PortDeviceInfo()
{
    //ctor
    create();
}

T100PortDeviceInfo::~T100PortDeviceInfo()
{
    //dtor
    destroy();
}

T100VOID T100PortDeviceInfo::create()
{
    name = L"Port";
    type = T100Component::T100DEVICE_PORT;
}

T100VOID T100PortDeviceInfo::destroy()
{

}

T100WORD T100PortDeviceInfo::count()
{

}

T100BOOL T100PortDeviceInfo::verify()
{

}

T100BOOL T100PortDeviceInfo::append(T100PortDeviceInfo* info)
{

}

T100BOOL T100PortDeviceInfo::remove(T100PortDeviceInfo* info)
{

}

T100BOOL T100PortDeviceInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100PortDeviceInfo::setup()
{

}

T100BOOL T100PortDeviceInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100PortDeviceInfo::remove(T100DeviceInfo* info)
{

}

}
