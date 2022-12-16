#ifndef T100TESTDEMOTEST_H
#define T100TESTDEMOTEST_H

#include "T100TestNew.h"

namespace T100Test{

class T100TestDemoTest : public T100Library::T100TestNew
{
    public:
        T100TestDemoTest();
        virtual ~T100TestDemoTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_test();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100TESTDEMOTEST_H
