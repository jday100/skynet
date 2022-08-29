#include "T100ConsoleTest.h"
#include "T100Log.h"
#include "T100LibTestHint.h"

#include "T100Console.h"


T100WSTRING         T100ConsoleTest::m_name                 = L"console";


T100ConsoleTest::T100ConsoleTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100ConsoleTest::~T100ConsoleTest()
{
    //dtor
}

T100BOOL T100ConsoleTest::do_test()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    value = test_console();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ConsoleTest::test_console()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_LIB_CONSOLE_TEST_START);

    T100Console     console;
    T100WSTRING     msg;

    msg = L"hello";
    console.outline(msg);

    msg = L"你好";
    console.outline(msg);


    show_result(result, T100TEST_HINT_LIB_CONSOLE_TEST_STOP);
    return result;
}
