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

T100WORD T100AUDeviceInfo::count()
{

}

T100BOOL T100AUDeviceInfo::verify()
{

}

T100BOOL T100AUDeviceInfo::append(T100AUDeviceInfo* info)
{

}

T100BOOL T100AUDeviceInfo::remove(T100AUDeviceInfo* info)
{

}

T100BOOL T100AUDeviceInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100AUDeviceInfo::setup()
{

}

T100BOOL T100AUDeviceInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100AUDeviceInfo::remove(T100DeviceInfo* info)
{

}

}
