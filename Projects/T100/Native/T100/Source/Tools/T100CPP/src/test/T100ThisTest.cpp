#include "T100ThisTest.h"

#include "T100ConsoleTest.h"
#include "T100CPPTest.h"

T100ThisTest::T100ThisTest()
    :T100Test()
{
    //ctor
}

T100ThisTest::~T100ThisTest()
{
    //dtor
}

T100BOOL T100ThisTest::run()
{
    T100ConsoleTest             console_test;

    console_test.run();

    T100CPPTest                 cpp_test;

    cpp_test.run();

    return T100FALSE;
}
