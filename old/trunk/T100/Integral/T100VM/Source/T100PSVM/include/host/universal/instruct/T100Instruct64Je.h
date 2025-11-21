#ifndef T100INSTRUCT64JE_H
#define T100INSTRUCT64JE_H

#include "T100Instruct64.h"

class T100Instruct64Je : public T100Instruct64
{
    public:
        T100Instruct64Je(T100CPU64*);
        virtual ~T100Instruct64Je();

        T100VOID                    Append(T100INSTRUCT_HASH&);

        virtual T100VOID            Execute(T100BYTE);

    protected:

    private:
};

#endif // T100INSTRUCT64JE_H
