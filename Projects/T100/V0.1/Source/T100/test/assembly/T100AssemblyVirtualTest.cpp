#include "T100AssemblyVirtualTest.h"

#include "T100ThisAppSetup.h"
#include "T100AssemblyTestHint.h"
#include "T100Assembly.h"
#include "T100TestTools.h"
#include "T100FileTools.h"

namespace T100Assembly{

T100WSTRING         T100AssemblyVirtualTest::m_name                         = L"produce.virtual";

T100AssemblyVirtualTest::T100AssemblyVirtualTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100AssemblyVirtualTest::~T100AssemblyVirtualTest()
{
    //dtor
}

T100BOOL T100AssemblyVirtualTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_virtual();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_share();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100AssemblyVirtualTest::test_virtual()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_BASIC_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"assembly\\virtual\\test_virtual.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_virtual.e");
    confirm = T100ThisAppSetup::getTestResources(L"assembly\\virtual\\test_virtual.e");

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

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_BASIC_TEST_STOP);
    return result;
}

T100BOOL T100AssemblyVirtualTest::test_share()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_SHARE_TEST_START);

    T100STRING          master_source;
    T100STRING          master_target;
    T100STRING          master_confirm;

    T100STRING          slave_source;
    T100STRING          slave_target;
    T100STRING          slave_confirm;

    T100Assembly        assembly;

    master_source   = T100ThisAppSetup::getTestResources(L"assembly\\virtual\\test_master.txt");
    master_target   = T100ThisAppSetup::getTestBuild(L"test_master.e");
    master_confirm  = T100ThisAppSetup::getTestResources(L"assembly\\virtual\\test_master.e");

    slave_source    = T100ThisAppSetup::getTestResources(L"assembly\\virtual\\test_slave.txt");
    slave_target    = T100ThisAppSetup::getTestBuild(L"test_slave.e");
    slave_confirm   = T100ThisAppSetup::getTestResources(L"assembly\\virtual\\test_slave.e");

    value = assembly.run(master_source, master_target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = T100Library::T100TestTools::Exists(master_target.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100Library::T100FileTools::compare(master_target.to_wstring(), master_confirm.to_wstring());
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
        value = T100Library::T100TestTools::Exists(slave_target.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100Library::T100FileTools::compare(slave_target.to_wstring(), slave_confirm.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_SHARE_TEST_STOP);
    return result;
}

}
