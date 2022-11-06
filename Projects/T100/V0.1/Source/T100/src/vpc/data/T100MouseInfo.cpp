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

}
