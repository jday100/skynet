#ifndef T100STRINGTEST_H
#define T100STRINGTEST_H

#include "T100Test.h"


class T100StringTest : public T100Test
{
    public:
        T100StringTest(T100Test*);
        virtual ~T100StringTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_std8();
        T100BOOL                    test_std16();
        T100BOOL                    test_std32();
        T100BOOL                    test_wstring();
        T100BOOL                    test_string();

        T100BOOL                    test_unicode();

    private:
        static T100WSTRING          m_name;

};

#endif // T100STRINGTEST_H
