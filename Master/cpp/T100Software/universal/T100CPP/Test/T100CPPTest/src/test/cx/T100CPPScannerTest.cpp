#include "T100CPPScannerTest.h"

T100CPPScannerTest::T100CPPScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label),
    test_file(this, L"FileScanner"),
    test_buffer(this, L"BufferScanner"),
    test_char(this, L"CharScanner")
{
    //ctor
}

T100CPPScannerTest::~T100CPPScannerTest()
{
    //dtor
}

T100BOOL T100CPPScannerTest::DoTest()
{

}
