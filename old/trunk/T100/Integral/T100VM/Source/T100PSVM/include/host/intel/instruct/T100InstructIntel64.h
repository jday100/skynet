#ifndef T100INSTRUCTINTEL64_H
#define T100INSTRUCTINTEL64_H

#include "T100Instruct.h"

class T100CPUIntel64;

class T100InstructIntel64 : public T100Instruct
{
    public:
        T100InstructIntel64(T100CPUIntel64*);
        virtual ~T100InstructIntel64();

        T100BYTE                m_byte      = 0;

    protected:
        T100CPUIntel64*         m_cpu       = T100NULL;

    private:
};

#endif // T100INSTRUCTINTEL64_H
