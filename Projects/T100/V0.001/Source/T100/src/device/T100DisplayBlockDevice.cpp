#include "T100DisplayBlockDevice.h"

#include "T100VPCCommon.h"
#include "T100Display.h"
#include "IManager.h"


T100DisplayBlockDevice::T100DisplayBlockDevice(T100Display* d)
{
    //ctor
    m_parent = d;
    create();
}

T100DisplayBlockDevice::~T100DisplayBlockDevice()
{
    //dtor
    destroy();
}

T100VOID T100DisplayBlockDevice::create()
{
    m_font = T100NEW T100Font();

    if(m_font->load(T100String("resources\\font.fnt"))){

    }else{
        T100DELETE(m_font);
        m_font = T100NULL;

        return;
    }

    m_font_width    = m_font->getWidth();
    m_font_height   = m_font->getHeight();

    m_row_size      = SCREEN_HEIGHT / m_font_height;
    m_column_size   = SCREEN_WIDTH / m_font_width;

    m_row           = 0;
    m_column        = 0;

    m_parent->m_row_size    = m_row_size;
    m_parent->m_column_size = m_column_size;

}

T100VOID T100DisplayBlockDevice::destroy()
{
    T100DELETE(m_font);
}

T100BOOL T100DisplayBlockDevice::load(T100Manager32* m)
{
    T100WORD    size;
    T100BOOL    result;

    m_manager = (IManager*)m;
    size = m_parent->m_row_size * m_parent->m_column_size;

    result = m_manager->allotBlock(this, size, m_block);

    return result;
}

T100BOOL T100DisplayBlockDevice::draw(T100WORD value)
{
    drawText(m_column, m_row, value);

    m_column++;
    if(m_column >= m_column_size){
        m_row++;
        if(m_row >= m_row_size){
            //
        }else{
            m_column = 0;
        }
    }
    return T100TRUE;
}

T100BOOL T100DisplayBlockDevice::drawText(T100WORD x, T100WORD y, T100WORD value)
{
    T100WORD ox, oy;
    T100WORD w, h;

    w = m_font_width;
    h = m_font_height;

    ox = m_column * m_font_width;
    oy = m_row * m_font_height;

    T100WORD_VECTOR* font       = T100NULL;


    if(m_font->getFont(value, font)&& font){
        if(m_parent->m_page_device.draw(ox, oy, w, h, font->data())){
            return T100TRUE;
        }
    }


    return T100FALSE;
}

T100BOOL T100DisplayBlockDevice::setCursor()
{
    return T100FALSE;
}

T100BOOL T100DisplayBlockDevice::getCursor()
{
    return T100FALSE;
}

T100BOOL T100DisplayBlockDevice::cursor(T100WORD row, T100WORD column)
{
    m_row       = row;
    m_column    = column;

    return T100TRUE;
}
