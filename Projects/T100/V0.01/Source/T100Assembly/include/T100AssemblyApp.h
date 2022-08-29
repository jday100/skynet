#ifndef T100ASSEMBLYAPP_H
#define T100ASSEMBLYAPP_H

#include "T100App.h"
#include "T100AssemblyCmdLineInfo.h"


class T100AssemblyApp : public T100App
{
    public:
        T100AssemblyApp();
        virtual ~T100AssemblyApp();

        T100BOOL            run();

    protected:

    private:
};

#endif // T100ASSEMBLYAPP_H
