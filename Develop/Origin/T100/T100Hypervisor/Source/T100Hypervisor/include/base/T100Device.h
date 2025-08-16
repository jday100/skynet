#ifndef T100DEVICE_H
#define T100DEVICE_H

#include "T100Common.h"

using namespace T100LIBRARY;

class T100Device
{
    public:
        T100Device();
        virtual ~T100Device();

        T100VOID            Install(void*);

    protected:

    private:
};

#endif // T100DEVICE_H
