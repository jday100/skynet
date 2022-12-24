#ifndef T100OSLIBTEST_H
#define T100OSLIBTEST_H

#include "T100Test.h"

namespace T100OS{

class T100OSLibTest : public T100Library::T100Test
{
    public:
        T100OSLibTest(T100Test*);
        virtual ~T100OSLibTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_string_split();
        T100BOOL            test_run();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100OSLIBTEST_H
