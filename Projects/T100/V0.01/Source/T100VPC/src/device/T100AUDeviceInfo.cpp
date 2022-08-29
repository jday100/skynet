#include "T100AUDeviceInfo.h"

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
    type = T100DEVICE_AU;
}

T100VOID T100AUDeviceInfo::destroy()
{

}
