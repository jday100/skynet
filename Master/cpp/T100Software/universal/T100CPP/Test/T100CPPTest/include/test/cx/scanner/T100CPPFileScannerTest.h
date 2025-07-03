#ifndef T100CPPFILESCANNERTEST_H
#define T100CPPFILESCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPFileScannerTest : public T100Test
{
    public:
        T100CPPFileScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPFileScannerTest();

        T100BOOL            DoTest();

    protected:
        T100BOOL            file_test();

    private:
};

#endif // T100CPPFILESCANNERTEST_H
