#ifndef T100CPPSEGMENTSCANNERTEST_H
#define T100CPPSEGMENTSCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPSegmentScannerTest : public T100Test
{
    public:
        T100CPPSegmentScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPSegmentScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    segment_test();

    private:
};

#endif // T100CPPSEGMENTSCANNERTEST_H
