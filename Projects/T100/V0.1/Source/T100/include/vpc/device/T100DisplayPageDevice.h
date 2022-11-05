#ifndef T100DISPLAYPAGEDEVICE_H
#define T100DISPLAYPAGEDEVICE_H

#include "T100PageDevice.h"

namespace T100VPC{
class T100Display;


class T100DisplayPageDevice : public T100PageDevice
{
    public:
        T100DisplayPageDevice(T100Display*);
        virtual ~T100DisplayPageDevice();

        T100BOOL            getScreen(T100WORD*);

        T100BOOL            draw(T100WORD, T100WORD, T100WORD);
        T100BOOL            draw(T100WORD, T100WORD, T100WORD, T100WORD, T100WORD*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

    private:
        T100Display*        m_display           = T100NULL;

};

}

#endif // T100DISPLAYPAGEDEVICE_H
