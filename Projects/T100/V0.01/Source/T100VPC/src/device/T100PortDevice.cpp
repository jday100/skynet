#include "T100PortDevice.h"
#include "T100QU32.h"


T100PortDevice::T100PortDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100PortDevice::~T100PortDevice()
{
    //dtor
    destroy();
}

T100VOID T100PortDevice::create()
{
    m_port = m_host->getPort32();
    m_port->appendDevice(m_id, this);
}

T100VOID T100PortDevice::destroy()
{
    m_port->removeDevice(m_id);
}

T100BOOL T100PortDevice::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100PortDevice::unload()
{
    return T100TRUE;
}

T100BOOL T100PortDevice::in(T100WORD offset, T100WORD& value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    value = m_data[offset];

    return T100TRUE;
}

T100BOOL T100PortDevice::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    switch(offset){
    case 0:
        {
            m_data[0] = value;

            switch(value){
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_PORT;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100PORTMODE_GET:
                {
                    m_data[1] = 1;
                    m_data[2] = 0;
                    m_data[3] = 32;
                }
                break;
            case T100PORTMODE_BLOCK:
                {
                    m_data[1] = 2;
                    m_data[2] = 1;
                    m_data[3] = 0;
                }
                break;
            case T100PORTMODE_PAGE:
                {
                    m_data[1] = 2;
                    m_data[2] = 1;
                    m_data[3] = 0;
                }
                break;
            }
        }
        break;
    default:
        m_data[offset] = value;
    }

    return T100TRUE;
}
