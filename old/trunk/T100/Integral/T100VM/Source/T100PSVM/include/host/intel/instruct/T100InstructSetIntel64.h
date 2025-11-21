#ifndef T100INSTRUCTSETINTEL64_H
#define T100INSTRUCTSETINTEL64_H

#include "T100Instruct.h"

class T100CPUIntel64;

class T100InstructSetIntel64
{
    public:
        T100InstructSetIntel64(T100CPUIntel64*);
        virtual ~T100InstructSetIntel64();

        virtual T100VOID            Append(T100INSTRUCT_HASH&);

    protected:
        T100CPUIntel64*             m_cpu       = T100NULL;

    private:
};

#endif // T100INSTRUCTSETINTEL64_H
