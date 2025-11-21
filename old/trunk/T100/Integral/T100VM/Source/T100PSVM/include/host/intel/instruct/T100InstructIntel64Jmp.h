#ifndef T100INSTRUCTINTEL64JMP_H
#define T100INSTRUCTINTEL64JMP_H

#include "T100InstructIntel64.h"

class T100InstructIntel64Jmp : public T100InstructIntel64
{
    public:
        T100InstructIntel64Jmp(T100CPUIntel64*);
        virtual ~T100InstructIntel64Jmp();

        virtual T100VOID            Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCTINTEL64JMP_H
