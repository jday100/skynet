#include "T100DiskInfo.h"

T100DiskInfo::T100DiskInfo()
{
    //ctor
    create();
}

T100DiskInfo::~T100DiskInfo()
{
    //dtor
    destroy();
}

T100VOID T100DiskInfo::create()
{
    name = L"Disk";
    type = T100DEVICE_DISK;
}

T100VOID T100DiskInfo::destroy()
{

}
