#include "IBlockDevice.h"

IBlockDevice::IBlockDevice()
    :T100Device()
{
    //ctor
}

IBlockDevice::~IBlockDevice()
{
    //dtor
}

T100BOOL IBlockDevice::load(IManager* m)
{
    return T100Device::load(m);
}
