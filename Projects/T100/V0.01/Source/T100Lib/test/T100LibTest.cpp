#include "T100LibTest.h"

#include "T100Clock.h"
#include "T100Thread.h"


T100WSTRING         T100LibTest::m_name             = L"lib";


T100LibTest::T100LibTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_log(this),
    test_console(this),
    test_cmdline(this),
    test_string(this),
    test_file(this)
{
    //ctor
}

T100LibTest::~T100LibTest()
{
    //dtor
}

T100BOOL T100LibTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_clock();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100LibTest::test_clock()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100DWORD       start;
    T100DWORD       stop;
    T100Clock       clock;

    T100DWORD       temp;


    start = clock.milliseconds();

    T100Thread::sleep(320);

    stop = clock.milliseconds();

    temp = stop - start;

    return result;
}
