#include "T100DisplayPageDevice.h"

#include "T100VPCCommon.h"
#include "T100Manager32.h"
#include "T100Display.h"


T100DisplayPageDevice::T100DisplayPageDevice(T100Display* d)
{
    //ctor
    m_parent = d;
}

T100DisplayPageDevice::~T100DisplayPageDevice()
{
    //dtor
}

T100WORD* T100DisplayPageDevice::getScreen()
{
    static T100WORD     buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

    T100WORD    size;
    T100WORD    count       = 0;

    size = SCREEN_WIDTH * SCREEN_HEIGHT;

    for(int i=0;i<m_page.size();i++){
        T100WORD    id;
        id = m_page[i];

        T100DEVICE_PAGE* page = getManager32()->getPage(id);

        if(!page){
            return T100NULL;
        }

        for(int j=0;j<1024*1024;j++){
            buffer[count] = page->data[j];
            /*
            //test
            buffer[count] = 0x00ffffff;
            //buffer[count] = 0;
            */
            count++;
            if(count >= size){
                return buffer;
            }
        }
    }

    return buffer;
}

T100BOOL T100DisplayPageDevice::load(T100Manager32* m)
{
    T100WORD    size;
    T100BOOL    result;

    m_manager = m;
    size = m_parent->m_row_size * m_parent->m_column_size;

    result = m_manager->allotPage(this, size, m_page);

    return result;
}

T100BOOL T100DisplayPageDevice::draw(T100WORD x, T100WORD y, T100WORD w, T100WORD h, T100WORD* data)
{
    T100WORD count      = 0;
    for(int m=0;m<h;m++){
        T100WORD yo;
        yo = y + m;
        for(int n=0;n<w;n++){
            T100WORD xo;
            xo = x + n;
            T100WORD value;
            value = data[count];
            count++;
            //test
            //value = 0xffffff;
            draw(xo, yo, value);
        }
    }
    return T100FALSE;
}

T100BOOL T100DisplayPageDevice::draw(T100WORD x, T100WORD y, T100WORD value)
{
    T100WORD offset;
    T100BYTE index;
    T100WORD os;

    offset  = y * SCREEN_WIDTH + x;

    //index = (offset + (1024 * 1024 - 1)) / (1024 * 1024);
    index   = offset / (1024 * 1024);
    os      = offset % (1024 * 1024);

    T100WORD id = m_page[index];

    T100DEVICE_PAGE* page = getManager32()->getPage(id);

    if(page){
        //test
        //value = 0xff;
        page->data[os] = value;
        return T100TRUE;
    }

    return T100FALSE;
}
