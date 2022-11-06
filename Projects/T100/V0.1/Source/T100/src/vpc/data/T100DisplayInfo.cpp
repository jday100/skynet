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

}
