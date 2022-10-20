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
        value = test_share();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value= test_virtual();
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

T100BOOL T100VirtualProduceTest::test_share()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_TEST_START);

    T100WSTRING             master_source;
    T100WSTRING             master_target;
    T100WSTRING             master_confirm;

    T100WSTRING             slave_source;
    T100WSTRING             slave_target;
    T100WSTRING             slave_confirm;

    T100Assembly            assembly;

    master_source   = T100AssemblySetup::getTestResources(L"assembly\\virtual\\test_master.txt");
    master_target   = T100AssemblySetup::getTestBuild(L"test_master.tgt");
    master_confirm  = T100AssemblySetup::getTestResources(L"assembly\\virtual\\test_master.tgt");

    slave_source    = T100AssemblySetup::getTestResources(L"assembly\\virtual\\test_slave.txt");
    slave_target    = T100AssemblySetup::getTestBuild(L"test_slave.tgt");
    slave_confirm   = T100AssemblySetup::getTestResources(L"assembly\\virtual\\test_slave.tgt");

    value = assembly.run(master_source, master_target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = T100TestTools::Exists(master_target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100FileTools::compare(master_target, master_confirm);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = assembly.run(slave_source, slave_target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100TestTools::Exists(slave_target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100FileTools::compare(slave_target, slave_confirm);
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_TEST_STOP);
    return result;
}
