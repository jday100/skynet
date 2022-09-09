#ifndef T100ASSEMBLY_H
#define T100ASSEMBLY_H

#include "T100AssemblyCommon.h"
#include "T100AssemblyCmdLineResult.h"


class T100Assembly
{
    public:
        T100Assembly();
        virtual ~T100Assembly();

        T100BOOL            run(T100AssemblyCmdLineResult&);

        T100BOOL            run(T100WSTRING&, T100WSTRING&);

    protected:

    private:
};

#endif // T100ASSEMBLY_H
