#ifndef T100TESTDEMOTEST_H
#define T100TESTDEMOTEST_H

#include "T100Test.h"

namespace T100Test{

class T100TestDemoTest : public T100Library::T100Test
{
    public:
        T100TestDemoTest();
        virtual ~T100TestDemoTest();

    protected:

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100TESTDEMOTEST_H
