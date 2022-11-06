#include "T100AUDeviceInfo.h"

namespace T100VPC{

T100AUDeviceInfo::T100AUDeviceInfo()
{
    //ctor
    create();
}

T100AUDeviceInfo::~T100AUDeviceInfo()
{
    //dtor
    destroy();
}

T100VOID T100AUDeviceInfo::create()
{
    name = L"AU";
    type = T100Component::T100DEVICE_AU;
}

T100VOID T100AUDeviceInfo::destroy()
{

}

}
