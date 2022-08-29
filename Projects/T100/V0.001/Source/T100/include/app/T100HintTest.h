#ifndef T100HINTTEST_H
#define T100HINTTEST_H

#include "T100Hint.h"

static std::string      T100TEST_HINT_TEST_SUCCESS                          =   "test success!";
static std::string      T100TEST_HINT_TEST_FAILURE                          =   "test failure!";

static std::string      T100TEST_APP_TEST_START                             =   "Test App is starting...";
static std::string      T100TEST_APP_TEST_STOP                              =   "Test App is stopped.";

static std::string      T100TEST_APP_TEST_SUCCESS                           =   "TEST SUCCESS!";
static std::string      T100TEST_APP_TEST_FAILURE                           =   "TEST FAILURE!";

static std::string      T100TEST_LIB_FILE_TEST_START                        =   "Test Lib's File module is starting...";
static std::string      T100TEST_LIB_FILE_TEST_STOP                         =   "Test Lib's File module is stopped.";

static std::string      T100TEST_SYSTEM_TEST_START                          =   "Test System is starting...";
static std::string      T100TEST_SYSTEM_TEST_STOP                           =   "Test System is stopped.";
static std::string      T100TEST_SYSTEM_FONT_TEST_START                     =   "Test System's Font module is starting...";
static std::string      T100TEST_SYSTEM_FONT_TEST_STOP                      =   "Test System's Font module is stopped.";
static std::string      T100TEST_SYSTEM_FONT_FILE_TEST_START                =   "Test System's Font File module is starting...";
static std::string      T100TEST_SYSTEM_FONT_FILE_TEST_STOP                 =   "Test System's Font File module is stopped.";
static std::string      T100TEST_SYSTEM_VDISK_TEST_START                    =   "Test System's VDisk module is starting...";
static std::string      T100TEST_SYSTEM_VDISK_TEST_STOP                     =   "Test System's VDisk module is stopped.";
static std::string      T100TEST_SYSTEM_VDISK_FILE_TEST_START               =   "Test System's VDisk File module is starting...";
static std::string      T100TEST_SYSTEM_VDISK_FILE_TEST_STOP                =   "Test System's VDisk File module is stopped.";
static std::string      T100TEST_SYSTEM_VFS_TEST_START                      =   "Test System's VFS module is starting...";
static std::string      T100TEST_SYSTEM_VFS_TEST_STOP                       =   "Test System's VFS module is stopped.";
static std::string      T100TEST_SYSTEM_VFS_ITEM_TEST_START                 =   "Test System's VFS Item module is starting...";
static std::string      T100TEST_SYSTEM_VFS_ITEM_TEST_STOP                  =   "Test System's VFS Item module is stopped.";
static std::string      T100TEST_SYSTEM_VFS_TABLE_TEST_START                =   "Test System's VFS Table module is starting...";
static std::string      T100TEST_SYSTEM_VFS_TABLE_TEST_STOP                 =   "Test System's VFS Table module is stopped.";
static std::string      T100TEST_SYSTEM_VFS_PATH_TEST_START                 =   "Test System's VFS Path module is starting...";
static std::string      T100TEST_SYSTEM_VFS_PATH_TEST_STOP                  =   "Test System's VFS Path module is stopped.";
static std::string      T100TEST_SYSTEM_VFS_FILE_TEST_START                 =   "Test System's VFS File module is starting...";
static std::string      T100TEST_SYSTEM_VFS_FILE_TEST_STOP                  =   "Test System's VFS File module is stopped.";

static std::string      T100TEST_OS_BOOT_TEST_START                         =   "Test OS's BOOT module is starting...";
static std::string      T100TEST_OS_BOOT_TEST_STOP                          =   "Test OS's BOOT module is stopped.";
static std::string      T100TEST_OS_BOOT_TEST_INIT_START                    =   "Test OS's BOOT module init is starting...";
static std::string      T100TEST_OS_BOOT_TEST_INIT_STOP                     =   "Test OS's BOOT module init is stopped.";
static std::string      T100TEST_OS_KERNEL_TEST_START                       =   "Test OS's KERNEL module is starting...";
static std::string      T100TEST_OS_KERNEL_TEST_STOP                        =   "Test OS's KERNEL module is stopped.";
static std::string      T100TEST_OS_KERNEL_TEST_INIT_START                  =   "Test OS's KERNEL module init is starting...";
static std::string      T100TEST_OS_KERNEL_TEST_INIT_STOP                   =   "Test OS's KERNEL module init is stopped.";


class T100HintTest : public T100Hint
{
    public:
        T100HintTest();
        virtual ~T100HintTest();

        static T100STDSTRING        test_result(T100STDSTRING, T100STDSTRING);

    protected:

    private:
};

#endif // T100HINTTEST_H
