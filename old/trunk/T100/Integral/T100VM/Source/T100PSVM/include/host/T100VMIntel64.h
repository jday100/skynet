#ifndef T100VMINTEL64_H
#define T100VMINTEL64_H

#include "T100VM.h"
#include "T100HostIntel64.h"

class T100VMIntel64 : public T100VM
{
    public:
        T100VMIntel64();
        virtual ~T100VMIntel64();

        virtual T100BOOL            Start();
        virtual T100BOOL            Stop();

        virtual T100VOID            Debug();
        virtual T100VOID            Step();

        virtual T100VOID            Info(T100DebugFrame*);

    protected:
        T100HostIntel64             m_host;

    private:
};

#endif // T100VMINTEL64_H
