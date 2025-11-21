#ifndef T100INSTRUCTINTEL64JE_H
#define T100INSTRUCTINTEL64JE_H

#include "T100InstructIntel64.h"

class T100InstructIntel64Je : public T100InstructIntel64
{
    public:
        T100InstructIntel64Je(T100CPUIntel64*);
        virtual ~T100InstructIntel64Je();

        virtual T100VOID            Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCTINTEL64JE_H
