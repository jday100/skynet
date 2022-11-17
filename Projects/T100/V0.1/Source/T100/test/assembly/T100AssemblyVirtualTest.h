#ifndef T100ASSEMBLYVIRTUALTEST_H
#define T100ASSEMBLYVIRTUALTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyVirtualTest : public T100Library::T100Test
{
    public:
        T100AssemblyVirtualTest(T100Test*);
        virtual ~T100AssemblyVirtualTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_virtual();

        T100BOOL                    test_share();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100ASSEMBLYVIRTUALTEST_H
