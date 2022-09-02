#ifndef T100DISPLAYPAGEDEVICE_H
#define T100DISPLAYPAGEDEVICE_H

#include "T100PageDevice.h"
class T100Display;


class T100DisplayPageDevice : public T100PageDevice
{
    public:
        T100DisplayPageDevice(T100QU32*);
        virtual ~T100DisplayPageDevice();

    protected:

    private:
};

#endif // T100DISPLAYPAGEDEVICE_H
