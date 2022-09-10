#ifndef T100DISPLAY_H
#define T100DISPLAY_H

#include "T100DisplayBlockDevice.h"
#include "T100DisplayPageDevice.h"


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
        T100Display(T100QU32*);
        virtual ~T100Display();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

        T100BOOL            in(T100WORD, T100WORD&);
        T100BOOL            out(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100QU32*                           getHost();

        T100DisplayBlockDevice              m_block_device;
        T100DisplayPageDevice               m_page_device;

    private:
};

#endif // T100DISPLAY_H
