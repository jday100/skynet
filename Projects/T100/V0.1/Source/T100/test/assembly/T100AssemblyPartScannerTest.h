#ifndef T100ASSEMBLYPARTSCANNERTEST_H
#define T100ASSEMBLYPARTSCANNERTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyPartScannerTest : public T100Library::T100Test
{
    public:
        T100AssemblyPartScannerTest(T100Test*);
        virtual ~T100AssemblyPartScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_part();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYPARTSCANNERTEST_H
