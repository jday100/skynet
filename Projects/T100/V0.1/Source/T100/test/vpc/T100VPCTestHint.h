#ifndef T100VPCTESTHINT_H
#define T100VPCTESTHINT_H

#include "T100Hint.h"

namespace T100VPC{

static T100WSTRING          T100TEST_HINT_VPC_QU32_TEST_START                                   = L"VPC qu32 test is starting ... ";
static T100WSTRING          T100TEST_HINT_VPC_QU32_TEST_STOP                                    = L"VPC qu32 test is stopped . ";

static T100WSTRING          T100TEST_HINT_VPC_BASIC_TEST_START                                  = L"VPC basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_VPC_BASIC_TEST_STOP                                   = L"VPC basic test is stopped . ";



class T100VPCTestHint : public T100Library::T100Hint
{
    public:
        T100VPCTestHint();
        virtual ~T100VPCTestHint();

    protected:

    private:
};

}

#endif // T100VPCTESTHINT_H
