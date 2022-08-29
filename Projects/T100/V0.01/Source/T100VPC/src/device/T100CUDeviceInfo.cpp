#include "T100CUDeviceInfo.h"

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
    type = T100DEVICE_CU;
}

T100VOID T100CUDeviceInfo::destroy()
{

}
