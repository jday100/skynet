#ifndef T100LIBTEST_H
#define T100LIBTEST_H

#include "T100Test.h"
#include "T100LogTest.h"
#include "T100ConsoleTest.h"
#include "T100CmdLineTest.h"
#include "T100StringTest.h"
#include "T100FileTest.h"


class T100LibTest : public T100Test
{
    public:
        T100LibTest(T100Test* parent = T100NULL);
        virtual ~T100LibTest();

    protected:
        T100LogTest                 test_log;
        T100ConsoleTest             test_console;
        T100CmdLineTest             test_cmdline;
        T100StringTest              test_string;
        T100FileTest                test_file;

        T100BOOL                    do_test();

        T100BOOL                    test_clock();

    private:
        static T100WSTRING          m_name;

};

#endif // T100LIBTEST_H
