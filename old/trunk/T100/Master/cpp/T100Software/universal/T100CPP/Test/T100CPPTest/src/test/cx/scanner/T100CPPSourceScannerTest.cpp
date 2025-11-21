#include "T100CPPSourceScannerTest.h"

#include "compiler/scanner/T100SourceScanner.h"

using namespace T100LIBRARY;

T100CPPSourceScannerTest::T100CPPSourceScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label)
{
    //ctor
}

T100CPPSourceScannerTest::~T100CPPSourceScannerTest()
{
    //dtor
}

T100BOOL T100CPPSourceScannerTest::DoTest()
{
    T100BOOL        result;

    result  = source_test();

    return result;
}

T100BOOL T100CPPSourceScannerTest::source_test()
{
    T100BOOL            result;

    return result;
}
