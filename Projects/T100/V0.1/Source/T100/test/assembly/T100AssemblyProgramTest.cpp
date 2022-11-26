#include "T100AssemblyProgramTest.h"

#include "T100ThisAppSetup.h"
#include "T100AssemblyTestHint.h"
#include "T100FileTools.h"
#include "T100TestTools.h"
#include "T100Assembly.h"


namespace T100Assembly{

T100WSTRING         T100AssemblyProgramTest::m_name                     = L"assembly.program";

T100AssemblyProgramTest::T100AssemblyProgramTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100AssemblyProgramTest::~T100AssemblyProgramTest()
{
    //dtor
}

T100BOOL T100AssemblyProgramTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_stack();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100AssemblyProgramTest::test_stack()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_PROGRAM_STACK_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"assembly\\program\\test_stack.txt");
    confirm = T100ThisAppSetup::getTestResources(L"assembly\\program\\test_stack.bin");
    target  = T100ThisAppSetup::getTestBuild(L"test_stack.bin");

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = T100Library::T100TestTools::Exists(target.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100Library::T100FileTools::compare(target.to_wstring(), confirm.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_PROGRAM_STACK_TEST_STOP);
    return result;
}


}
