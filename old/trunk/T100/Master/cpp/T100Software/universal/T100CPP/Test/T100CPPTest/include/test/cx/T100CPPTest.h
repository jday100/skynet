#ifndef T100CPPTEST_H
#define T100CPPTEST_H

#include "T100CPPScannerTest.h"

using namespace T100LIBRARY;

class T100CPPTest : public T100Test
{
    public:
        T100CPPTest(T100Test* = T100NULL, const T100WSTRING& = L"All");
        virtual ~T100CPPTest();

        T100BOOL                    DoTest();

    protected:
        T100CPPScannerTest          test_scanner;

    private:
};

#endif // T100CPPTEST_H
