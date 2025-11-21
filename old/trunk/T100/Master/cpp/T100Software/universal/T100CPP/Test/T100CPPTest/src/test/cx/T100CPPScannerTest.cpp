#include "T100CPPScannerTest.h"

T100CPPScannerTest::T100CPPScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label),
    test_file(this, L"FileScanner"),
    test_buffer(this, L"BufferScanner"),
    test_byte(this, L"ByteScanner"),
    test_char(this, L"CharScanner"),
    test_string(this, L"StringScanner"),
    test_keyword(this, L"KeywordScanner"),
    test_sentence(this, L"SentenceScanner"),
    test_segment(this, L"SegmentScanner"),
    test_function(this, L"FunctionScanner"),
    test_source(this, L"SourceScanner")
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
