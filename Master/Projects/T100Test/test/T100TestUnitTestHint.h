#ifndef T100TESTUNITTESTHINT_H
#define T100TESTUNITTESTHINT_H

#include "base/T100Hint.h"

static T100WSTRING          T100TEST_HINT_UNIT_TEST_TEST_START                    = L"Test test is starting ... ";
static T100WSTRING          T100TEST_HINT_UNIT_TEST_TEST_STOP                     = L"Test test is stopped . ";

class T100TestUnitTestHint : public T100Hint
{
    public:
        T100TestUnitTestHint();
        virtual ~T100TestUnitTestHint();

    protected:

    private:
};

#endif // T100TESTUNITTESTHINT_H
