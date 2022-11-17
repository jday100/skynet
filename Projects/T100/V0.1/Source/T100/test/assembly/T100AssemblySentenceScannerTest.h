#ifndef T100ASSEMBLYSENTENCESCANNERTEST_H
#define T100ASSEMBLYSENTENCESCANNERTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblySentenceScannerTest : public T100Library::T100Test
{
    public:
        T100AssemblySentenceScannerTest(T100Test*);
        virtual ~T100AssemblySentenceScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_sentence();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYSENTENCESCANNERTEST_H
