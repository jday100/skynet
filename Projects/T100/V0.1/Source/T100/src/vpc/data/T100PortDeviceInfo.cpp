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

}
