#include "T100PortDeviceInfo.h"

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
    type = T100DEVICE_PORT;
}

T100VOID T100PortDeviceInfo::destroy()
{

}
