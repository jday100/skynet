#ifndef T100HOST64_H
#define T100HOST64_H

#include <thread>
#include "T100Host.h"
#include "T100CPU64.h"
#include "T100Bus64.h"
#include "T100Memory64.h"
#include "T100Counter64.h"
#include "T100Generator64.h"
#include "T100Port.h"

class T100Host64 : public T100Host
{
    friend class T100Generator64;
    public:
        T100Host64();
        virtual ~T100Host64();

        T100CPU64                   m_cpu;
        T100Bus64                   m_bus;
        T100Memory64                m_memory;
        T100Counter64               m_counter;
        T100Generator64             m_generator;
        T100Port                    m_port;

        virtual T100BOOL            Start();
        virtual T100BOOL            Stop();

        virtual T100VOID            Debug();
        virtual T100VOID            Step();

        virtual T100VOID            Info(T100DebugFrame*);

    protected:
        std::thread*                m_thread        = T100NULL;

        T100BOOL                    Pulse();

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100HOST64_H
