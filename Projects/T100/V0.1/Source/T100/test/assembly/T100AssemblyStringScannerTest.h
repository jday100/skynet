#ifndef T100ASSEMBLYSTRINGSCANNERTEST_H
#define T100ASSEMBLYSTRINGSCANNERTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyStringScannerTest : public T100Library::T100Test
{
    public:
        T100AssemblyStringScannerTest(T100Test*);
        virtual ~T100AssemblyStringScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_string();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYSTRINGSCANNERTEST_H
