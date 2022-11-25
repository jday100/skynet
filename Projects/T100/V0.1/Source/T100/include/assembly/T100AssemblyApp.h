#ifndef T100ASSEMBLYAPP_H
#define T100ASSEMBLYAPP_H

#include "T100AppBase.h"
#include "T100ThisAppCmdLineResult.h"

namespace T100Assembly{

class T100AssemblyApp : public T100Library::T100AppBase
{
    public:
        T100AssemblyApp(T100Library::T100AppManager*);
        virtual ~T100AssemblyApp();

        T100BOOL            run(T100ThisAppCmdLineResult&);

    protected:

    private:
};

}

#endif // T100ASSEMBLYAPP_H
