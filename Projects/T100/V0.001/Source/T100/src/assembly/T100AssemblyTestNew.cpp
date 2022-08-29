#include "T100AssemblyTestNew.h"
#include "T100AssemblySetup.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"
#include "T100FileTools.h"


T100STDSTRING       T100AssemblyTestNew::m_unit     =   "assembly.new";


T100AssemblyTestNew::T100AssemblyTestNew(T100App* app)
    :T100Test(m_unit), m_app(app)
{
    //ctor
}

T100AssemblyTestNew::~T100AssemblyTestNew()
{
    //dtor
}

T100BOOL T100AssemblyTestNew::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_exe()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTestNew::test_label()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source = T100AssemblySetup::getTestScriptPathNew("test_label.txt");
    target = T100AssemblySetup::getTestBuildPath("test_label.bin");

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

T100BOOL T100AssemblyTestNew::test_tiny()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source = T100AssemblySetup::getTestScriptPathNew("test_tiny.txt");
    target = T100AssemblySetup::getTestBuildPath("test_tiny.bin");

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

T100BOOL T100AssemblyTestNew::test_big()
{
    return T100FALSE;
}

T100BOOL T100AssemblyTestNew::test_dll()
{
    return T100FALSE;
}

T100BOOL T100AssemblyTestNew::test_sll()
{
    return T100FALSE;
}

T100BOOL T100AssemblyTestNew::test_virtual()
{
    return T100FALSE;
}

T100BOOL T100AssemblyTestNew::test_share()
{
    return T100FALSE;
}

T100BOOL T100AssemblyTestNew::test_exe()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100STDSTRING   binary;

    source = T100AssemblySetup::getTestScriptPathNew("test_exe.txt");
    target = T100AssemblySetup::getTestBuildPath("test_exe.exe");
    binary = T100AssemblySetup::getTestScripts("build\\test_exe.bin");

    value = assembly.run(source, target);
    if(value){
        result = T100FileTools::compare(target, binary);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTestNew::test_variable()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100STDSTRING   source;
    T100STDSTRING   target;

    source = T100AssemblySetup::getTestScriptPathNew("test_variable.txt");
    target = T100AssemblySetup::getTestBuildPath("test_variable.exe");

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    return result;
}
