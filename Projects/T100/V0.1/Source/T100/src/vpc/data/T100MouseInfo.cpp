#include "T100MouseInfo.h"

namespace T100VPC{

T100MouseInfo::T100MouseInfo()
{
    //ctor
    create();
}

T100MouseInfo::~T100MouseInfo()
{
    //dtor
    destroy();
}

T100VOID T100MouseInfo::create()
{
    name = L"Mouse";
    type = T100Component::T100DEVICE_MOUSE;
}

T100VOID T100MouseInfo::destroy()
{

}

T100WORD T100MouseInfo::count()
{

}

T100BOOL T100MouseInfo::verify()
{

}

T100BOOL T100MouseInfo::append(T100MouseInfo* info)
{

}

T100BOOL T100MouseInfo::remove(T100MouseInfo* info)
{

}

T100BOOL T100MouseInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100MouseInfo::setup()
{

}

T100BOOL T100MouseInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100MouseInfo::remove(T100DeviceInfo* info)
{

}

}
