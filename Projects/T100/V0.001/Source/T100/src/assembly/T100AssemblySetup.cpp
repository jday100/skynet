#include "T100AssemblySetup.h"

T100AssemblySetup::T100AssemblySetup()
{
    //ctor
}

T100AssemblySetup::~T100AssemblySetup()
{
    //dtor
}

T100STDSTRING T100AssemblySetup::getTestScriptPath(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "scripts\\assembly";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100AssemblySetup::getTestBuildPath(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "build";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100AssemblySetup::getTestStorePath(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "scripts\\stores";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100AssemblySetup::getTestScriptPathNew(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "scripts\\assembly_v0.01";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100AssemblySetup::getTestScriptPathDrafts(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = "docs\\drafts\\asm";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100AssemblySetup::getTestScripts(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "scripts";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}
