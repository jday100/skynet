#ifndef T100INSTRUCTINTEL64TEST_H
#define T100INSTRUCTINTEL64TEST_H

#include "T100InstructIntel64.h"

class T100InstructIntel64Test : public T100InstructIntel64
{
    public:
        T100InstructIntel64Test(T100CPUIntel64*);
        virtual ~T100InstructIntel64Test();

        virtual T100VOID        Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCTINTEL64TEST_H
