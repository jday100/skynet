#include "T100Display.h"

#include <iostream>
#include "T100VPCCommon.h"
#include "T100HintQU32.h"
#include "T100Manager32.h"


T100Display::T100Display(T100String file)
    :m_file(file), m_block_device(this), m_page_device(this)
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
    T100Log::trace(T100DEVICE_HINT_DISPLAY_LOAD);

    m_width         = SCREEN_WIDTH;
    m_height        = SCREEN_HEIGHT;

    if(m_font.load(m_file)){

        m_font_width    = m_font.getWidth();
        m_font_height   = m_font.getHeight();

        m_row_size      = m_height / m_font_width;
        m_column_size   = m_width / m_font_height;

        m_row           = 0;
        m_column        = 0;
        m_coord         = 0;

        m_block_num     = 0;
        m_block_base    = 0;

        m_page_num      = 0;
        m_page_base     = 0;
        m_page_offset   = 0;
        m_page_coord    = 0;

        m_page_row      = m_width * m_font_height;

        m_inited = T100TRUE;
    }else{
        m_inited = T100FALSE;
    }
}

T100VOID T100Display::destroy()
{
    T100Log::trace(T100DEVICE_HINT_DISPLAY_UNLOAD);
}

T100BOOL T100Display::isInited()
{
    return m_inited;
}

T100BOOL T100Display::load(IManager* m)
{
    return load((T100Manager32*)m);
}

