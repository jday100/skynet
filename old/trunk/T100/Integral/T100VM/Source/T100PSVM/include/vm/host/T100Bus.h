#ifndef T100BUS_H
#define T100BUS_H

#include "T100Device.h"

class T100Bus : public T100Device
{
    public:
        T100Bus();
        virtual ~T100Bus();

        virtual T100VOID            Plug(T100Device*) = 0;
        virtual T100VOID            Unplug(T100Device*) = 0;

    protected:

    private:
};

#endif // T100BUS_H
