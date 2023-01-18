#ifndef T100PAINTERTEST_H
#define T100PAINTERTEST_H

#include "T100Test.h"

namespace T100Painter{

class T100PainterTest : public T100Library::T100Test
{
    public:
        T100PainterTest(T100Test*);
        virtual ~T100PainterTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_painter();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100PAINTERTEST_H
