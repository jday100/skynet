#ifndef T100DEPLOYTESTHINT_H
#define T100DEPLOYTESTHINT_H

#include "T100Hint.h"

namespace T100{

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_START                                       = L"OS deploy is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_STOP                                        = L"OS deploy is stopped . ";


static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_FONT_START                                = L"OS deploy b font is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_FONT_STOP                                 = L"OS deploy b font is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_ROM_START                                 = L"OS deploy b rom is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_ROM_STOP                                  = L"OS deploy b rom is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_BOOT_START                                = L"OS deploy b boot is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_BOOT_STOP                                 = L"OS deploy b boot is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_INIT_START                                = L"OS deploy b init is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_INIT_STOP                                 = L"OS deploy b init is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_KERNEL_START                              = L"OS deploy b kernel is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_KERNEL_STOP                               = L"OS deploy b kernel is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_VDISK_START                               = L"OS deploy b vdisk is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_VDISK_STOP                                = L"OS deploy b vdisk is stopped . ";

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_RUN_START                                 = L"OS deploy b run is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_B_RUN_STOP                                  = L"OS deploy b run is stopped . ";


class T100DeployTestHint : public T100Library::T100Hint
{
    public:
        T100DeployTestHint();
        virtual ~T100DeployTestHint();

    protected:

    private:
};

}

#endif // T100DEPLOYTESTHINT_H
