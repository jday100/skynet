#include "T100DisplayPageDevice.h"

#include <string.h>
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

    T100PageDevice::load(port);

    result = m_display->getHost()->getPort32()->allotPage(this, length, m_pages);

    return result;
}

T100BOOL T100DisplayPageDevice::unload()
{

}

T100BOOL T100DisplayPageDevice::getScreen(T100WORD* data)
{
    if(!data){
        return T100FALSE;
    }

    T100WORD            length;
    T100WORD            offset      = 0;
    T100WORD            total;
    T100WORD            index       = 0;
    T100WORD            id;
    T100DEVICE_PAGE*    page        = T100NULL;

    total   = m_display->getWidth() * m_display->getHeight();

    do{
        length  = m_page_size;
        length  = (offset + length) < total ? length : total - offset;

        index   = offset / m_page_size;
        if(index >= m_pages.size()){
            return T100FALSE;
        }

        id      = m_pages[index];
        page    = getPort32()->getPage(id);

        if(!page){
            return T100FALSE;
        }

        memcpy(data + offset, page->data, length * sizeof(T100WORD));

        offset += length;

    }while(offset < total);

    return T100TRUE;
}

T100BOOL T100DisplayPageDevice::draw(T100WORD x, T100WORD y, T100WORD value)
{
    T100WORD            offset;
    T100WORD            index;
    T100WORD            os;
    T100WORD            id;
    T100DEVICE_PAGE*    page        = T100NULL;

    //offset  = y * m_display->getWidth() + x;
    offset = y * 800 + x;
    index   = offset / m_page_size;
    os      = offset % m_page_size;

    if(index >= m_pages.size()){
        return T100FALSE;
    }

    id      = m_pages[index];

    page    = getPort32()->getPage(id);

    if(page){
        //test
        //value = 0xffffff;

        page->data[os] = value;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100DisplayPageDevice::draw(T100WORD x, T100WORD y, T100WORD w, T100WORD h, T100WORD* data)
{
    if(!data){
        return T100FALSE;
    }

    T100WORD        count       = 0;
    T100WORD        yo;
    T100WORD        xo;
    T100WORD        value;

    for(int m=0;m<h;m++){
        yo = y + m;

        for(int n=0;n<w;n++){
            xo      = x + n;
            value   = data[count];
            count++;
            draw(xo, yo, value);
        }
    }

    return T100TRUE;
}
