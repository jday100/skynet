#include "T100DiskInfo.h"

namespace T100VPC{

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
    type = T100Component::T100DEVICE_DISK;
}

T100VOID T100DiskInfo::destroy()
{

}

T100WORD T100DiskInfo::count()
{

}

T100BOOL T100DiskInfo::verify()
{
    return T100TRUE;
}

T100BOOL T100DiskInfo::append(T100DiskInfo* info)
{

}

T100BOOL T100DiskInfo::remove(T100DiskInfo* info)
{

}

T100BOOL T100DiskInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100DiskInfo::setup()
{
    if(!m_setup){
        m_setup = T100NEW T100VPCDiskSetupDialog(T100NULL);
    }
    m_setup->Show();

    return T100TRUE;
}

T100BOOL T100DiskInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100DiskInfo::remove(T100DeviceInfo* info)
{

}

}
