#ifndef T100INSTRUCTINTEL64MOV_H
#define T100INSTRUCTINTEL64MOV_H

#include "T100InstructIntel64.h"

class T100InstructIntel64Mov : public T100InstructIntel64
{
    public:
        T100InstructIntel64Mov(T100CPUIntel64*);
        virtual ~T100InstructIntel64Mov();

        virtual T100VOID            Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCTINTEL64MOV_H
