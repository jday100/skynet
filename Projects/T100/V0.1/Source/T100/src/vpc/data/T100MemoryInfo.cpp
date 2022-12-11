#include "T100MemoryInfo.h"

namespace T100VPC{

T100MemoryInfo::T100MemoryInfo()
{
    //ctor
    create();
}

T100MemoryInfo::~T100MemoryInfo()
{
    //dtor
    destroy();
}

T100VOID T100MemoryInfo::create()
{
    name = L"Memory";
    type = T100Component::T100DEVICE_MEMORY;
}

T100VOID T100MemoryInfo::destroy()
{

}

T100WORD T100MemoryInfo::count()
{

}

T100BOOL T100MemoryInfo::verify()
{

}

T100BOOL T100MemoryInfo::append(T100MemoryInfo* info)
{

}

T100BOOL T100MemoryInfo::remove(T100MemoryInfo* info)
{

}

T100BOOL T100MemoryInfo::getDeviceInfos(T100DEVICE_INFO_VECTOR& infos)
{

}

T100BOOL T100MemoryInfo::setup()
{

}

T100BOOL T100MemoryInfo::append(T100DeviceInfo* info)
{

}

T100BOOL T100MemoryInfo::remove(T100DeviceInfo* info)
{

}

}
