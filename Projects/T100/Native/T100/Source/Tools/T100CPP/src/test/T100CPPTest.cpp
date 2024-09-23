#include "T100CPPTest.h"

#include "T100CPPScannerTest.h"

T100CPPTest::T100CPPTest()
    :T100Test()
{
    //ctor
}

T100CPPTest::~T100CPPTest()
{
    //dtor
}

T100BOOL T100CPPTest::run()
{
    T100CPPScannerTest          scanner_test;

    scanner_test.run();

    return T100FALSE;
}
