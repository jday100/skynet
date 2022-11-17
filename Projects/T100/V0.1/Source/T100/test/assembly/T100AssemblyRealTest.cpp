#include "T100AssemblyRealTest.h"

#include "T100ThisAppSetup.h"
#include "T100AssemblyTestHint.h"
#include "T100Assembly.h"
#include "T100TestTools.h"
#include "T100FileTools.h"
#include "T100PartScannerTools.h"

namespace T100Assembly{

T100WSTRING         T100AssemblyRealTest::m_name                        = L"produce.real";

T100AssemblyRealTest::T100AssemblyRealTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100AssemblyRealTest::~T100AssemblyRealTest()
{
    //dtor
}

T100BOOL T100AssemblyRealTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_basic();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_multiple();
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

T100BOOL T100AssemblyRealTest::test_basic()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_BASIC_TEST_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      confirm;
    T100Assembly    assembly;

    source  = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_basic.txt");
    confirm = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_basic.bin");
    target  = T100ThisAppSetup::getTestBuild(L"test_basic.bin");

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

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_BASIC_TEST_STOP);
    return result;
}

T100BOOL T100AssemblyRealTest::test_multiple()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_MULTIPLE_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_multiple.txt");
    confirm = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_multiple.bin");
    target  = T100ThisAppSetup::getTestBuild(L"test_multiple.bin");

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

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_MULTIPLE_TEST_STOP);
    return result;
}

T100BOOL T100AssemblyRealTest::test_share()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_SHARE_TEST_START);

    T100STRING          master_source;
    T100STRING          master_target;
    T100STRING          master_confirm;

    T100STRING          slave_source;
    T100STRING          slave_target;
    T100STRING          slave_confirm;

    T100Assembly        assembly;

    master_source   = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_master.txt");
    master_target   = T100ThisAppSetup::getTestBuild(L"test_master.bin");
    master_confirm  = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_master.bin");

    slave_source    = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_slave.txt");
    slave_target    = T100ThisAppSetup::getTestBuild(L"test_slave.bin");
    slave_confirm   = T100ThisAppSetup::getTestResources(L"assembly\\real\\test_slave.bin");

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

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_SHARE_TEST_STOP);
    return result;
}

}
