#ifndef T100OSTESTHINT_H
#define T100OSTESTHINT_H

#include "T100Hint.h"

namespace T100OS{

static T100WSTRING          T100TEST_HINT_OS_BASIC_TEST_START                                   = L"OS basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_BASIC_TEST_STOP                                    = L"OS basic test is stopped . ";


class T100OSTestHint : public T100Library::T100Hint
{
    public:
        T100OSTestHint();
        virtual ~T100OSTestHint();

    protected:

    private:
};

}

#endif // T100OSTESTHINT_H
