#ifndef T100TESTTEST_H
#define T100TESTTEST_H

#include "T100Test.h"

namespace T100Library{

class T100TestTest : public T100Library::T100Test
{
    public:
        T100TestTest(T100Test*);
        virtual ~T100TestTest();

    protected:
        T100BOOL                do_test();

        T100BOOL                test_test();

    private:
        static T100WSTRING      m_name;

};

}

#endif // T100TESTTEST_H
