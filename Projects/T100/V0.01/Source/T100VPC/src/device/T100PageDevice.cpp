#include "T100PageDevice.h"
#include "T100Port32.h"


T100PageDevice::T100PageDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
}

T100PageDevice::~T100PageDevice()
{
    //dtor
}

T100BOOL T100PageDevice::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100PageDevice::unload()
{
    return T100TRUE;
}

T100BOOL T100PageDevice::in(T100WORD offset, T100WORD& value)
{
    T100DEVICE_PAGE*            page            = T100NULL;

    page = m_port->getPage(m_id);

    if(page){
        value = page->data[offset];
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100PageDevice::out(T100WORD offset, T100WORD value)
{
    T100DEVICE_PAGE*            page            = T100NULL;

    page = m_port->getPage(m_id);

    if(page){
        page->data[offset] = value;
        return T100TRUE;
    }

    return T100FALSE;
}
