#ifndef T100HOST_H
#define T100HOST_H

#include "T100CPU.h"
#include "T100Memory.h"
#include "T100Counter.h"
#include "T100Generator.h"

class T100Host
{
    public:
        T100Host();
        virtual ~T100Host();

        void                Start();

        void                Pulse();

        T100CPU             m_cpu;
        T100Memory          m_memory;
        T100Counter         m_counter;
        T100Generator       m_generator;

    protected:

    private:
};

#endif // T100HOST_H
