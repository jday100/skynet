#include "T100VirtualProduceTest.h"

#include "T100Log.h"
#include "T100AssemblySetup.h"
#include "T100AssemblyTestHint.h"
#include "T100Assembly.h"
#include "T100TestTools.h"
#include "T100FileTools.h"


T100WSTRING         T100VirtualProduceTest::m_name                  = L"produce.virtual";

T100VirtualProduceTest::T100VirtualProduceTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100VirtualProduceTest::~T100VirtualProduceTest()
{
    //dtor
}

T100BOOL T100VirtualProduceTest::do_test()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_virtual();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VirtualProduceTest::test_virtual()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_TEST_START);


    T100WSTRING             source;
    T100WSTRING             target;
    T100WSTRING             confirm;
    T100Assembly            assembly;

    source  = T100AssemblySetup::getTestResources(L"assembly\\virtual\\test_basic.txt");
    confirm = T100AssemblySetup::getTestResources(L"assembly\\virtual\\test_basic.bin");
    target  = T100AssemblySetup::getTestBuild(L"test_basic.bin");

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = T100TestTools::Exists(target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100FileTools::compare(target, confirm);
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_TEST_STOP);
    return result;
}