T100BOOL T100Display::load(T100Manager32* m)
{
    if(m_loaded || !m_inited){
        return T100FALSE;
    }

    m_manager = (IManager*)m;

    if(m_block_device.load(m) && m_page_device.load(m)){
        m_loaded = T100TRUE;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Display::load1(T100Manager32* m)
{
    T100WORD    size;
    T100BOOL    result;

    T100Font    font;

    //size = (SCREEN_WIDTH / font.getWidth()) * (SCREEN_HEIGHT / font.getHeight()) + 1;

    //result = m->allotBlock(this, size, m_block);
    if(!result)return false;

#ifdef __DEBUG__
    /*
    std::cout << "T100Display::load->" << "Block size:" << m_block.size() << std::endl;
    std::cout << "T100Display::load->" << "Block:";
    for(int i=0;i<m_block.size();i++){
        std::cout << m_block[i] << " ";
    }
    std::cout << std::endl;
    */
#endif // __DEBUG__

    size = SCREEN_WIDTH * SCREEN_HEIGHT * 4 + 1;

    //result = m->allotPage(this, size, m_page);


    return result;
}

T100BYTE* T100Display::getScreen1()
{
    T100WORD_VECTOR*    screen;
    T100WORD            size;
    T100WORD            offset = 0;

    screen = T100NEW T100WORD_VECTOR();

    //size = m_page.size() * 1024 * 1024;
    screen->resize(size + 1);
    (*screen)[size] = 0;

    /*
    for(int i=0;i<m_page.size();i++){
        T100WORD id;
        id = m_page[i];
        T100DEVICE_PAGE* page = T100App::getServe()->getComputer()->getManager()->getPage(id);
        for(int j=0;j<1024*1024;j++){
            (*screen)[offset++] = page->data[j];
        }
    }
    */

    return (T100BYTE*)screen->data();
}

T100WORD* T100Display::getScreen()
{
    if(!m_loaded){
        return T100NULL;
    }
    return m_page_device.getScreen();
}

T100WORD T100Display::in(T100WORD id, T100WORD offset)
{
    T100WORD value;
    T100DEVICE_BLOCK* block;

    if(!m_loaded){
        return 0;
    }

    block = getManager32()->getBlock(id);
    value = block->data[offset];

    return value;
}

T100VOID T100Display::out(T100WORD id, T100WORD offset, T100WORD value)
{
    T100DEVICE_BLOCK* block;

    if(!m_loaded){
        return;
    }

    block = getManager32()->getBlock(id);

    if(block){
        block->data[offset] = value;

        draw(id, offset, value);
    }
}

T100BOOL T100Display::drawText(T100WORD value)
{
    m_block_device.draw(value);
    return T100FALSE;
}

T100BOOL T100Display::drawText(T100WORD x, T100WORD y, T100WORD value)
{
    m_block_device.cursor(y, x);
    m_block_device.draw(value);
    return T100FALSE;
}

T100VOID T100Display::draw(T100WORD id, T100WORD offset, T100WORD value)
{
    T100BYTE_VECTOR font;

    //m_font.getFont(value, font);

    figure(id, offset);

#ifdef __DEBUG__
    std::cout << "T100Display::draw->" << "Font size:" << font.size() << std::endl;
    std::cout << "T100Display::draw->" << "Page coord:" << m_page_coord << std::endl;
#endif // __DEBUG__

    T100WORD os = 0;
    for(int i=0;i<m_font_height;i++){
    //for(int i=0;i<1;++i){
        for(int j=0;j<m_font_width;j++){
            figure();
#ifdef __DEBUG__
    //std::cout << "T100Display::draw->" << "Font size:" << font.size() << std::endl;
    //std::cout << "T100Display::draw->" << "Page coord:" << m_page_coord << "\t" << "Page offset:" << m_page_offset << std::endl;
#endif // __DEBUG__
            /*
            T100DEVICE_PAGE* page = T100App::getServe()->getComputer()->getManager()->getPage(m_page_id);
            if(page){
                TORDER order;
                order.BYTES[0].BYTE = font[os++];
                order.BYTES[1].BYTE = font[os++];
                order.BYTES[2].BYTE = font[os++];
                order.BYTES[3].BYTE = 0xff;
                page->data[m_page_offset] = order.WORD;
#ifdef __DEBUG__
    //std::cout << "T100Display::draw->" << "RGB:" << T100App::itoa(order.BYTES[0].BYTE) << " " << T100App::itoa(order.BYTES[1].BYTE) << " " << T100App::itoa(order.BYTES[2].BYTE) << std::endl;
#endif // __DEBUG__

                //std::string str << "T100Display::draw->" << "RGB:"+T100App::itoa(order.BYTES[0])+" "+T100App::itoa(order.BYTES[1])+" "+T100App::itoa(order.BYTES[2]);
                //T100App::debug(str);
            }
            */
            m_page_coord++;
        }
        m_page_coord += m_width - 16;
    }

}

T100WORD T100Display::getNumber(T100WORD id)
{
    T100WORD num;

    /*
    for(int i=0;i<m_block.size();i++){
        if(id == m_block[i]){
            num = i;
            break;
        }
    }
    */

    return num;
}

T100VOID T100Display::figure(T100WORD id, T100WORD offset)
{
    m_block_id      = id;
    m_block_num     = getNumber(id);
    m_block_base    = m_block_num * 1024;
    m_block_offset  = offset;

    m_coord         = m_block_num * 1024 + offset;
    m_row           = m_coord / m_column_size;
    m_column        = m_coord % m_column_size;

    m_page_coord    = m_row * m_page_row + m_column * m_font_width;
    m_page_num      = m_page_coord / (1024 * 1024);
    m_page_base     = m_page_num * (1024 * 1024);
    m_page_offset   = m_page_coord % (1024 * 1024);

}

T100VOID T100Display::figure()
{
    /*
    m_block_id      = id;
    m_block_num     = getNumber(id);
    m_block_base    = m_block_num * 1024;
    m_block_offset  = offset;

    m_coord         = m_block_num * 1024 + offset;
    m_row           = m_coord / m_column_size;
    m_column        = m_coord % m_column_size;
    */

    //m_page_coord    = m_row * m_page_row + m_column * m_font_width;
    m_page_num      = m_page_coord / (1024 * 1024);
    m_page_base     = m_page_num * (1024 * 1024);
    m_page_offset   = m_page_coord % (1024 * 1024);
    //m_page_id       = m_page[m_page_num];
}

T100WORD T100Display::in(T100WORD offset)
{
    T100WORD result = 0;

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

T100VOID T100Display::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return;

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
                    m_data[1] = m_row_size;
                    m_data[2] = m_column_size;
                    m_data[3] = 0;
                }
                break;
            case T100DISPLAYMODE_WRITE:
                {
                    T100WORD value;
                    value = m_data[1] * m_column_size + m_data[2];
                    //out(1, value, m_data[3]);
                    m_block_device.draw(m_data[3]);
                }
                break;
            };
        }
        break;
    default:
        m_data[offset] = value;
    };
}
