#include "IDevice.h"

IDevice::IDevice()
{
    //ctor
}

IDevice::~IDevice()
{
    //dtor
}

T100BOOL IDevice::isLoaded()
{
    return m_loaded;
}
