#ifndef T100GENERATOR64_H
#define T100GENERATOR64_H

#include <windef.h>
#include "T100Common.h"

class T100Host64;

class T100Generator64
{
    public:
        T100Generator64(T100Host64*);
        virtual ~T100Generator64();

        T100VOID            Start();
        T100VOID            Stop();

        T100VOID            Pulse();

        T100VOID            SetFrequency(T100UINT);

    protected:
        T100Host64*         m_host          = T100NULL;
        T100UINT            m_frequency;
        T100UINT            m_delay;
        T100UINT64          m_previous;

        LARGE_INTEGER       m_hardFrequency;
        LARGE_INTEGER       m_before;

    private:
};

#endif // T100GENERATOR64_H
