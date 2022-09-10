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

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                load(T100Port32*);
        T100BOOL                unload();

    private:
        T100Display*            m_display           = T100NULL;
        T100Font                m_font;

};

#endif // T100DISPLAYBLOCKDEVICE_H
