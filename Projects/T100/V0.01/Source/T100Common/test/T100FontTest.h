#ifndef T100FONTTEST_H
#define T100FONTTEST_H

#include "T100Test.h"


class T100FontTest : public T100Test
{
    public:
        T100FontTest(T100Test*);
        virtual ~T100FontTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_font();

    private:
        static T100WSTRING          m_name;

};

#endif // T100FONTTEST_H
