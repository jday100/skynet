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

}
