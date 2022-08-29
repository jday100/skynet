#include "T100OSTestFS.h"

#include "T100VPCSetup.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"

T100STDSTRING       T100OSTestFS::m_unit        = "os.fs";


T100OSTestFS::T100OSTestFS(T100App* app)
    :T100Test(m_unit), m_app(app)
{
    //ctor
}

T100OSTestFS::~T100OSTestFS()
{
    //dtor
}

T100VOID T100OSTestFS::load()
{

}

T100BOOL T100OSTestFS::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_fs()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100OSTestFS::test_fs()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;
    T100WORD            offset          = 1049600;

    source  = T100VPCSetup::getTestOSScript("test_fs.txt");
    target  = T100VPCSetup::getTestOSBuild("test_fs.bin");

    assembly.add("os");
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target, offset);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}
