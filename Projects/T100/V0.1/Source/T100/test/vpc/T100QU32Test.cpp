#include "T100QU32Test.h"

#include "T100ThisAppSetup.h"
#include "T100VPCTestHint.h"
#include "T100Assembly.h"
#include "T100File.h"
#include "T100QU32.h"


namespace T100VPC{

T100WSTRING         T100QU32Test::m_name                        = L"vpc.qu32";

T100QU32Test::T100QU32Test(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100QU32Test::~T100QU32Test()
{
    //dtor
}

T100BOOL T100QU32Test::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_qu32();
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100QU32Test::test_qu32()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;
    T100STRING      source;
    T100STRING      target;

    T100Library::T100Log::info(T100TEST_HINT_VPC_QU32_TEST_START);

    T100QU32::T100QU32              host;
    T100Assembly::T100Assembly      assembly;

    source = T100ThisAppSetup::getTestResources(L"vpc\\test_qu32.txt");
    target = T100ThisAppSetup::getTestBuild(L"test_qu32.bin");

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        T100Library::T100File       file(target.to_wstring());
        if(!file.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        value = host.create();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = host.start();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = host.wait();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(1 != host.getReturn()){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_VPC_QU32_TEST_STOP);
    return result;
}

}
