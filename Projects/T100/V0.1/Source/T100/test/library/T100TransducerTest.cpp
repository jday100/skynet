#include "T100TransducerTest.h"

#include "T100LibraryTestHint.h"


namespace T100Library{

T100WSTRING         T100TransducerTest::m_name                      = L"transducer";

T100TransducerTest::T100TransducerTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100TransducerTest::~T100TransducerTest()
{
    //dtor
}

T100BOOL T100TransducerTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_trans();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TransducerTest::test_trans()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100Library::T100TEST_HINT_LIBRARY_TRANSDUCER_TEST_START);




    show_result(result, T100Library::T100TEST_HINT_LIBRARY_TRANSDUCER_TEST_STOP);
    return result;
}

}
