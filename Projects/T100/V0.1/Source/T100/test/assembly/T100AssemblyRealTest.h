#ifndef T100ASSEMBLYREALTEST_H
#define T100ASSEMBLYREALTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyRealTest : public T100Library::T100Test
{
    public:
        T100AssemblyRealTest(T100Test*);
        virtual ~T100AssemblyRealTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_basic();

        T100BOOL                    test_multiple();

        T100BOOL                    test_share();

        T100BOOL                    test_stack();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYREALTEST_H
