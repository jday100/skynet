#include "T100HintTest.h"

T100HintTest::T100HintTest()
{
    //ctor
}

T100HintTest::~T100HintTest()
{
    //dtor
}

T100STDSTRING T100HintTest::test_result(T100STDSTRING msg, T100STDSTRING hint)
{
    T100STDSTRING   result;

    result  =   "\n";
    result  +=  msg;
    result  +=  "\t";
    result  +=  hint;
    result  +=  "\n";

    return result;
}
