#ifndef T100TESTUNITTEST_H
#define T100TESTUNITTEST_H

#include "test/T100TestNode.h"

class T100TestUnitTest : public T100TestNode
{
    public:
        T100TestUnitTest();
        virtual ~T100TestUnitTest();

    protected:
        T100RESULT                  DoTest();

        T100RESULT                  test_test();

    private:
};

#endif // T100TESTUNITTEST_H
