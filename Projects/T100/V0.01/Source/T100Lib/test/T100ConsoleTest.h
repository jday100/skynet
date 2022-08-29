#ifndef T100CONSOLETEST_H
#define T100CONSOLETEST_H

#include "T100Test.h"


class T100ConsoleTest : public T100Test
{
    public:
        T100ConsoleTest(T100Test*);
        virtual ~T100ConsoleTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_console();

    private:
        static T100WSTRING          m_name;

};

#endif // T100CONSOLETEST_H
