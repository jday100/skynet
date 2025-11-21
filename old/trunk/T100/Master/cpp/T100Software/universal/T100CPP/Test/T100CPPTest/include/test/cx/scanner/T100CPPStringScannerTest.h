#ifndef T100CPPSTRINGSCANNERTEST_H
#define T100CPPSTRINGSCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPStringScannerTest : public T100Test
{
    public:
        T100CPPStringScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPStringScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    string_test();

    private:
};

#endif // T100CPPSTRINGSCANNERTEST_H
