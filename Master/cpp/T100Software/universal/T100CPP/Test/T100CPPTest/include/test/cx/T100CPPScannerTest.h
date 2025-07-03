#ifndef T100CPPSCANNERTEST_H
#define T100CPPSCANNERTEST_H

#include "T100CPPFileScannerTest.h"
#include "T100CPPBufferScannerTest.h"

#include "T100CPPCharScannerTest.h"

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

        T100CPPCharScannerTest          test_char;

    private:
};

#endif // T100CPPSCANNERTEST_H
