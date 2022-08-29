#include "T100AsmTestExe.h"

#include "T100AssemblySetup.h"
#include "T100AssemblyNew.h"


T100STDSTRING       T100AsmTestExe::m_unit      = "asm.exe";


T100AsmTestExe::T100AsmTestExe(T100App* app)
    :T100Test(m_unit), m_app(app)
{
    //ctor
}

T100AsmTestExe::~T100AsmTestExe()
{
    //dtor
}

T100BOOL T100AsmTestExe::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_exe()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AsmTestExe::test_exe()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100String      source;
    T100String      target;

    source = T100AssemblySetup::getTestScriptPath("test_exe.txt");
    target = T100AssemblySetup::getTestBuildPath("test_exe.exe");

    value = assembly.run(source.to_std_string(), target.to_std_string());
    if(value){

    }else{
        result = T100FALSE;
    }

    return result;
}
