#include "T100DisplayInfo.h"

namespace T100VPC{

T100DisplayInfo::T100DisplayInfo()
{
    //ctor
    create();
}

T100DisplayInfo::~T100DisplayInfo()
{
    //dtor
    destroy();
}

T100VOID T100DisplayInfo::create()
{
    name = L"Display";
    type = T100Component::T100DEVICE_DISPLAY;
}

T100VOID T100DisplayInfo::destroy()
{

}

T100WORD T100DisplayInfo::count()
{

}

T100BOOL T100DisplayInfo::verify()
{

}

T100BOOL T100DisplayInfo::append(T100DisplayInfo* info)
{

}

T100BOOL T100DisplayInfo::remove(T100DisplayInfo* info)
{

}

T100BOOL T100DisplayInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100DisplayInfo::setup()
{

}

T100BOOL T100DisplayInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100DisplayInfo::remove(T100DeviceInfo* info)
{

}

}
