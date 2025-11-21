#ifndef T100HOST_H
#define T100HOST_H

#include "T100CPU.h"
#include "T100Bus.h"
#include "T100Memory.h"
#include "T100Port.h"

class T100DebugFrame;

class T100Host
{
    public:
        T100Host();
        virtual ~T100Host();

        virtual T100BOOL            Pulse() = 0;

        virtual T100VOID            Info(T100DebugFrame*) = 0;

    protected:
        T100CPU*                    m_cpu       = T100NULL;
        T100Bus*                    m_bus       = T100NULL;
        T100Memory*                 m_memory    = T100NULL;
        T100Port*                   m_port      = T100NULL;

    private:
};

#endif // T100HOST_H
