#include "T100Device.h"

namespace T100QU32{

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
    m_inited    = T100FALSE;
    m_loaded    = T100FALSE;
}

T100VOID T100Device::destroy()
{

}

T100BOOL T100Device::isInited()
{
    return m_inited;
}

T100BOOL T100Device::isLoaded()
{
    return m_loaded;
}

T100VOID T100Device::setName(T100STRING name)
{
    m_name = name;
}

T100STRING T100Device::getName()
{
    return m_name;
}

T100Component::T100DEVICE_TYPE T100Device::getType()
{
    return m_type;
}

T100Port32* T100Device::getPort32()
{
    return m_port;
}

}
