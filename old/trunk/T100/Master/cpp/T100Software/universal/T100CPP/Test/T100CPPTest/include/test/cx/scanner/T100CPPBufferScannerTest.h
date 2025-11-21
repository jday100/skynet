#ifndef T100CPPBUFFERSCANNERTEST_H
#define T100CPPBUFFERSCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPBufferScannerTest : public T100Test
{
    public:
        T100CPPBufferScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPBufferScannerTest();

        T100BOOL            DoTest();

    protected:
        T100BOOL            buffer_test();

    private:
};

#endif // T100CPPBUFFERSCANNERTEST_H
