#ifndef T100TESTTEST_H
#define T100TESTTEST_H

#include "test/T100Test.h"

using namespace T100LIBRARY;

class T100TestTest : public T100Test
{
    public:
        T100TestTest();
        virtual ~T100TestTest();

        virtual T100BOOL            DoTest();

    protected:

    private:
};

#endif // T100TESTTEST_H
