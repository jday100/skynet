#include "T100Device.h"

T100Device::T100Device(T100QU32* host)
    :m_host(host)
{
    //ctor
    create();
}

T100Device::~T100Device()
{
    //dtor
    destroy();
}

T100VOID T100Device::create()
{
    m_loaded = T100FALSE;
}

T100VOID T100Device::destroy()
{

}

T100BOOL T100Device::isLoaded()
{
    return m_loaded;
}

T100VOID T100Device::setName(T100String name)
{
    m_name = name;
}

T100String T100Device::getName()
{
    return m_name;
}

T100DEVICE_TYPE T100Device::getType()
{
    return m_type;
}
