#include "T100ConsoleTest.h"

#include "T100Console.h"

T100ConsoleTest::T100ConsoleTest()
    :T100Test()
{
    //ctor
}

T100ConsoleTest::~T100ConsoleTest()
{
    //dtor
}

T100BOOL T100ConsoleTest::run()
{
    T100Console         console;
    T100WString         msg;

    msg = L"hello";

    console.out(msg);

    return T100FALSE;
}
