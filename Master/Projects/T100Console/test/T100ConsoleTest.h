#ifndef T100CONSOLETEST_H
#define T100CONSOLETEST_H

#include "test/T100TestNode.h"

class T100ConsoleTest : public T100TestNode
{
    public:
        T100ConsoleTest();
        virtual ~T100ConsoleTest();

        T100RESULT          DoTest();

    protected:
        T100RESULT          test_console();

    private:
};

#endif // T100CONSOLETEST_H
