#include "T100TestTest.h"

#include "T100LibraryTestHint.h"
#include "T100TestDemoTest.h"

namespace T100Library{

T100WSTRING         T100TestTest::m_name                        = L"test";

T100TestTest::T100TestTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100TestTest::~T100TestTest()
{
    //dtor
}

T100BOOL T100TestTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_test();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestTest::test_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_LIBRARY_TEST_TEST_START);

    ::T100Test::T100TestDemoTest      demo;

    value = demo.test_all();
    if(!value){
        result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIBRARY_TEST_TEST_STOP);
    return result;
}

}
