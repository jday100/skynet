#include "T100CUDeviceInfo.h"

namespace T100VPC{

T100CUDeviceInfo::T100CUDeviceInfo()
{
    //ctor
    create();
}

T100CUDeviceInfo::~T100CUDeviceInfo()
{
    //dtor
    destroy();
}

T100VOID T100CUDeviceInfo::create()
{
    name = L"CU";
    type = T100Component::T100DEVICE_CU;
}

T100VOID T100CUDeviceInfo::destroy()
{

}

T100WORD T100CUDeviceInfo::count()
{

}

T100BOOL T100CUDeviceInfo::verify()
{

}

T100BOOL T100CUDeviceInfo::append(T100CUDeviceInfo* info)
{

}

T100BOOL T100CUDeviceInfo::remove(T100CUDeviceInfo* info)
{

}

T100BOOL T100CUDeviceInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100CUDeviceInfo::setup()
{

}

T100BOOL T100CUDeviceInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100CUDeviceInfo::remove(T100DeviceInfo* info)
{

}

}
