#ifndef T100CPU_H
#define T100CPU_H

#include "T100Device.h"

class T100DebugFrame;

class T100CPU : public T100Device
{
    public:
        T100CPU();
        virtual ~T100CPU();

        virtual T100BOOL            Pulse() = 0;

        virtual T100VOID            Info(T100DebugFrame*) = 0;

    protected:

    private:
};

#endif // T100CPU_H
