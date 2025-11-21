#ifndef T100CPPSCANNERTEST_H
#define T100CPPSCANNERTEST_H

#include "T100CPPFileScannerTest.h"
#include "T100CPPBufferScannerTest.h"
#include "T100CPPByteScannerTest.h"
#include "T100CPPCharScannerTest.h"
#include "T100CPPStringScannerTest.h"
#include "T100CPPKeywordScannerTest.h"
#include "T100CPPSentenceScannerTest.h"
#include "T100CPPSegmentScannerTest.h"
#include "T100CPPFunctionScannerTest.h"
#include "T100CPPSourceScannerTest.h"

using namespace T100LIBRARY;

class T100CPPScannerTest : public T100Test
{
    public:
        T100CPPScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPScannerTest();

        T100BOOL            DoTest();

    protected:
        T100CPPFileScannerTest          test_file;
        T100CPPBufferScannerTest        test_buffer;
        T100CPPByteScannerTest          test_byte;
        T100CPPCharScannerTest          test_char;
        T100CPPStringScannerTest        test_string;
        T100CPPKeywordScannerTest       test_keyword;
        T100CPPSentenceScannerTest      test_sentence;
        T100CPPSegmentScannerTest       test_segment;
        T100CPPFunctionScannerTest      test_function;
        T100CPPSourceScannerTest        test_source;

    private:
};

#endif // T100CPPSCANNERTEST_H
