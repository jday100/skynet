#ifndef T100INSTRUCT64_H
#define T100INSTRUCT64_H

#include "T100Instruct.h"

class T100CPU64;

class T100Instruct64 : public T100Instruct
{
    public:
        T100Instruct64(T100CPU64*);
        virtual ~T100Instruct64();

    protected:
        T100CPU64*          m_cpu       = T100NULL;

    private:
};

#endif // T100INSTRUCT64_H
