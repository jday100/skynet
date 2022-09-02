#ifndef T100DISPLAYBLOCKDEVICE_H
#define T100DISPLAYBLOCKDEVICE_H

#include "T100BlockDevice.h"
#include "T100Font.h"
class T100Display;


class T100DisplayBlockDevice : public T100BlockDevice
{
    public:
        T100DisplayBlockDevice(T100QU32*);
        virtual ~T100DisplayBlockDevice();

    protected:

    private:
        T100Font            m_font;

};

#endif // T100DISPLAYBLOCKDEVICE_H
