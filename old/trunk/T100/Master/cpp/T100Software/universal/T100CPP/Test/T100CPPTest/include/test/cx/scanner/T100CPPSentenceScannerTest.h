#ifndef T100CPPSENTENCESCANNERTEST_H
#define T100CPPSENTENCESCANNERTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100CPPSentenceScannerTest : public T100Test
{
    public:
        T100CPPSentenceScannerTest(T100Test*, const T100WSTRING&);
        virtual ~T100CPPSentenceScannerTest();

        virtual T100BOOL            DoTest();

    protected:
        T100BOOL                    sentence_test();

    private:
};

#endif // T100CPPSENTENCESCANNERTEST_H
