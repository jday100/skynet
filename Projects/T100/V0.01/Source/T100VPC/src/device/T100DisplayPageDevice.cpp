#include "T100DisplayPageDevice.h"

#include "T100QU32.h"
#include "T100Display.h"


T100DisplayPageDevice::T100DisplayPageDevice(T100Display* parent)
    :T100PageDevice(parent->getHost()),
    m_display(parent)
{
    //ctor
    create();
}

T100DisplayPageDevice::~T100DisplayPageDevice()
{
    //dtor
    destroy();
}

T100VOID T100DisplayPageDevice::create()
{
    load(m_display->getHost()->getPort32());
}

T100VOID T100DisplayPageDevice::destroy()
{
    unload();
}

T100BOOL T100DisplayPageDevice::load(T100Port32* port)
{
    T100BOOL            result          = T100FALSE;
    T100WORD            length;

    result = m_display->getHost()->getPort32()->allotPage(this, length, m_pages);

    return result;
}

T100BOOL T100DisplayPageDevice::unload()
{

}
