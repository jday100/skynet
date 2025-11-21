#ifndef T100CPPFUNCTIONSCANNERTEST_H
#define T100CPPFUNCTIONSCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPFunctionScannerTest : public T100Test
{
    public:
        T100CPPFunctionScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPFunctionScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    function_test();

    private:
};

#endif // T100CPPFUNCTIONSCANNERTEST_H
