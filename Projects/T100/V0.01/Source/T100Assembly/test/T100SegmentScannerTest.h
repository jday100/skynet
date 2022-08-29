#ifndef T100SEGMENTSCANNERTEST_H
#define T100SEGMENTSCANNERTEST_H

#include "T100Test.h"


class T100SegmentScannerTest : public T100Test
{
    public:
        T100SegmentScannerTest(T100Test*);
        virtual ~T100SegmentScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_segment();

    private:
        static T100WSTRING          m_name;

};

#endif // T100SEGMENTSCANNERTEST_H
