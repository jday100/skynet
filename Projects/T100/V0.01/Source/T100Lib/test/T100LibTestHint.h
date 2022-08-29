#ifndef T100LIBTESTHINT_H
#define T100LIBTESTHINT_H

#include "T100Hint.h"

#include "T100Common.h"

static T100WSTRING          T100TEST_HINT_LIB_LOG_TEST_START                        = L"Lib log test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_LOG_TEST_STOP                         = L"Lib log test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_CONSOLE_TEST_START                    = L"Lib console test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_CONSOLE_TEST_STOP                     = L"Lib console test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_CMDLINE_TEST_START                    = L"Lib cmdline test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_CMDLINE_TEST_STOP                     = L"Lib cmdline test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_BUFFER_TEST_START                     = L"Lib buffer test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_BUFFER_TEST_STOP                      = L"Lib buffer test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_UNICODE_TEST_START                    = L"Lib unicode test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_UNICODE_TEST_STOP                     = L"Lib unicode test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_STD8_TEST_START                = L"String std8 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_STD8_TEST_STOP                 = L"String std8 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_STD16_TEST_START               = L"String std16 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_STD16_TEST_STOP                = L"String std16 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_STD32_TEST_START               = L"String std32 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_STD32_TEST_STOP                = L"String std32 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_BASE_TEST_START                = L"String base test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_BASE_TEST_STOP                 = L"String base test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_WSTRING_TEST_START             = L"String wstring test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_WSTRING_TEST_STOP              = L"String wstring test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_CUSTOM_TEST_START              = L"String custom test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_CUSTOM_TEST_STOP               = L"String custom test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_TOOLS_TEST_START               = L"String tools test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_TOOLS_TEST_STOP                = L"String tools test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STRING_UNICODE_TEST_START             = L"String unicode test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STRING_UNICODE_TEST_STOP              = L"String unicode test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_STATE_TEST_START                      = L"Lib state machine test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_STATE_TEST_STOP                       = L"Lib state machine test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_DATABAE_SQLITE3_TEST_START            = L"Lib database model sqlite3 test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_DATABASE_SQLITE3_TEST_STOP            = L"Lib database model sqlite3 test is stopped . ";

static T100WSTRING          T100TEST_HINT_LIB_VESSEL_TEST_START                     = L"Lib vessel test is starting ... ";
static T100WSTRING          T100TEST_HINT_LIB_VESSEL_TEST_STOP                      = L"Lib vessel test is stopped . ";


class T100LibTestHint : public T100Hint
{
    public:
        T100LibTestHint();
        virtual ~T100LibTestHint();

    protected:

    private:
};

#endif // T100LIBTESTHINT_H
