#ifndef T100DISPLAYBLOCKDEVICE_H
#define T100DISPLAYBLOCKDEVICE_H

#include "T100BlockDevice.h"
#include "T100Font.h"

namespace T100VPC{
class T100Display;


class T100DisplayBlockDevice : public T100BlockDevice
{
    public:
        T100DisplayBlockDevice(T100Display*);
        virtual ~T100DisplayBlockDevice();

        T100BOOL            draw(T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

    protected:
        T100BOOL            scroll_screen();
        T100BOOL            draw_char(T100WORD, T100WORD, T100WORD);

    private:
        T100Display*        m_display           = T100NULL;
        T100Font            m_font;

        T100WORD            m_row_size          = 0;
        T100WORD            m_column_size       = 0;

        T100WORD            m_row               = 0;
        T100WORD            m_column            = 0;

};

}

#endif // T100DISPLAYBLOCKDEVICE_H
