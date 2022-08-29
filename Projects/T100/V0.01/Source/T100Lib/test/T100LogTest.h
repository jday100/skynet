#ifndef T100LOGTEST_H
#define T100LOGTEST_H

#include "T100Test.h"


class T100LogTest : public T100Test
{
    public:
        T100LogTest(T100Test*);
        virtual ~T100LogTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_log();

    private:
        static T100WSTRING          m_name;

};

#endif // T100LOGTEST_H
