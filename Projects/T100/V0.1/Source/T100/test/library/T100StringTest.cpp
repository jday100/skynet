#include "T100StringTest.h"

#include "T100LibraryTestHint.h"


namespace T100Library{

T100WSTRING         T100StringTest::m_name                      = L"string";


T100StringTest::T100StringTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100StringTest::~T100StringTest()
{
    //dtor
}

T100BOOL T100StringTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_std8();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100StringTest::test_std8()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100Library::T100TEST_HINT_LIBRARY_STRING_STD8_TEST_START);

    show_result(result, T100Library::T100TEST_HINT_LIBRARY_STRING_STD8_TEST_STOP);
    return result;
}

}
