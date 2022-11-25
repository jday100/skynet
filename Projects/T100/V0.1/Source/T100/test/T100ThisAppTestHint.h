#ifndef T100THISAPPTESTHINT_H
#define T100THISAPPTESTHINT_H

#include "T100Hint.h"

namespace T100{

static T100WSTRING          T100TEST_HINT_FULL_TEST_START                                       = L"Full test is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_TEST_STOP                                        = L"Full test is stopped . ";

static T100WSTRING          T100TEST_HINT_FULL_TEST_FONT_INIT_START                             = L"Full test font init is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_TEST_FONT_INIT_STOP                              = L"Full test font init is stopped . ";

static T100WSTRING          T100TEST_HINT_FULL_TEST_VDISK_INIT_START                            = L"Full test vdisk init is starting ... ";
static T100WSTRING          T100TEST_HINT_FULL_TEST_VDISK_INIT_STOP                             = L"Full test vdisk init is stopped . ";



class T100ThisAppTestHint : public T100Library::T100Hint
{
    public:
        T100ThisAppTestHint();
        virtual ~T100ThisAppTestHint();

    protected:

    private:
};

}

#endif // T100THISAPPTESTHINT_H
