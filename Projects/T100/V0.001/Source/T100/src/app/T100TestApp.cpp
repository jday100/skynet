#include "T100TestApp.h"

#include "T100VPCSetup.h"
#include "T100ShellTools.h"
#include "T100AllTests.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"



T100STDSTRING       T100TestApp::m_unit     = "all";


T100TestApp::T100TestApp(T100App* app)
    :T100Test(m_unit), m_app(app),
    test_assembly(m_app), test_os(m_app)
{
    //ctor
}

T100TestApp::~T100TestApp()
{
    //dtor
}

T100VOID T100TestApp::load()
{

}

T100VOID T100TestApp::init()
{

}

T100BOOL T100TestApp::test_all()
{
    T100BOOL        result          = T100TRUE;

    /*
    T100TestLog                     test_log;
    T100TestLib                     test_lib;
    T100TestSystem                  test_system;

    T100VPCTest                     test_vpc;
    T100OSTest                      test_os(m_app);
    */

    if(!test_app()){
        result = T100FALSE;
    }

    return result;

    if(!test_log.test_all()){
        result = T100FALSE;
    }

    if(!test_lib.test_all()){
        result = T100FALSE;
    }

    if(!test_system.test_all()){
        result = T100FALSE;
    }

    if(!test_qu32.test_all()){
        result = T100FALSE;
    }

    //test
    //return result;

    if(!test_assembly.test_all()){
        result = T100FALSE;
    }

    if(!test_vpc.test_all()){
        result = T100FALSE;
    }

    if(!test_os.test_all()){
        result = T100FALSE;
    }

    show_result(result, "");

    return result;
}

T100BOOL T100TestApp::test_app()
{
    T100STDSTRING   cmd;
    T100STDSTRING   exec        = "bin\\Release\\T100.exe -V";
    T100STDSTRING   file        = "";
    T100STDSTRING   paras       = "-q -s 0 -f";
    T100INTEGER     result;
    T100BOOL        value;

    T100Assembly        assembly;
    T100VPCApp          vpc;
    T100STDSTRING       source;
    T100STDSTRING       target;

    source  = T100VPCSetup::getTestOSScript("test_word.txt");
    target  = T100VPCSetup::getTestOSBuild("test_word.bin");

    assembly.add("os");
    value = assembly.run(source, target);
    if(!value){
        return T100FALSE;
    }

    if(value){
        vpc.setQuit(T100TRUE);

        value = vpc.run(m_app, target);
        if(!value){
            return T100FALSE;
        }

        if(0 != vpc.getReturn()){
            return T100FALSE;
        }
    }

    file    = target;

    cmd     = exec + " " + paras + " " + file;

    result = T100ShellTools::system(cmd);
    if(0 == result){
        return T100TRUE;
    }

    return T100FALSE;
}
