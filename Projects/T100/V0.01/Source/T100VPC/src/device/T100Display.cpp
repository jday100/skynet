#include "T100Display.h"
#include "T100QU32.h"


T100Display::T100Display(T100QU32* host)
    :T100Device(host),
    m_block_device(this),
    m_page_device(this)
{
    //ctor
    create();
}

T100Display::~T100Display()
{
    //dtor
    destroy();
}

T100VOID T100Display::create()
{
    m_port = m_host->getPort32();
    m_port->appendDevice(m_id, this);
}

T100VOID T100Display::destroy()
{
    m_port->removeDevice(m_id);
}

T100BOOL T100Display::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100Display::unload()
{
    return T100TRUE;
}

T100BOOL T100Display::in(T100WORD offset, T100WORD& value)
{
    if(offset >= 4)return T100FALSE;

    value = m_data[offset];

    return T100TRUE;
}

T100BOOL T100Display::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return T100FALSE;

    switch(offset){
    case 0:
        {
            switch(value)
            {
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_DISPLAY;
                    m_data[2] = 1;
                    m_data[3] = 1;
                }
                break;
            case T100DISPLAYMODE_TYPE:
                {
                    m_data[1] = 1;
                    m_data[2] = 0;
                    m_data[3] = 32;
                }
                break;
            case T100DISPLAYMODE_GET:
                {
                    //m_data[1] = m_row_size;
                    //m_data[2] = m_column_size;
                    m_data[3] = 0;
                }
                break;
            case T100DISPLAYMODE_WRITE:
                {
                    T100WORD value;
                    //value = m_data[1] * m_column_size + m_data[2];
                    //out(1, value, m_data[3]);
                    //m_block_device.draw(m_data[3]);
                }
                break;
            };
        }
        break;
    default:
        m_data[offset] = value;
    };

    return T100TRUE;
}

T100QU32* T100Display::getHost()
{
    return m_host;
}
