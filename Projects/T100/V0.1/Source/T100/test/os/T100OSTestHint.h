#ifndef T100OSTESTHINT_H
#define T100OSTESTHINT_H

#include "T100Hint.h"

namespace T100OS{

static T100WSTRING          T100TEST_HINT_OS_TEST_FONT_INIT_START                               = L"OS test font init is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_TEST_FONT_INIT_STOP                                = L"OS test font init is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_LIB_TEST_START                                     = L"OS lib test is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_LIB_TEST_STOP                                      = L"OS lib test is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_LIB_TEST_STRING_SPLIT_START                        = L"OS lib test string split is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_LIB_TEST_STRING_SPLIT_STOP                         = L"OS lib test string split is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_LIB_TEST_RUN_START                                 = L"OS lib test run is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_LIB_TEST_RUN_STOP                                  = L"OS lib test run is stopped . ";


static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_ASSEMBLY_START                            = L"OS rom test assembly is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_ASSEMBLY_STOP                             = L"OS rom test assembly is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_BOOT_START                                = L"OS rom test boot is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_BOOT_STOP                                 = L"OS rom test boot is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_VDISK_START                               = L"OS rom test vdisk is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_VDISK_STOP                                = L"OS rom test vdisk is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_RUN_START                                 = L"OS rom test run is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_ROM_TEST_RUN_STOP                                  = L"OS rom test run is stopped . ";


static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_ASSEMBLY_START                           = L"OS boot test assembly is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_ASSEMBLY_STOP                            = L"OS boot test assembly is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_INIT_START                               = L"OS boot test init is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_INIT_STOP                                = L"OS boot test init is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_VDISK_START                              = L"OS boot test vdisk is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_VDISK_STOP                               = L"OS boot test vdisk is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_RUN_START                                = L"OS boot test run is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_BOOT_TEST_RUN_STOP                                 = L"OS boot test run is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_ASSEMBLY_START                           = L"OS init test assembly is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_ASSEMBLY_STOP                            = L"OS init test assembly is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_KERNEL_START                             = L"OS init test kernel is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_KERNEL_STOP                              = L"OS init test kernel is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_VDISK_START                              = L"OS init test vdisk is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_VDISK_STOP                               = L"OS init test vdisk is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_RUN_START                                = L"OS init test run is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_INIT_TEST_RUN_STOP                                 = L"OS init test run is stopped . ";


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
