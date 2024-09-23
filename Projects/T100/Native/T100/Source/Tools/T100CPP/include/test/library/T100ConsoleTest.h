#ifndef T100CONSOLETEST_H
#define T100CONSOLETEST_H

#include "T100Test.h"

class T100ConsoleTest : public T100Test
{
    public:
        T100ConsoleTest();
        virtual ~T100ConsoleTest();

        T100BOOL            run();

    protected:

    private:
};

#endif // T100CONSOLETEST_H
