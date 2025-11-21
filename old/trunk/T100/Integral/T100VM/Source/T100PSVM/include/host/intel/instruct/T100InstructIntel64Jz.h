#ifndef T100INSTRUCTINTEL64JZ_H
#define T100INSTRUCTINTEL64JZ_H

#include "T100InstructIntel64.h"

class T100InstructIntel64Jz : public T100InstructIntel64
{
    public:
        T100InstructIntel64Jz(T100CPUIntel64*);
        virtual ~T100InstructIntel64Jz();

        virtual T100VOID            Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCTINTEL64JZ_H
