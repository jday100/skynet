#include "T100VPCTest.h"

#include "T100ThisAppSetup.h"
#include "T100VPCTestHint.h"
#include "T100Assembly.h"
#include "T100File.h"
#include "T100VPC.h"

namespace T100VPC{

T100WSTRING         T100VPCTest::m_name                         = L"vpc";

T100VPCTest::T100VPCTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_qu32(this)
{
    //ctor
}

T100VPCTest::~T100VPCTest()
{
    //dtor
}

T100BOOL T100VPCTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_vpc();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VPCTest::test_vpc()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_VPC_BASIC_TEST_START);

    show_result(result, T100TEST_HINT_VPC_BASIC_TEST_STOP);
    return result;
}

}
