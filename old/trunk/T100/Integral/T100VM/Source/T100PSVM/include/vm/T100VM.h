#ifndef T100VM_H
#define T100VM_H

#include <atomic>
#include "T100Common.h"

class T100DebugFrame;

class T100VM
{
    public:
        T100VM();
        virtual ~T100VM();

        virtual T100BOOL            IsRunning();

        virtual T100BOOL            Start() = 0;
        virtual T100BOOL            Stop() = 0;

        virtual T100VOID            Debug() = 0;
        virtual T100VOID            Step() = 0;

        virtual T100VOID            Info(T100DebugFrame*) = 0;

    protected:
        std::atomic_bool            m_running;

    private:
};

#endif // T100VM_H
