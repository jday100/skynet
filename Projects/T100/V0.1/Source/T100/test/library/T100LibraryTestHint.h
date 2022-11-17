#ifndef T100LIBRARYTESTHINT_H
#define T100LIBRARYTESTHINT_H

#include "T100Hint.h"

namespace T100Library{

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD8_TEST_START                    = L"Library string std8 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD8_TEST_STOP                     = L"Library string std8 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD16_TEST_START                   = L"Library string std16 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD16_TEST_STOP                    = L"Library string std16 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD32_TEST_START                   = L"Library string std32 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_STD32_TEST_STOP                    = L"Library string std32 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_BASE_TEST_START                    = L"Library string base test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_BASE_TEST_STOP                     = L"Library string base test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_WSTRING_TEST_START                 = L"Library string wstring test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_WSTRING_TEST_STOP                  = L"Library string wstring test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_CUSTOM_TEST_START                  = L"Library string custom test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_CUSTOM_TEST_STOP                   = L"Library string custom test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_TOOLS_TEST_START                   = L"Library string tools test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_TOOLS_TEST_STOP                    = L"Library string tools test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_UNICODE_TEST_START                 = L"Library string unicode test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_STRING_UNICODE_TEST_STOP                  = L"Library string unicode test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_LOG_TEST_START                            = L"Library log test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_LOG_TEST_STOP                             = L"Library log test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIBRARY_TEST_TEST_START                           = L"Library test test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIBRARY_TEST_TEST_STOP                            = L"Library test test is stopped . ";



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
