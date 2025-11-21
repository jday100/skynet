#ifndef T100HOSTINTEL64_H
#define T100HOSTINTEL64_H

#include "T100Host.h"
#include "T100CPUIntel64.h"
#include "T100BusIntel64.h"
#include "T100MemoryIntel64.h"
#include "T100Port.h"

class T100HostIntel64 : public T100Host
{
    public:
        T100HostIntel64();
        virtual ~T100HostIntel64();

        virtual T100BOOL            Pulse();

        virtual T100VOID            Info(T100DebugFrame*);

    protected:
        T100CPUIntel64*             m_cpu       = T100NULL;
        T100BusIntel64*             m_bus       = T100NULL;
        T100MemoryIntel64*          m_memory    = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100HOSTINTEL64_H
