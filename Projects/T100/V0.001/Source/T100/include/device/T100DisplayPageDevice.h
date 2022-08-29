#ifndef T100DISPLAYPAGEDEVICE_H
#define T100DISPLAYPAGEDEVICE_H

#include "T100PageDevice.h"
class T100Display;


class T100DisplayPageDevice : public T100PageDevice
{
    public:
        T100DisplayPageDevice(T100Display*);
        virtual ~T100DisplayPageDevice();

        T100WORD*           getScreen();

        T100BOOL            load(T100Manager32*);

        T100BOOL            draw(T100WORD, T100WORD, T100WORD, T100WORD, T100WORD*);
        T100BOOL            draw(T100WORD, T100WORD, T100WORD);

    private:
        T100Display*        m_parent        = T100NULL;
};

#endif // T100DISPLAYPAGEDEVICE_H
