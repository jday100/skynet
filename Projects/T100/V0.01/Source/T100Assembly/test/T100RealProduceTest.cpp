#include "T100RealProduceTest.h"

#include "T100Log.h"
#include "T100AssemblySetup.h"
#include "T100AssemblyTestHint.h"
#include "T100File.h"
#include "T100Assembly.h"
#include "T100TestTools.h"
#include "T100FileTools.h"
#include "T100PartScannerTools.h"


T100WSTRING         T100RealProduceTest::m_name                     = L"produce.real";


T100RealProduceTest::T100RealProduceTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100RealProduceTest::~T100RealProduceTest()
{
    //dtor
}

T100BOOL T100RealProduceTest::do_test()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    /*
    if(result){
        value = test_keyword();
        if(!value){
            result = T100FALSE;
        }
    }
    */

    /*
    if(result){
        value = test_basic();
        if(!value){
            result = T100FALSE;
        }
    }
    */

    /*
    if(result){
        value = test_multiple();
        if(!value){
            result = T100FALSE;
        }
    }
    */

    if(result){
        value = test_share();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100RealProduceTest::test_real()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_START);


    T100WSTRING                 file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_part.txt");

    }


    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP);
    return result;
}

T100BOOL T100RealProduceTest::test_basic()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_START);


    T100WSTRING             source;
    T100WSTRING             target;
    T100WSTRING             confirm;
    T100Assembly            assembly;

    source  = T100AssemblySetup::getTestResources(L"assembly\\real\\test_basic.txt");
    confirm = T100AssemblySetup::getTestResources(L"assembly\\real\\test_basic.bin");
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

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP);
    return result;
}

T100BOOL T100RealProduceTest::test_multiple()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_START);


    T100WSTRING             source;
    T100WSTRING             target;
    T100WSTRING             confirm;
    T100Assembly            assembly;

    source  = T100AssemblySetup::getTestResources(L"assembly\\real\\test_multiple.txt");
    confirm = T100AssemblySetup::getTestResources(L"assembly\\real\\test_multiple.bin");
    target  = T100AssemblySetup::getTestBuild(L"test_multiple.bin");

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

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP);
    return result;
}

T100BOOL T100RealProduceTest::test_share()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_START);

    T100WSTRING             master_source;
    T100WSTRING             master_target;
    T100WSTRING             master_confirm;

    T100WSTRING             slave_source;
    T100WSTRING             slave_target;
    T100WSTRING             slave_confirm;

    T100Assembly            assembly;

    master_source   = T100AssemblySetup::getTestResources(L"assembly\\real\\test_master.txt");
    master_target   = T100AssemblySetup::getTestBuild(L"test_master.bin");
    master_confirm  = T100AssemblySetup::getTestResources(L"assembly\\real\\test_master.bin");

    slave_source    = T100AssemblySetup::getTestResources(L"assembly\\real\\test_slave.txt");
    slave_target    = T100AssemblySetup::getTestBuild(L"test_slave.bin");
    slave_confirm   = T100AssemblySetup::getTestResources(L"assembly\\real\\test_slave.bin");

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
        //value = T100FileTools::compare(master_target, master_confirm);
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
        //value = T100FileTools::compare(slave_target, slave_confirm);
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP);
    return result;
}

T100BOOL T100RealProduceTest::test_keyword()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_START);

    T100ByteScanner*            bscanner        = T100NULL;
    T100CharScanner*            cscanner        = T100NULL;
    T100StringScanner*          sscanner        = T100NULL;
    T100KeywordScanner*         kscanner        = T100NULL;
    T100KeywordToken            token;
    T100WSTRING                 file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\real\\test_multiple.txt");
        bscanner    = T100NEW T100ByteScanner();
        if(bscanner){
            if(bscanner->open(file)){

            }else{
                result = T100FALSE;
                T100SAFE_DELETE(bscanner);
            }
        }else{
            result = T100FALSE;
        }

        if(result){
            cscanner    = T100NEW T100CharScanner();
            if(cscanner){
                cscanner->setSource(bscanner);
            }else{
                result = T100FALSE;
            }
        }

        if(result){
            sscanner    = T100NEW T100StringScanner();
            if(sscanner){
                sscanner->setSource(cscanner);
            }else{
                result = T100FALSE;
            }
        }

        if(result){
            kscanner    = T100NEW T100KeywordScanner();
            if(kscanner){
                kscanner->setSource(sscanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){

        for(int i=0;i<100;i++){
            value = kscanner->next(token);
            if(!value){
                break;
            }
        }

        value = bscanner->close();
        if(!value){
            result = T100FALSE;
        }
        T100SAFE_DELETE(bscanner);
        T100SAFE_DELETE(cscanner);
        T100SAFE_DELETE(sscanner);
        T100SAFE_DELETE(kscanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP);
    return result;
}
