#ifndef T100ASSEMBLYTEST_H
#define T100ASSEMBLYTEST_H

#include "T100Test.h"
#include "T100AssemblyScannerTest.h"
#include "T100AssemblyStringScannerTest.h"
#include "T100AssemblyKeywordScannerTest.h"
#include "T100AssemblySentenceScannerTest.h"
#include "T100AssemblySegmentScannerTest.h"
#include "T100AssemblyPartScannerTest.h"

#include "T100AssemblyRealTest.h"
#include "T100AssemblyVirtualTest.h"


namespace T100Assembly{

class T100AssemblyTest : public T100Library::T100Test
{
    public:
        T100AssemblyTest(T100Test*);
        virtual ~T100AssemblyTest();

    protected:
        T100AssemblyScannerTest             test_scanner;
        T100AssemblyStringScannerTest       test_string;
        T100AssemblyKeywordScannerTest      test_keyword;
        T100AssemblySentenceScannerTest     test_sentence;
        T100AssemblySegmentScannerTest      test_segment;
        T100AssemblyPartScannerTest         test_part;

        T100AssemblyRealTest                test_real;
        T100AssemblyVirtualTest             test_virtual;

    private:
        static T100WSTRING                  m_name;

};

}

#endif // T100ASSEMBLYTEST_H
