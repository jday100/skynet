#ifndef T100INSTRUCTSET64_H
#define T100INSTRUCTSET64_H

#include "T100Instruct.h"

class T100CPU64;

class T100InstructSet64
{
    public:
        T100InstructSet64(T100CPU64*);
        virtual ~T100InstructSet64();

        T100VOID            Append(T100INSTRUCT_HASH&);

    protected:
        T100CPU64*          m_cpu       = T100NULL;

    private:
};

#endif // T100INSTRUCTSET64_H
