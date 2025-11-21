#ifndef T100CPPBYTESCANNERTEST_H
#define T100CPPBYTESCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPByteScannerTest : public T100Test
{
    public:
        T100CPPByteScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPByteScannerTest();

        T100BOOL            DoTest();

    protected:
        T100BOOL            byte_test();

    private:
};

#endif // T100CPPBYTESCANNERTEST_H
