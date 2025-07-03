#ifndef T100CPPCHARSCANNERTEST_H
#define T100CPPCHARSCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPCharScannerTest : public T100Test
{
    public:
        T100CPPCharScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPCharScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    char_test();

    private:
};

#endif // T100CPPCHARSCANNERTEST_H
