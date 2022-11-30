#ifndef T100FULLTESTHINT_H
#define T100FULLTESTHINT_H

#include "T100Hint.h"

namespace T100{

static T100WSTRING          T100TEST_HINT_FULL_TEST_START                                       = L"Full test is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_TEST_STOP                                        = L"Full test is stopped . ";

static T100WSTRING          T100TEST_HINT_FULL_TEST_FONT_INIT_START                             = L"Full test font init is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_TEST_FONT_INIT_STOP                              = L"Full test font init is stopped . ";

static T100WSTRING          T100TEST_HINT_FULL_TEST_VDISK_INIT_START                            = L"Full test vdisk init is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_TEST_VDISK_INIT_STOP                             = L"Full test vdisk init is stopped . ";


static T100WSTRING          T100TEST_HINT_FULL_REAL_BASIC_TEST_START                            = L"Full real basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_REAL_BASIC_TEST_STOP                             = L"Full real basic test is stopped . ";

static T100WSTRING          T100TEST_HINT_FULL_REAL_STACK_TEST_START                            = L"Full real stack test is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_REAL_STACK_TEST_STOP                             = L"Full real stack test is stopped . ";


static T100WSTRING          T100TEST_HINT_FULL_VIRTUAL_BASIC_TEST_START                         = L"Full virtual basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_VIRTUAL_BASIC_TEST_STOP                          = L"Full virtual basic test is stopped . ";



class T100FullTestHint : public T100Library::T100Hint
{
    public:
        T100FullTestHint();
        virtual ~T100FullTestHint();

    protected:

    private:
};

}

#endif // T100FULLTESTHINT_H
