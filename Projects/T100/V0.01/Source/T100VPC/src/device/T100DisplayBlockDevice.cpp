#include "T100DisplayBlockDevice.h"

#include "T100QU32.h"
#include "T100Display.h"


T100DisplayBlockDevice::T100DisplayBlockDevice(T100Display* parent)
    :T100BlockDevice(parent->getHost()),
    m_display(parent)
{
    //ctor
    create();
}

T100DisplayBlockDevice::~T100DisplayBlockDevice()
{
    //dtor
    destroy();
}

T100VOID T100DisplayBlockDevice::create()
{
    load(m_display->getHost()->getPort32());
}

T100VOID T100DisplayBlockDevice::destroy()
{
    unload();
}

T100BOOL T100DisplayBlockDevice::load(T100Port32* port)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            length;

    m_display->getHost()->getPort32()->allotBlock(this, length, m_blocks);

    return result;
}

T100BOOL T100DisplayBlockDevice::unload()
{

}
