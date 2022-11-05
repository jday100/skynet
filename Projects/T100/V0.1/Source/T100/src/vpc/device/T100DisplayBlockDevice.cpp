#include "T100DisplayBlockDevice.h"

#include "T100QU32.h"
#include "T100VPCSetup.h"
#include "T100Display.h"

namespace T100VPC{

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
    if(m_font.load(T100VPCSetup::getFontFile())){
        m_column_size   = T100VPCSetup::SCREEN_WIDTH / m_font.getWidth();
        m_row_size      = T100VPCSetup::SCREEN_HEIGHT / m_font.getHeight();
    }else{
        return;
    }

    load(m_display->getHost()->getPort32());
}

T100VOID T100DisplayBlockDevice::destroy()
{
    unload();
}

T100BOOL T100DisplayBlockDevice::load(T100Port32* port)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        length;

    if(!m_display){
        return T100FALSE;
    }

    length = (T100VPCSetup::SCREEN_WIDTH / m_font.getWidth()) * (T100VPCSetup::SCREEN_HEIGHT / m_font.getHeight());
    m_display->getHost()->getPort32()->allotBlock(this, length, m_blocks);

    return result;
}

T100BOOL T100DisplayBlockDevice::unload()
{
    return T100TRUE;
}

T100BOOL T100DisplayBlockDevice::draw(T100WORD value)
{
    T100BOOL        result;

    result = draw_char(m_row, m_column, value);
    if(!result){
        return T100FALSE;
    }

    m_column++;

    if(m_column >= m_column_size){
        m_row++;
        if(m_row >= m_row_size){
            scroll_screen();
            m_row = 0;
        }
        m_column = 0;
    }

    return result;
}

T100BOOL T100DisplayBlockDevice::scroll_screen()
{
    return T100FALSE;
}

T100BOOL T100DisplayBlockDevice::draw_char(T100WORD row, T100WORD column, T100WORD value)
{
    T100WORD        ox;
    T100WORD        oy;
    T100WORD        w;
    T100WORD        h;

    w = m_font.getWidth();
    h = m_font.getHeight();

    ox = m_column * w;
    oy = m_row * h;

    T100WORD_VECTOR*    font        = T100NULL;

    if(m_font.getFont(value, font) && font){
        if(m_display->m_page_device.draw(ox, oy, w, h, font->data())){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

}
