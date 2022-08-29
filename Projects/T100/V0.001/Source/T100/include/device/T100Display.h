#ifndef T100DISPLAY_H
#define T100DISPLAY_H

#include "T100DisplayBlockDevice.h"
#include "T100DisplayPageDevice.h"
#include "T100Font.h"


enum T100DISPLAY_MODE{
    T100DISPLAYMODE_NONE            = T100DEVICEMODE_MAX,
    T100DISPLAYMODE_TYPE,
    T100DISPLAYMODE_SET,
    T100DISPLAYMODE_GET,
    T100DISPLAYMODE_READ,
    T100DISPLAYMODE_WRITE,
    T100DISPLAYMODE_MAX
};



class T100Display : public T100Device
{
    friend class T100DisplayBlockDevice;
    friend class T100DisplayPageDevice;
    public:
        T100Display(T100String);
        virtual ~T100Display();

        T100BOOL                    isInited();

        virtual T100BOOL            load(IManager*);
        virtual T100BOOL            load(T100Manager32*);

        T100BOOL                    load1(T100Manager32*);
        T100BYTE*                   getScreen1();

        T100WORD*                   getScreen();

        T100WORD                    in(T100WORD, T100WORD);
        T100VOID                    out(T100WORD, T100WORD, T100WORD);

        T100WORD                    in(T100WORD);
        T100VOID                    out(T100WORD, T100WORD);

    protected:
        T100Font                    m_font;

        T100VOID                    create();
        T100VOID                    destroy();

        T100BOOL                    drawText(T100WORD);
        T100BOOL                    drawText(T100WORD, T100WORD, T100WORD);

        T100VOID                    draw(T100WORD, T100WORD, T100WORD);
        T100WORD                    getNumber(T100WORD);
        T100VOID                    figure(T100WORD, T100WORD);
        T100VOID                    figure();

        T100DisplayBlockDevice      m_block_device;
        T100DisplayPageDevice       m_page_device;

    private:
        T100String                  m_file;
        T100WORD                    m_cursor;
        T100BOOL                    m_inited        = T100FALSE;

        T100WORD                    m_width;
        T100WORD                    m_height;
        T100WORD                    m_font_width;
        T100WORD                    m_font_height;
        T100WORD                    m_row_size;
        T100WORD                    m_column_size;

        T100WORD                    m_row;
        T100WORD                    m_column;
        T100WORD                    m_coord;

        T100WORD                    m_block_id;
        T100WORD                    m_block_num;
        T100WORD                    m_block_base;
        T100WORD                    m_block_offset;

        T100WORD                    m_page_id;
        T100WORD                    m_page_num;
        T100WORD                    m_page_base;
        T100WORD                    m_page_offset;
        T100WORD                    m_page_coord;
        T100WORD                    m_page_row;


};

#endif // T100DISPLAY_H
