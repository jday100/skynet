#include "T100TestUnitTest.h"

#include "log/T100Logger.h"
#include "T100TestUnitTestHint.h"

T100TestUnitTest::T100TestUnitTest() :
    T100TestNode(L"Test", T100NULL)
{
    //ctor
}

T100TestUnitTest::~T100TestUnitTest()
{
    //dtor
}

T100RESULT T100TestUnitTest::DoTest()
{
    T100RESULT          result;

    result  = test_test();

    return result;
}

T100RESULT T100TestUnitTest::test_test()
{
    T100RESULT          result      = T100RESULT_SUCCESS;

    //T100Logger::Info(T100TEST_HINT_UNIT_TEST_TEST_START);

    ShowResult(result, T100TEST_HINT_UNIT_TEST_TEST_STOP);
    return result;
}
