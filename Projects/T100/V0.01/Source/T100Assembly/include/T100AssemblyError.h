#ifndef T100ASSEMBLYERROR_H
#define T100ASSEMBLYERROR_H

#include "T100AssemblyCommon.h"


class T100AssemblyError
{
    public:
        T100AssemblyError();
        virtual ~T100AssemblyError();

        static T100VOID             error(T100STRING);

    protected:

    private:
};

#endif // T100ASSEMBLYERROR_H
