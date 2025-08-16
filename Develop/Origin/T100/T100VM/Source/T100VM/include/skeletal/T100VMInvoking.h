#ifndef T100VMINVOKING_H
#define T100VMINVOKING_H

#include "T100Common.h"
#include "host/T100HostBase.h"

using namespace T100LIBRARY;

class T100VMInvoking
{
    public:
        T100VMInvoking();
        virtual ~T100VMInvoking();

        static T100VOID             OnStart();
        static T100VOID             OnStop();

    protected:

    private:
        static T100HostBase*        m_host;
};

#endif // T100VMINVOKING_H
