#include "T100CPPScannerTest.h"

#include "T100CPPSetting.h"
#include "T100CPPScanner.h"

T100CPPScannerTest::T100CPPScannerTest()
    :T100Test()
{
    //ctor
}

T100CPPScannerTest::~T100CPPScannerTest()
{
    //dtor
}

T100BOOL T100CPPScannerTest::run()
{
    T100CPPScanner          cpp_scanner;
    T100WString             file;

    file    = L"test_main.cpp";

    cpp_scanner.done(file);

    return T100FALSE;
}
