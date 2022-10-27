#ifndef T100STRINGTEST_H
#define T100STRINGTEST_H

#include "T100Test.h"

namespace T100Library{

class T100StringTest : public T100Test
{
    public:
        T100StringTest(T100Test*);
        virtual ~T100StringTest();

    protected:
        T100BOOL                do_test();

        T100BOOL                test_std8();

    private:
        static T100WSTRING      m_name;

};

}

#endif // T100STRINGTEST_H
