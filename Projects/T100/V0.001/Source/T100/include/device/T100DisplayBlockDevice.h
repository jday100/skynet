#ifndef T100DISPLAYBLOCKDEVICE_H
#define T100DISPLAYBLOCKDEVICE_H

#include "T100BlockDevice.h"
#include "T100Font.h"
class T100Display;


class T100DisplayBlockDevice : public T100BlockDevice
{
    public:
        T100DisplayBlockDevice(T100Display*);
        virtual ~T100DisplayBlockDevice();

        T100BOOL            load(T100Manager32*);

        T100BOOL            draw(T100WORD);
        T100BOOL            setCursor();
        T100BOOL            getCursor();

        T100BOOL            cursor(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();
        T100BOOL            drawText(T100WORD, T100WORD, T100WORD);

    private:
        T100Font*           m_font          = T100NULL;
        T100Display*        m_parent        = T100NULL;
        T100CURSOR_TYPE     m_cursor        = T100CURSOR_LINE;

        T100WORD            m_row_size;
        T100WORD            m_column_size;

        T100WORD            m_row;
        T100WORD            m_column;

        T100WORD            m_font_width;
        T100WORD            m_font_height;

};

#endif // T100DISPLAYBLOCKDEVICE_H
