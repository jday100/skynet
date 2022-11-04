#include "T100BlockDevice.h"
#include "T100Port32.h"


namespace T100QU32{

T100BlockDevice::T100BlockDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
}

T100BlockDevice::~T100BlockDevice()
{
    //dtor
}

T100BOOL T100BlockDevice::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100BlockDevice::unload()
{
    return T100TRUE;
}

T100BOOL T100BlockDevice::in(T100WORD offset, T100WORD& value)
{
    T100Component::T100DEVICE_BLOCK*       block           = T100NULL;

    block = m_port->getBlock(m_id);

    if(block){
        value = block->DATA[offset];
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100BlockDevice::out(T100WORD offset, T100WORD value)
{
    T100Component::T100DEVICE_BLOCK*       block           = T100NULL;

    block = m_port->getBlock(m_id);

    if(block){
        block->DATA[offset] = value;
        return T100TRUE;
    }
    return T100FALSE;
}

}
