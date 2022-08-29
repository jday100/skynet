#include "T100PageDevice.h"

#include "T100Manager32.h"


T100PageDevice::T100PageDevice()
{
    //ctor
}

T100PageDevice::~T100PageDevice()
{
    //dtor
}

T100BOOL T100PageDevice::load(T100Manager32* m)
{
    return T100FALSE;
}

T100BOOL T100PageDevice::unload()
{
    return T100FALSE;
}

T100WORD T100PageDevice::in(T100WORD id, T100WORD offset)
{
    T100WORD value;
    T100DEVICE_PAGE* page;

    page    = getManager32()->getPage(id);
    value   = page->data[offset];

    return value;
}

T100VOID T100PageDevice::out(T100WORD id, T100WORD offset, T100WORD value)
{
    T100DEVICE_PAGE* page;

    page = getManager32()->getPage(id);
    page->data[offset] = value;
}
