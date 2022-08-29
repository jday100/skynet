#include "T100AssemblyTestDrafts.h"
#include "T100AssemblySetup.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"
#include "T100FileTools.h"


T100STDSTRING       T100AssemblyTestDrafts::m_unit      =       "asm.drafts";


T100AssemblyTestDrafts::T100AssemblyTestDrafts(T100App* app)
    :T100Test(m_unit), m_app(app)
{
    //ctor
}

T100AssemblyTestDrafts::~T100AssemblyTestDrafts()
{
    //dtor
}

T100BOOL T100AssemblyTestDrafts::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_share()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTestDrafts::test_multifile()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source = T100AssemblySetup::getTestScriptPathDrafts("multifile\\main.txt");
    target = T100AssemblySetup::getTestBuildPath("test_multifile.bin");

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

T100BOOL T100AssemblyTestDrafts::test_multisegment()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source = T100AssemblySetup::getTestScriptPathDrafts("multisegment\\main.txt");
    target = T100AssemblySetup::getTestBuildPath("test_multisegment.bin");

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

T100BOOL T100AssemblyTestDrafts::test_cross_segment()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source = T100AssemblySetup::getTestScriptPathDrafts("crosssegment\\main.txt");
    target = T100AssemblySetup::getTestBuildPath("test_crosssegment.bin");

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

T100BOOL T100AssemblyTestDrafts::test_cross()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset;     //      = 1049600;

    source = T100AssemblySetup::getTestScriptPathDrafts("cross\\master.txt");
    target = T100AssemblySetup::getTestBuildPath("test_master.bin");

    value = assembly.run(source, target);
    if(value){
        offset = 1049600;
        result = vpc.add(target, offset);
    }else{
        result = T100FALSE;
    }

    if(result){
        source = T100AssemblySetup::getTestScriptPathDrafts("cross\\slave.txt");
        target = T100AssemblySetup::getTestBuildPath("test_slave.bin");

        value = assembly.run(source, target);
        if(value){
            offset = 1050624;
            result = vpc.add(target, offset);
        }else{
            result = T100FALSE;
        }
    }

    if(result){
        value = vpc.run(m_app);

        if(value){
            if(0 == vpc.getReturn()){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}

T100BOOL T100AssemblyTestDrafts::test_int()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset;     //      = 1049600;

    source = T100AssemblySetup::getTestScriptPathDrafts("int\\master.txt");
    target = T100AssemblySetup::getTestBuildPath("test_master.bin");

    value = assembly.run(source, target);
    if(value){
        offset = 1049600;
        result = vpc.add(target, offset);
    }else{
        result = T100FALSE;
    }

    if(result){
        source = T100AssemblySetup::getTestScriptPathDrafts("int\\slave.txt");
        target = T100AssemblySetup::getTestBuildPath("test_slave.bin");

        value = assembly.run(source, target);
        if(value){
            offset = 1050624;
            result = vpc.add(target, offset);
        }else{
            result = T100FALSE;
        }
    }

    if(result){
        value = vpc.run(m_app);

        if(value){
            if(0 == vpc.getReturn()){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}

T100BOOL T100AssemblyTestDrafts::test_exe()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100STDSTRING   source;
    T100STDSTRING   target;

    source = T100AssemblySetup::getTestScriptPathDrafts("exe.txt");
    target = T100AssemblySetup::getTestBuildPath("test_exe.exe");

    value = assembly.run(source, target);
    if(value){

    }else{
        result = T100FALSE;
    }


    return result;
}

T100BOOL T100AssemblyTestDrafts::test_share()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100STDSTRING   binary;

    source = T100AssemblySetup::getTestScriptPathDrafts("share\\master.txt");
    target = T100AssemblySetup::getTestBuildPath("test_master.exe");
    binary = T100AssemblySetup::getTestScripts("build\\share\\test_master.bin");

    value = assembly.run(source, target);
    if(value){
        result = T100FileTools::compare(target, binary);
    }else{
        result = T100FALSE;
    }

    if(!result){
        return result;
    }

    source = T100AssemblySetup::getTestScriptPathDrafts("share\\slave.txt");
    target = T100AssemblySetup::getTestBuildPath("test_slave.exe");
    binary = T100AssemblySetup::getTestScripts("build\\share\\test_slave.bin");

    value = assembly.run(source, target);
    if(value){
        result = T100FileTools::compare(target, binary);
    }else{
        result = T100FALSE;
    }

    return result;
}








