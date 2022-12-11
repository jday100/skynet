#include "T100KeyboardInfo.h"

namespace T100VPC{

T100KeyboardInfo::T100KeyboardInfo()
{
    //ctor
    create();
}

T100KeyboardInfo::~T100KeyboardInfo()
{
    //dtor
    destroy();
}

T100VOID T100KeyboardInfo::create()
{
    name = L"Keyboard";
    type = T100Component::T100DEVICE_KEYBOARD;
}

T100VOID T100KeyboardInfo::destroy()
{

}

T100WORD T100KeyboardInfo::count()
{

}

T100BOOL T100KeyboardInfo::verify()
{

}

T100BOOL T100KeyboardInfo::append(T100KeyboardInfo* info)
{

}

T100BOOL T100KeyboardInfo::remove(T100KeyboardInfo* info)
{

}

T100BOOL T100KeyboardInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100KeyboardInfo::setup()
{

}

T100BOOL T100KeyboardInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100KeyboardInfo::remove(T100DeviceInfo* info)
{

}

}
