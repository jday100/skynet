#ifndef T100VM64_H
#define T100VM64_H

#include "T100VM.h"
#include "T100Host64.h"

class T100VM64 : public T100VM
{
    public:
        T100VM64();
        virtual ~T100VM64();

        virtual T100BOOL            Start();
        virtual T100BOOL            Stop();

        virtual T100VOID            Debug();
        virtual T100VOID            Step();

        virtual T100VOID            Info(T100DebugFrame*);

    protected:
        T100Host64                  m_host;

    private:
};

#endif // T100VM64_H
