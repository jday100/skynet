#ifndef T100ASSEMBLYSEGMENTSCANNERTEST_H
#define T100ASSEMBLYSEGMENTSCANNERTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblySegmentScannerTest : public T100Library::T100Test
{
    public:
        T100AssemblySegmentScannerTest(T100Test*);
        virtual ~T100AssemblySegmentScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_segment();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYSEGMENTSCANNERTEST_H
