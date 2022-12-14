#include "T100Mouse.h"
#include "T100QU32.h"


T100Mouse::T100Mouse(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100Mouse::~T100Mouse()
{
    //dtor
    destroy();
}

T100VOID T100Mouse::create()
{
    m_port = m_host->getPort32();
    m_port->appendDevice(m_id, this);
}

T100VOID T100Mouse::destroy()
{
    m_port->removeDevice(m_id);
}

T100BOOL T100Mouse::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100Mouse::unload()
{
    return T100TRUE;
}

T100BOOL T100Mouse::in(T100WORD offset, T100WORD& value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    value = m_data[offset];

    return T100TRUE;
}

T100BOOL T100Mouse::out(T100WORD offset, T100WORD value)
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
                    m_data[1] = T100DEVICE_MOUSE;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100MOUSEMODE_GET:
                {
                    m_data[1] = 3;
                    m_data[2] = 0;
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
