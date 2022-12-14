#ifndef T100DEPLOYTESTHINT_H
#define T100DEPLOYTESTHINT_H

#include "T100Hint.h"

namespace T100{

static T100WSTRING          T100TEST_HINT_OS_DEPLOY_START                                       = L"OS deploy is starting ... ";
static T100WSTRING          T100TEST_HINT_OS_DEPLOY_STOP                                        = L"OS deploy is stopped . ";


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
