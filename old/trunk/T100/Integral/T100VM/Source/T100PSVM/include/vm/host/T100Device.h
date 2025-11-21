#ifndef T100DEVICE_H
#define T100DEVICE_H

#include "T100Common.h"

class T100Bus;

class T100Device
{
    public:
        T100Device();
        virtual ~T100Device();

        virtual T100VOID            SetBus(T100Bus*);
        virtual T100Bus*            GetBus();

    protected:
        T100Bus*                    m_bus       = T100NULL;

    private:
};

#endif // T100DEVICE_H
