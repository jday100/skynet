#ifndef T100ASSEMBLYERROR_H
#define T100ASSEMBLYERROR_H

#include "T100Error.h"
#include "T100AssemblyCommon.h"
#include "T100String.h"

namespace T100Assembly{

class T100AssemblyError : public T100Library::T100Error
{
    public:
        T100AssemblyError();
        virtual ~T100AssemblyError();

        static T100VOID         error(T100STRING);

    protected:

    private:
};

}

#endif // T100ASSEMBLYERROR_H
