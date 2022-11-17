#ifndef T100ASSEMBLYKEYWORDSCANNERTEST_H
#define T100ASSEMBLYKEYWORDSCANNERTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyKeywordScannerTest : public T100Library::T100Test
{
    public:
        T100AssemblyKeywordScannerTest(T100Test*);
        virtual ~T100AssemblyKeywordScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_keyword();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYKEYWORDSCANNERTEST_H
