#ifndef T100CPPTEST_H
#define T100CPPTEST_H

#include "T100Test.h"

class T100CPPTest : public T100Test
{
    public:
        T100CPPTest();
        virtual ~T100CPPTest();

        T100BOOL            run();

    protected:

    private:
};

#endif // T100CPPTEST_H
