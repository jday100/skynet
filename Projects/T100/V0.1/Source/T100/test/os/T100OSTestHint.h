#ifndef T100OSTESTHINT_H
#define T100OSTESTHINT_H

#include "T100Hint.h"

namespace T100OS{

static T100WSTRING          T100TEST_HINT_OS_TEST_FONT_INIT_START                               = L"OS test font init is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_TEST_FONT_INIT_STOP                                = L"OS test font init is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_TEST_VDISK_INIT_START                              = L"OS test vdisk init is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_TEST_VDISK_INIT_STOP                               = L"OS test vdisk init is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_BASIC_TEST_START                                   = L"OS basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_BASIC_TEST_STOP                                    = L"OS basic test is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_START                                     = L"OS rom test is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_STOP                                      = L"OS rom test is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_VDISK_INIT_START                          = L"OS rom test vdisk init is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_VDISK_INIT_STOP                           = L"OS rom test vdisk init is stopped . ";


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
