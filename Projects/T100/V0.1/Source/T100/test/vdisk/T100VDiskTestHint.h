#ifndef T100VDISKTESTHINT_H
#define T100VDISKTESTHINT_H

#include "T100Hint.h"

namespace T100VDisk{

static T100WSTRING          T100TEST_HINT_VDISK_BASIC_TEST_START                                = L"VDisk basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_VDISK_BASIC_TEST_STOP                                 = L"VDisk basic test is stopped . ";

static T100WSTRING          T100TEST_HINT_VDISK_CONSOLE_TEST_START                              = L"VDisk console test is starting ... ";
static T100WSTRING          T100TEST_HINT_VDISK_CONSOLE_TEST_STOP                               = L"VDisk console test is stopped . ";



class T100VDiskTestHint : public T100Library::T100Hint
{
    public:
        T100VDiskTestHint();
        virtual ~T100VDiskTestHint();

    protected:

    private:
};

}

#endif // T100VDISKTESTHINT_H
