#ifndef T100ASSEMBLYPROGRAMTEST_H
#define T100ASSEMBLYPROGRAMTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyProgramTest : public T100Library::T100Test
{
    public:
        T100AssemblyProgramTest(T100Test*);
        virtual ~T100AssemblyProgramTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_stack();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYPROGRAMTEST_H
