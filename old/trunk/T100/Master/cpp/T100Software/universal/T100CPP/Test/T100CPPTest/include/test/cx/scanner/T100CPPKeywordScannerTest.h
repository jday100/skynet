#ifndef T100CPPKEYWORDSCANNERTEST_H
#define T100CPPKEYWORDSCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPKeywordScannerTest : public T100Test
{
    public:
        T100CPPKeywordScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPKeywordScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    keyword_test();

    private:
};

#endif // T100CPPKEYWORDSCANNERTEST_H
