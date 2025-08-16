#ifndef T100HYPERV_H
#define T100HYPERV_H

#include "host/T100HostBase.h"

class T100HyperV : public T100HostBase
{
    public:
        T100HyperV();
        virtual ~T100HyperV();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:

    private:
};

#endif // T100HYPERV_H
