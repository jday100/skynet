#include "T100OSTestLib.h"

#include "T100VPCSetup.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"

T100STDSTRING       T100OSTestLib::m_unit       = "os.lib";


T100OSTestLib::T100OSTestLib(T100App* app)
    :T100Test(m_unit), m_app(app)
{
    //ctor
}

T100OSTestLib::~T100OSTestLib()
{
    //dtor
}

T100VOID T100OSTestLib::load()
{

}

T100BOOL T100OSTestLib::test_all()
{
    T100BOOL    result      = T100TRUE;

    /*
    if(!test_string()){
        result = T100FALSE;
    }


    if(result && (!test_word())){
        result = T100FALSE;
    }
    */


    if(result && (!test_dword())){
        result = T100FALSE;
    }

    return result;

    if(result && (!test_disk())){
        result = T100FALSE;
    }

    if(result && (!test_part())){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100OSTestLib::test_string()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;

    source  = T100VPCSetup::getTestOSScript("test_string.txt");
    target  = T100VPCSetup::getTestOSBuild("test_string.bin");

    assembly.add("os");
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100OSTestLib::test_word()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;

    source  = T100VPCSetup::getTestOSScript("test_word.txt");
    target  = T100VPCSetup::getTestOSBuild("test_word.bin");

    assembly.add("os");
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100OSTestLib::test_dword()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;
    T100WORD            offset          = 1049600;

    source  = T100VPCSetup::getTestOSScript("test_dword.txt");
    target  = T100VPCSetup::getTestOSBuild("test_dword.bin");

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

T100BOOL T100OSTestLib::test_disk()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100VPCSetup::setVDiskFile(T100VPCSetup::getTestOSStore("test.vdk"));

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;

    source  = T100VPCSetup::getTestOSScript("test_disk.txt");
    target  = T100VPCSetup::getTestOSBuild("test_disk.bin");

    assembly.add("os");
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100OSTestLib::test_part()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;

    T100VPCSetup::setVDiskFile(T100VPCSetup::getTestOSStore("test.vdk"));
    source  = T100VPCSetup::getTestOSScript("test_part.txt");
    target  = T100VPCSetup::getTestOSBuild("test_part.bin");

    assembly.add("os");
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }
    }

    return result;
}
