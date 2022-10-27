#ifndef T100LIBRARYTESTHINT_H
#define T100LIBRARYTESTHINT_H

#include "T100Hint.h"

namespace T100Library{

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD8_TEST_START                    = L"Library string std8 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD8_TEST_STOP                     = L"Library string std8 test is stopped. ";

class T100LibraryTestHint : public T100Hint
{
    public:
        T100LibraryTestHint();
        virtual ~T100LibraryTestHint();

    protected:

    private:
};

}

#endif // T100LIBRARYTESTHINT_H
