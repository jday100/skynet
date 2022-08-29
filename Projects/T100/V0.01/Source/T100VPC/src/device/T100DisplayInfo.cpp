#include "T100DisplayInfo.h"

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
    type = T100DEVICE_DISPLAY;
}

T100VOID T100DisplayInfo::destroy()
{

}
