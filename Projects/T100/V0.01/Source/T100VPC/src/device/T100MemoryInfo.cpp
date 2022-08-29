#include "T100MemoryInfo.h"

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
    type = T100DEVICE_MEMORY;
}

T100VOID T100MemoryInfo::destroy()
{

}
