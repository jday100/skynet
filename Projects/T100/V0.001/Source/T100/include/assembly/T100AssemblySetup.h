#ifndef T100ASSEMBLYSETUP_H
#define T100ASSEMBLYSETUP_H

#include "T100Common.h"
#include "T100Setup.h"


class T100AssemblySetup : T100Setup
{
    public:
        T100AssemblySetup();
        virtual ~T100AssemblySetup();

        static T100STDSTRING        getTestScriptPathNew(T100STDSTRING);
        static T100STDSTRING        getTestScriptPathDrafts(T100STDSTRING);

        static T100STDSTRING        getTestScriptPath(T100STDSTRING);
        static T100STDSTRING        getTestBuildPath(T100STDSTRING);
        static T100STDSTRING        getTestStorePath(T100STDSTRING);

        static T100STDSTRING        getTestScripts(T100STDSTRING);

    protected:

    private:
};

#endif // T100ASSEMBLYSETUP_H
