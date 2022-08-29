#ifndef T100ASSEMBLY_H
#define T100ASSEMBLY_H

#include "T100AssemblyCommon.h"


class T100Assembly
{
    public:
        T100Assembly();
        virtual ~T100Assembly();

        T100BOOL            run(T100WSTRING&, T100WSTRING&);

    protected:

    private:
};

#endif // T100ASSEMBLY_H
