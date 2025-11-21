#ifndef T100CPPSOURCESCANNERTEST_H
#define T100CPPSOURCESCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPSourceScannerTest : public T100Test
{
    public:
        T100CPPSourceScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPSourceScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    source_test();

    private:
};

#endif // T100CPPSOURCESCANNERTEST_H
