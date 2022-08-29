#include "T100RealProduceTest.h"

#include "T100Log.h"
#include "T100AssemblySetup.h"
#include "T100AssemblyTestHint.h"
#include "T100File.h"
#include "T100Assembly.h"


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


    if(result){
        value = test_basic();
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
    T100Assembly            assembly;

    source  = T100AssemblySetup::getTestResources(L"assembly\\real\\test_basic.txt");
    target  = T100AssemblySetup::getTestBuild(L"test_basic.bin");

    result = assembly.run(source, target);

    if(result){
        T100File        file(target);

        if(file.exists()){

        }else{
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP);
    return result;
}
