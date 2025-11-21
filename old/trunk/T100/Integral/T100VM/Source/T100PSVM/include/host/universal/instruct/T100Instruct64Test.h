#ifndef T100INSTRUCT64TEST_H
#define T100INSTRUCT64TEST_H

#include "T100Instruct64.h"

class T100Instruct64Test : public T100Instruct64
{
    public:
        T100Instruct64Test(T100CPU64*);
        virtual ~T100Instruct64Test();

        T100VOID                    Append(T100INSTRUCT_HASH&);

        virtual T100VOID            Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCT64TEST_H
