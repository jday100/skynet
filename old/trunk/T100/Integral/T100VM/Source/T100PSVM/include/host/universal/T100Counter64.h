#ifndef T100COUNTER64_H
#define T100COUNTER64_H

#include <atomic>
#include "T100Common.h"

class T100Host64;

class T100Counter64
{
    public:
        T100Counter64(T100Host64*);
        virtual ~T100Counter64();

        T100VOID                            Pulse();

    protected:
        T100Host64*                         m_host          = T100NULL;
        std::atomic_uint_fast64_t           m_count;

    private:
};

#endif // T100COUNTER64_H
