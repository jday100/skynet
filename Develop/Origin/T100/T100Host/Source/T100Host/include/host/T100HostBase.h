#ifndef T100HOSTBASE_H
#define T100HOSTBASE_H

#include "T100Common.h"

using namespace T100LIBRARY;

class T100HostBase
{
    public:
        T100HostBase();
        virtual ~T100HostBase();

        virtual T100VOID            Start() = 0;
        virtual T100VOID            Stop() = 0;

    protected:

    private:
};

#endif // T100HOSTBASE_H
